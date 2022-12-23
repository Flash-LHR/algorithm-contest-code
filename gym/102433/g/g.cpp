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
#define sz(x) (int)x.size()
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

constexpr int Ma = 100;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    char hv[]{'h', 'v'};
    rep (i, n) {
        char c; int t, m, a; cin >> c >> t >> m >> a;
        int id = find(hv, hv + 2, c) - hv;
        ;
    }
}
