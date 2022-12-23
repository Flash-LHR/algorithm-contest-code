#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define F first
#define S second
#define mkt make_tuple
#define mkp make_pair
#define eb emplace_back
#define ep emplace
#define sz(x) (int)x.size()
#define state(x) (1<<(x))
#define endl '\n'
constexpr int Ma = 60, inf = 0x3f3f3f3f;
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

ll nm(ll x, ll p) {if (x < p) return x; else return x % p + p;}

ll fast(ll a, ll b, ll p) {
    ll s = 1;
    for (a = nm(a, p); b; b >>= 1, a = nm(a * a, p))
        if (b & 1) s = nm(s * a, p);
    return s;
}

ll phi(ll x) {
    ll tot{x};
    for (ll i = 2; i * i <= x; i++) if (x % i == 0) {
        tot = tot / i * (i - 1);
        while (x % i == 0) x /= i;
    }
    if (x != 1) tot = tot / x * (x - 1);
    return tot;
}

ll cal (ll a, ll b) {
    if (a == 1 or b == 1) return nm(a, b);
    return fast(a, cal(a - 1, phi(b)), b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, m; cin >> n >> m;
    cout << cal(n, m) % m << endl;
}

