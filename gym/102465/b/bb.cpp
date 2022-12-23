#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define S second
#define F first
#define endl '\n'
using ll=long long;
template<typename T>
T cmax(T& a, const T& b) {return a >= b or (a = b, false);}
template<typename T>
T cmin(T& a, const T& b) {return a <= b or (a = b, false);}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const int Ma = 1e5 + 100;

int l[Ma], r[Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n = 100000; cin >> n;
    rep (i, n) {
        cin >> l[i] >> r[i];
    }
    int ans{0};
    rep (i, n) fep (j, i, n) rep (k, n) fep (l, k, n) {
        bool can = true;
        fep (ii, i, j + 1)
            can &= (::l[ii] <= k and r[ii] >= l);
        if (can and l - k == j - i) {
            //cerr << i << ' ' << j << ' ' << k << ' ' << l << endl;
            cmax(ans, l - k + 1);
        }
    }
    cout << ans << endl;
}
