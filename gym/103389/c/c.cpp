#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

using ll = long long;
#define endl '\n'
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define ep emplace_back
constexpr int Ma = 38, inf = 0x3f3f3f3f;
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}

ll w[Ma];
int c[Ma];
ll s[Ma];
bool vis[Ma];
int in[Ma], go[Ma], cur;
int pre[Ma], ppre[Ma], dfn[Ma];
bool gg[Ma][Ma];
vector<int> g[Ma];
vector<int> h[Ma];
int n; ll val[Ma];

void dfs(int u, int idx) {
    if (u == n) {
        memset(val, 0, sizeof val);
        memcpy(ppre, pre, sizeof pre);
        sort(pre, pre + idx, [&] (int a, int b) {
                    return dfn[a] < dfn[b];
                });
        for (int i = 0; i < idx; i++) {
            cmax(val[pre[i]], w[c[pre[i]]]);
            for (int j = i + 1; j < idx; j++) if (gg[pre[i]][pre[j]]) {
                cmax(val[pre[j]], val[pre[i]] + w[c[pre[j]]]);
            }
        }
        for (int i = 0; i < idx; i++)
            cmax(s[pre[i]], val[pre[i]]);
        memcpy(pre, ppre, sizeof ppre);
        return ;
    }
    if (h[u].empty()) dfs(u + 1, idx);
    else 
    rap (i, h[u]) {
        pre[idx] = i;
        dfs(u + 1, idx + 1);
    }
}

void topo(int u) {
    dfn[u] = cur++;
    rap (i, g[u]) if (--in[i] == 0) topo(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    cout << fixed << setprecision(12);
    int m; cin >> n >> m;
    rep (i, n) cin >> c[i], --c[i], h[c[i]].ep(i);
    rep (i, n) cin >> w[i];
    rep (i, m) {
        int u, v; cin >> u >> v; --u, --v;
        gg[u][v] = true; in[v]++;
        g[u].ep(v);
    }
    topo(0);
    rep (k, n) rep (i, n) rep (j, n)
        gg[i][j] |= gg[i][k] & gg[k][j];
    dfs(0, 0);
    rep (i, n) cout << s[i] << endl;

    return 0;
}
