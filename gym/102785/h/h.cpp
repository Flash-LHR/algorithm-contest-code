#include <bits/stdc++.h>
using namespace std;

#define seg(x) x.begin(), x.end()
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
#define endl '\n'
#define ep emplace
#define eb emplace_back
#define F first
#define S second
constexpr int Ma = 50;

int res[Ma], cnt[Ma];

bool dfs(int u, int lim) {
    if (u == lim) {
        memset(cnt, 0, sizeof cnt);
        rep (i, lim) ++cnt[res[i]];
        if (memcmp(res, cnt, sizeof res) == 0) {
            rep (i, lim) cerr << res[i] << ' ';
            cerr << endl;
            return true;
        }
        return false;
    }
    bool can{false};
    rep (i, lim) res[u] = i, can |= dfs(u + 1, lim);
    return can;
}

void solve(int n) {
    memset(res, 0, sizeof res);
    cerr << boolalpha << dfs(0, n) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    while (cin >> n) solve(n);
}

