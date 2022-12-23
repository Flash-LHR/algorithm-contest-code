#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define endl '\n'
#define mkp make_pair
#define ep emplace_back
#define F first
#define S second
#define seg(x) x.begin(), x.end()
const int Ma = 20, mod = 78294349;
using ll = long long;
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

//#define int ll

cc_hash_table<size_t, pair<ll, ll>> dp[Ma];
string p;
int res[Ma];
//hash<string> str_hash;

size_t gen() {
    size_t s{0};// string ss;
    for (int i = 0; i < 10; i++)
        s *= 15, s += res[i];//, ss += to_string(res[i]) + '|';
    return s; //str_hash(ss);
}

//#define debug(x) cerr << #x << ":\n" << x << endl
#define debug(x) 

string pp;

pair<ll, ll> dfs(int u, bool zero, bool lim) {
    if (u == -1) return mkp(0ll, 1ll);
    size_t now = gen();
    if (!lim and !zero and dp[u].find(now) != dp[u].end())
        return dp[u][now];
    int p = lim ? ::p[u] - '0' : 9;
    pair<ll, ll> ans;
    for (int i = 0; i <= p; i++) {
        int t{0};
        for (int j = 0; j < i; j++) t += res[j];
        if (!(zero and i == 0)) ++res[i];
        pp += i + '0';
        auto c = dfs(u - 1, zero && i == 0, lim && i == p);
        ans.F += c.F + c.S * t;
        ans.S += c.S;
        pp.pop_back();
        if (!(zero and i == 0)) --res[i];
    }
    debug(u << ' ' << ord << ' ' << boolalpha << lim << ' ' << zero << ' ' << ans << ' ' << pp);
    if (!lim and !zero) dp[u][now] = ans;
    return ans;
}

ll cal(ll x) {
    p = to_string(x);
    debug(p);
    reverse(seg(p));
    return dfs(p.size() - 1, 1, 1).F;
}

void solve() {
    ll x, y; cin >> x >> y;
    cout << cal(y) - cal(x - 1) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    rep (qq, t) {
        cout << "Case " << qq + 1 << ": ";
        solve();
    }
}
