//
// Created by lhr on 21-6-3.
//

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
const int Ma = 1e5 + 100, inf = 0x3f3f3f3f;
#define rep(i, x) for (int i = 0; i < (x); i++)
#define endl '\n'
#define ep emplace_back
#define F first
#define S second
#define seg(x) (x).begin(), (x).end()

vector<int> g[Ma];
int cur[Ma], tot, now, n;

void dfs(int u) {
    if (now > n) return ;
    do {
        while (cur[u] < g[u].size() and g[u][cur[u]] < now) ++cur[u];
        if (cur[u] >= g[u].size() and u != 1) return;
        if ((u == 1 and cur[u] >= g[u].size()) or g[u][cur[u]] != now) ++tot, --cur[u];
        dfs(now++), ++cur[u];
    } while (now <= n);
}

void solve() {
    tot = 0;
    int m; cin >> n >> m;
    rep (i, n) g[i + 1].clear(), cur[i + 1] = 0;
    rep (i, m) {
        int u, v; cin >> u >> v;
        g[u].ep(v); g[v].ep(u);
    }
    rep (i, n) sort(seg(g[i + 1])), g[i + 1].resize(unique(seg(g[i + 1])) - g[i + 1].begin());
    now = 2;
    dfs(1);
    cout << tot << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();

    return 0;
}

