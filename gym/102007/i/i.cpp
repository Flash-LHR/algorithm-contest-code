#include <bits/stdc++.h>
using namespace std;

constexpr int Ma = 1e5 + 100, inf = 0x3f3f3f3f;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define F first
#define S second
#define endl '\n'
#define sz(x) (int)x.size()
using ll = long long;
using db = double;
#define int ll
constexpr db eps = 1e-9;
#define ep emplace_back
template<typename T>
bool cmin(T &a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T &a, const T& b) {return a >= b || (a = b, false);}
using pa=pair<int, ll>;

int p[Ma], ss[Ma];
vector<pa> g[Ma];
ll dis[20][Ma];
bool vis[Ma];

void dij(int id, int u) {
    memset(dis[id], inf, sizeof dis[id]);
    memset(vis, 0, sizeof vis);
    dis[id][u] = 0;
    ll* d = dis[id];
    priority_queue<pair<ll, int>> q;
    q.emplace(0, u);
    while (!q.empty()) {
        auto t = q.top(); q.pop();
        if (vis[t.S]) continue;
        vis[t.S] = true;
        rap (i, g[t.S]) if (!vis[i.F] and d[t.S] + i.S < d[i.F]) {
            d[i.F] = d[t.S] + i.S;
            q.emplace(-d[i.F], i.F);
        }
    }
}

#define qxx(i, x) for (int i = head[x]; ~i; i = node[i].nex)

struct Dinic {
    struct Node {
        int u, v, nex;
        ll w;
    } node[Ma * 20];
    int head[Ma], cnt, n, cur[Ma], d[Ma];
    void clear(int n) {
        cnt = 0; this->n = n;
        memset(head, -1, sizeof(int) * n);
    }
    void add_edge(int u, int v, ll w) {
        node[cnt].u = u, node[cnt].v = v, node[cnt].w = w;
        node[cnt].nex = head[u], head[u] = cnt++;
    }
    void add(int u, int v, ll w) {
        add_edge(u, v, w);
        add_edge(v, u, 0);
    }
    bool bfs(const int& s, const int& t) {
        memset(d, 0, sizeof(int) * n);
        queue<int> q;
        q.emplace(s);
        d[s] = 1;
        while (!q.empty()) {
            int tp = q.front();
            q.pop();
            qxx(i, tp) if (node[i].w and !d[node[i].v]) {
                d[node[i].v] = d[tp] + 1;
                q.emplace(node[i].v);
            }
        }
        return d[t];
    }
    ll dfs(int u, const int &t, ll mn) {
        if (u == t or mn == 0) return mn;
        ll flow = 0;
        for (int &i = cur[u]; ~i; i = node[i].nex)
            if (d[node[i].v] == d[u] + 1 and node[i].w) {
                ll af = dfs(node[i].v, t, min(mn, node[i].w));
                if (af > 0) {
                    flow += af;
                    mn -= af;
                    node[i].w -= af;
                    node[i ^ 1].w += af;
                    if (mn <= 0) break;
                }
            }
        return flow;
    }
    ll maxflow(int s, int t) {
        ll ans = 0;
        while (bfs(s, t)) {
            memcpy(cur, head, sizeof(int) * n);
            ans += dfs(s, t, numeric_limits<ll>::max());
        }
        return ans;
    }
} dinic;

constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, s; cin >> n >> m >> s;
    ll tot{0};
    rep (i, n) cin >> p[i], tot += p[i];
    rep (i, m) {
        int u, v, w; cin >> u >> v >> w;
        g[u].ep(v, w);
        g[v].ep(u, w);
    }
    rep (i, s) {
        int id; cin >> id; cin >> ss[i];
        dij(i, id);
    }
    ll l = -1, r = linf;
    int S = 0, T = n + s + 1;
    auto ck = [&] (ll lim) {
        dinic.clear(T + 1);
        rep (i, s) {
            dinic.add(S, i + 1, ss[i]);
            rep (j, n) if (dis[i][j + 1] <= lim) dinic.add(i + 1, s + j + 1, p[j]);
        }
        rep (j, n) dinic.add(s + 1 + j, T, p[j]);
        return dinic.maxflow(S, T) == tot;
    };
//    cerr << "over" << endl;
    while (r - l > 1) {
        ll mid(l + (r - l) / 2);
        if (ck(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}

