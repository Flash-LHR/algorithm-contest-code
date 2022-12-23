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

constexpr int Ma = 550;

string s[Ma];
vector<int> g[Ma];

int mat[Ma];
bool mz[Ma];

bool find(int u) {
    rap (i, g[u]) {
        if (mz[i]) continue;
        mz[i] = true;
        if (!~mat[i] or find(mat[i]))
            return mat[i] = u, mat[u] = i, true;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    rep (i, n) cin >> s[i];
    int len = s[0].size();
    rep (i, n) {
        rep (j, n) if (i != j) {
            int cnt{0};
            rep (k, len) cnt += s[i][k] != s[j][k];
            if (cnt == 2) g[i].eb(j);
        }
    }
    memset(mat, -1, sizeof mat);
    int ans = 0;
    for (int i= 0; i < n; memset(mz, 0, sizeof mz), i++)
        if (!~mat[i]) ans += find(i);
    cout << n - ans << endl;
}
