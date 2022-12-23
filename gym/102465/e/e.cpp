#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define S second
#define F first
#define endl '\n'
using ll=long long;
using db=double;
template<typename T>
T cmax(T& a, const T& b) {return a >= b or (a = b, false);}
template<typename T>
T cmin(T& a, const T& b) {return a <= b or (a = b, false);}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

constexpr db eps = 1e-9;
int sign(db x) {return x < -eps ? -1 : x > eps;}
constexpr int Ma = 1e5 + 100;

pair<string, int> res[Ma];

db nm(db x) {
    return max(0.0, min(x, 100.0));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(2);
    int n; cin >> n;
    int tot{0};
    rep (i, n) {
        cin >> res[i].F >> res[i].S;
        tot += res[i].S;
    }
    db r = 100 - tot;
    if (sign(r + 0.5 * n) == -1 or sign(r - 0.49 * n) == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    rep (i, n) {
        cout << res[i].F;
        cout << ' ' << nm(res[i].S + max(-0.5, r - 0.49 * (n - 1)));
        cout << ' ' << nm(res[i].S + min(0.49, r + 0.5 * (n - 1)));
        cout << endl;
    }
}
