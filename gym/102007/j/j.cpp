#include <bits/stdc++.h>
using namespace std;

constexpr int Ma = 1e6 + 100, inf = 0x3f3f3f3f;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
using ll = long long;
using db = double;
constexpr db eps = 1e-9;
#define ep emplace_back
template<typename T>
bool cmin(T &a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T &a, const T& b) {return a >= b || (a = b, false);}

db heron(db a, db b, db c) {
    db s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(8);
    int a[4];
    rep (i, 4) cin >> a[i];
    sort(a, a + 4);
    db ans = 0.0;
    do {
        db l = eps, r = min(a[0] + a[1], a[2] + a[3]) - eps;
        auto cal = [&] (db x) {
            db val = heron(a[0], a[1], x) + heron(x, a[2], a[3]);
            return isnan(val) ? 0.0 : val;
        };
        //cerr << l << ' ' << r << ' ' << cal(l) << ' ' << cal(r) << endl;
        while (r - l > eps) {
            db lm = l + (r - l) / 3.0, rm = (l + r) / 2.0;
            //assert(lm < rm);
            //cerr << "val: " << cal(lm) << ' ' << cal(rm) << endl;
            if (cal(lm) <= cal(rm)) l = lm;
            else r = rm;
            //cerr << l << ' ' << r << endl;
        }
        //cerr << r << ' ' << cal(r) << endl;
        //cerr << boolalpha << (ans < cal(r)) << endl;
        cmax(ans, cal(r));
        //cerr << ans << ' ' << cal(r) << endl;
    } while (next_permutation(a, a + 4));
    cout << ans << endl;
}

