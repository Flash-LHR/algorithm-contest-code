#include <bits/stdc++.h>
using namespace std;

using db=double;
using ll=long long;
#define endl '\n'
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
const int Ma = 2000 + 100, mod = 1e9 + 7;

struct Mint {
    ll x;
    Mint inv(Mint a) {
        Mint s{1};
        for (int b = mod - 2; b; b >>= 1, a = a * a)
            if (b & 1) s = s * a;
        return s;
    }
    ll nm(ll x) {
        if (x < 0) x %= mod, x += mod;
        return x % mod;
    }
    Mint(ll x=0) : x(nm(x)) {}
    Mint operator + (const Mint& b) {
        return x + b.x;
    }
    Mint operator - (const Mint& b) {
        return x - b.x;
    }
    Mint operator * (const Mint& b) {
        return x * b.x;
    }
    Mint operator / (const Mint& b) {
        return *this * inv(b);
    }
};

Mint f[Ma][Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k, m; cin >> n >> k >> m;
    int lim = m / 2, mx = min(k, lim);
    f[0][0] = 1;
    Mint ans{0};
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= mx; j++) {
            if (j) f[i][j] = f[i][j] + f[i - 1][j - 1];
            if (j != mx) f[i][j] = f[i][j] + f[i - 1][j + 1];
        }
        ans = ans + f[i][0];
    }
    cout << (ans * n * 2).x << endl;
}

