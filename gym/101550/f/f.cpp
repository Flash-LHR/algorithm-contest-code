#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int n, m; cin >> n >> m;
    db now = (db)m / (n + 1), ans = now;
    fep (i, 2, n * 2 + 1) {
        now *= (db)i / (i - 1) * (n - m + i) / (n + i);
        cmax(ans, now);
    }
    cout << ans << endl;
}

