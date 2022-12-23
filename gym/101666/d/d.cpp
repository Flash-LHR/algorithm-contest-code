#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = double;
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
#define mkp make_pair
#define F first
#define S second
#define seg(x) x.begin(), x.end()
#define ep emplace_back
constexpr db pi = acos(-1.0), eps = 1e-9;
constexpr int Ma = 1e5 + 100, inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

vector<pair<int, int>> g[Ma];
ll dis[Ma];
int fa[Ma];
bool vis[Ma];
set<int> ck[Ma];

void dij(int s) {
    memset(dis, inf, sizeof dis);
    dis[s] = 0;
    __gnu_pbds::priority_queue<pair<ll, int>> q;
    q.push(mkp(0, s));
    while (!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        //cerr << u << ' ' << g[u].size()<< endl;
        //cerr << g[u][0].F << ' ' << vis[g[u][0].F] << ' ' << dis[g[u][0].F] << endl;
        rap (i, g[u]) if (!vis[i.F] and dis[i.F] > dis[u] + i.S) {
            //cerr << "in " << i.F << endl;
            dis[i.F] = dis[u] + i.S;
            fa[i.F] = u;
            q.push(mkp(-dis[i.F], i.F));
        }
    }
}

struct Node {
    int who, fa;
} nd[Ma * 10];

int main() {
    int n, m; scanf("%d%d", &n, &m);
    rep (i, m) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        g[u].ep(v, w); g[v].ep(u, w);
    }
    dij(1);
    memset(vis, false, sizeof vis);
    //rep (i, n) cerr << fa[i] << ' ';
    //cerr << endl;
    queue<int> q; nd[0].who = 0, nd[0].fa = -1;
    int f = -1, cur = 1;
    q.emplace(0);
    while (!q.empty()) {
        int t = q.front(); q.pop();
        if (vis[nd[t].who]) continue;
        if (nd[t].who == 1) {f = t; break;}
        vis[nd[t].who] = true;
        //cerr << nd[t].who << endl;
        rap (i, g[nd[t].who]) {
            //cerr << i.F << ' ' << fa[nd[t].who] << endl;
            if (!vis[i.F] and i.F != fa[nd[t].who]) {
                nd[cur].who = i.F; nd[cur].fa = t;
                //cerr << i.F << endl;
                q.emplace(cur++);
            }
        }
    }
    if (f == -1) puts("impossible");
    else {
        vector<int> res;
        while (f != -1) {
            res.ep(nd[f].who);
            f = nd[f].fa;
        }
        reverse(seg(res));
        printf("%lu ", res.size());
        rep (i, sz(res)) printf("%d%c", res[i], " \n"[i == sz(res) - 1]);
    }
}
