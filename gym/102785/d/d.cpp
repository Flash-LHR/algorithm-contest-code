#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
constexpr int Ma = 1010, inf = 0x3f3f3f3f, ma = 2e9;

template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

int prim[]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
ll m{inf * 2};

void dfs(int u, int k, int pv, ll res) {
    if (u == 12) {
        if (k == 1) cmin(m, res);
        return ;
    }
    ll now = 1;
    rep (i, pv + 1) if (res * now < ma) {
        if (k % (i + 1) == 0)
            dfs(u + 1, k / (i + 1), i,
                res * now);
        now *= prim[u];
    } else break;
}

ll cal(ll x) {
    ll now{1};
    for (ll i = 2; i * i <= x; i++) if (x % i == 0) {
        int cnt{0};
        while (x % i == 0) ++cnt, x /= i;
        now *= cnt + 1;
    }
    if (x != 1) now *= 2;
    return now;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int k; cin >> k;
    dfs(0, k, 30, 1);
    if (m == 2 * inf) m = -1;
    else {
        cerr << inf * 2 << endl;
        cerr << m << endl;
        assert(cal(m) == k);
    }
    cout << m << endl;
}

