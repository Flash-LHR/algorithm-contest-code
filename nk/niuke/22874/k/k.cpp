#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

#define endl '\n'
#define sz(x) (int)x.size()
#define lowbit(x) ((x)&(-(x)))
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define ep emplace_back
#define mkp make_pair
#define mkt make_tuple
#define F first
#define S second
using ll=long long;
constexpr int Ma = 550, mod = 1e9 + 7, inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}

int a[Ma];//, aa[Ma], bb[Ma], al, bl;
ll f[Ma][Ma];
ll g[Ma][Ma];
ll gg[Ma];
ll val[Ma][Ma];
ll vv[Ma];
bool vis[Ma][Ma];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    memset(f, inf, sizeof f);
    memset(g, inf, sizeof g);
    memset(val, inf, sizeof val);
    rep (i, n) cin >> a[i], f[i][i] = 0;
    rep (i, m) {
        int u, v, w; cin >> u >> v >> w; --u, --v;
        g[u][v] = g[v][u] = w;
        val[u][v] = val[v][u] = max(a[u], a[v]);
        cmin(f[u][v], val[u][v] * g[u][v]);
        f[v][u] = f[u][v];
    }
    for (int k = 0; k < n; k++) {
        memcpy(gg, g[k], sizeof gg);
        memcpy(vv, val[k], sizeof vv);
        for (int i = 0; i < n; i++) if (i != k)
            for (int j = 0; j < n; j++) if (i != j and j != k) {
                if (gg[i] != linf and gg[j] != linf) {
                    if (!cmin(f[i][j],
                         max(vv[i], vv[j]) * max(gg[i], gg[j]))) {
                        cmin(g[i][j], max(gg[i], gg[j]));
                        cmin(val[i][j], max(vv[i], vv[j]));
                    }
                }
            }
    }
    rep (i, n) {
        rep (j, n) {
            if (f[i][j] == linf) f[i][j] = -1;
            cout << f[i][j]
                 << " \n"[j == n -1];
        }
    }
}

