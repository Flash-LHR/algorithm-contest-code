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
#define mkt make_tuple
#define F first
#define S second
#define state(x) (1<<(x))
constexpr int Ma = 1e6, inf = 0x3f3f3f3f, ma = 2e9;

template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    int pos = sz(s) - 1;
    while (pos >= 0 and s[pos] == '1') --pos;
    if (pos == -1) cout << "0" << endl;
    else {
        string ans{"1"};
        for (int i = pos - 1; i >= 0; i--) if (s[i] == '1')
            ans += '1';
        else ans += '0';
        cout << ans << endl;
    }
}

