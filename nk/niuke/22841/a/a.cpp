#include <bits/stdc++.h>
using namespace std;
   
constexpr int Ma = 510;
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define endl '\n'

template<int md>
struct Mint {
    ll x;
    ll nm(ll x) {
        if (x < 0) x %= md, x += md;
        return x % md;
    }
    Mint(ll x=0) : x(nm(x)) {}
    Mint inv(Mint a) {
        int b = md - 2;
        Mint s{1};
        for (; b; b >>= 1, a = a * a)
            if (b & 1) s = s * a;
        return s;
    }
    Mint operator + (const Mint& b) const {return x + b.x;}
    Mint operator - (const Mint& b) const {return x - b.x;} 
    Mint operator * (const Mint& b) const {return x * b.x;} 
    Mint operator / (const Mint& b) const {return *this * inv(b);} 
};

using mint = Mint<119 << 23 | 1>;

mint f[2][Ma][1010];
int mz[Ma][Ma];

void solve() {
    int n, m, q, p; cin >> n >> m >> p >> q;
    rep (i, n) rep (j, m) cin >> mz[i][j];
    if (p + q > n + m - 1) {
        cout << "0" << endl;
        return ;
    }
    int cur = 0;
    f[cur][0][0] = 1;
    rep (i, n) {
        cur ^= 1;
        rep (j, m) {
            rep (k, n + m) {
                f[cur][j][k] = 0;
                if (k >= mz[i][j]) {
                    f[cur][j][k] =
                        f[cur][j][k] +
                        f[cur ^ 1][j][k - mz[i][j]];
                    if (j) f[cur][j][k] =
                        f[cur][j][k] +
                        f[cur][j - 1][k - mz[i][j]];
                }
            }
        }
    }
    mint ans{0};
    for (int i = q; i <= n + m - 1 - p; i++)
        ans = ans + f[cur][m - 1][i];
    cout << ans.x << endl;
}

int main() {
    int t = 1;
    while (t--) solve();
}

