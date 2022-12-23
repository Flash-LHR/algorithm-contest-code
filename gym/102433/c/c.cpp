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
#define eb emplace_back
#define mkp make_pair
#define mkt make_tuple

constexpr int Ma = 2e5 + 100;

vector<int> g[Ma];
bool vis[Ma];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    rep (i, m) {
        int u, v; cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    queue<pair<int, int>> q; q.ep(1, 0);
    vis[1] = true;
    while (!q.empty()) {
        auto [u, cnt] = q.front(); q.pop();
        if (u == n) {
            cout << cnt - 1 << endl;
            return 0;
        }
        rap (i, g[u]) if (!vis[i]) {
            vis[i] = true;
            q.ep(i, cnt + 1);
        }
    }
    assert(false);
}
