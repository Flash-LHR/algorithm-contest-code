#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define sz(x) (int)x.size()
#define endl '\n'
#define ep emplace_back
#define F first
#define S second
#define seg(x) x.begin(), x.end()
const int Ma = 20, mod = 78294349;
using ll = long long;
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

int res[Ma];

void solve() {
    ll x, y; cin >> x >> y;
    ll ans = 0;
    while (x <= y) {
        memset(res, 0, sizeof res);
        string s = to_string(x);
        for (int i = 0; i < sz(s); i++) {
            ++res[s[i] - '0'];
            for (int j = 0; j < s[i] - '0'; j++)
                ans += res[j];
        }
        ++x;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    rep (qq, t) {
        cout << "Case " << qq + 1 << ": ";
        solve();
    }
}
