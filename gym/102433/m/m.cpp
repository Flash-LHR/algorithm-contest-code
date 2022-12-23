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

constexpr int Ma = 1e3 + 100;

char mz[Ma][Ma];
bool vis[Ma][Ma];
int n, m;

bool outside(int r, int c) {
    return r < 0 or r >= n or c < 0 or c >= m;
}

int xz[] = {0, 0, -1, 1, 1, -1, 1, -1},
    yz[] = {-1, 1, 0, 0, 1, -1, -1, 1};

bool dfs(int r, int c) {
    if (outside(r, c)) return true;
    if (vis[r][c]) return false;
    vis[r][c] = true;
    if (mz[r][c] != '.') return false;
    bool can{false};
    rep (i, 8) {
        if (i >= 4) {
            pair<int, int> k1{r, c}, k2 = {r + xz[i], c + yz[i]};
            if (outside(k1.F, k1.S) or outside(k2.F, k2.S)) continue;
            if (k2.F < k1.F) swap(k1, k2);
            if (k1.S < k2.S and
                mz[k2.F][k1.S] == '/' and
                mz[k1.F][k2.S] == '/')
                continue;
            if (k1.S > k2.S and
                mz[k2.F][k1.S] == '\\' and
                mz[k1.F][k2.S] == '\\')
                continue;
        }
        can |= dfs(r + xz[i], c + yz[i]);
    }
    return can;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    rep (i, n) cin >> mz[i];
    int ans{0};
    rep (i, n) rep (j, m) if (!vis[i][j] and mz[i][j] == '.')
         ans += !dfs(i, j);
    //cerr << ans << endl;
    rep (i, n - 1) rep (j, m - 1)
        if (mz[i][j] == '/' and mz[i][j + 1] == '\\' and
            mz[i + 1][j] == '\\' and mz[i + 1][j + 1] == '/')
            ++ans;
    cout << ans << endl;
}
