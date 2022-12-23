#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lowbit(x) ((x)&(-(x)))
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
using ll=long long;
constexpr int Ma = 120, mod = 1e9 + 7;

struct Mint {
    ll x;
    static ll nm(ll x) {
        if (x < 0) x %= mod, x += mod;
        return x % mod;
    }
    static Mint fast(Mint x, ll b) {
        Mint s{1};
        for (; b; b >>= 1, x = x * x)
            if (b & 1) s = s * x;
        return s;
    }
    static Mint inv(Mint x) {
        return fast(x, mod - 2);
    }
    Mint (ll x=0) : x(nm(x)) {}
    Mint operator + (const Mint& b) {return x + b.x;}
    Mint operator - (const Mint& b) {return x - b.x;}
    Mint operator * (const Mint& b) {return x * b.x;}
    Mint operator / (const Mint& b) {return *this * inv(b.x);}
};

ostream& operator << (ostream& out, const Mint& x) {
    out << x.x;
    return out;
}

Mint C[2][Ma][Ma], f[Ma][Ma * Ma];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 0; i < Ma; i++) {
        C[0][i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[0][i][j] = C[0][i - 1][j] + C[0][i - 1][j - 1];
    }
    int n, k; ll m; cin >> n >> m >> k;
    ll p = m / n;
    for (int i = 0; i < Ma; i++)
        for (int j = 0; j <= i; j++)
            C[1][i][j] = Mint::fast(C[0][i][j], p);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int jj = 0; jj <= min(n, j); ++jj) {
                f[i][j] = f[i][j] + f[i - 1][j - jj] *
                           C[1][n][jj] *
                           (i - 1 < m % n ? C[0][n][jj] : Mint(1));
            }
        }
    }
    cout << f[n][k] << endl;
}

