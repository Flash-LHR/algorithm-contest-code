#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using db = double;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define ep emplace
#define F first
#define S second
#define eb emplace_back
#define mkp make_pair
#define mkt make_tuple
#define endl '\n'
#define seg(x) x.begin(), x.end()

#ifdef DEBUG
void err(istream_iterator<string>) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ';
    err(++it, args...);
}
#define debug(args...) {string _s = #args; \
    replace(seg(_s), ',', ' '); \
    cerr << "DEBUG:"; \
    istringstream it(_s); \
    err(istream_iterator<string>(it), args); \
    cerr << endl; \
}
#else
#define debug(...)
#endif

constexpr int Ma = 1e5 + 100;

vector<pair<int, int>> gr[Ma];
ll c[Ma], g[Ma], h[Ma], son[Ma], siz[Ma];
ll tot{0};

void dfs(int u, int fa, ll dis) {
    g[u] = dis; h[u] = c[u] * dis; son[u] = c[u];
    siz[u] = 1;
    rap (i, gr[u]) if (i.F != fa) {
        dfs(i.F, u, dis + i.S);
        g[u] += g[i.F]; h[u] += h[i.F];
        son[u] += son[i.F], siz[u] += siz[i.F];
    }
}

void dfs(int u, int fa) {
    for (auto& [v, w] : gr[u]) if (v != fa) {
        g[v] = g[u] - siz[v] * w + (siz[1] - siz[v]) * w;
        h[v] = h[u] - son[v] * w + (son[1] - son[v]) * w;
        dfs(v, u);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    rep (i, n)
        cin >> c[i + 1];
    rep (i, n - 1) {
        int u, v, w; cin >> u >> v >> w;
        gr[u].eb(v, w), gr[v].eb(u, w);
    }
    dfs(1, 0, 0);
    dfs(1, 0);
    fep (i, 1, n + 1) cout << g[i] * c[i] + h[i] << endl;
}
