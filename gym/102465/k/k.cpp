#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = a, i##_ = (x); i < i##_; i++)
#define S second
#define F first
#define endl '\n'
#define sz(x) (int)x.size()
#define mkp make_pair
using ll=long long;
using db=double;
template<typename T>
T cmax(T& a, const T& b) {return a >= b or (a = b, false);}
template<typename T>
T cmin(T& a, const T& b) {return a <= b or (a = b, false);}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

constexpr db eps = 1e-9;
int sign(db x) {return x < -eps ? -1 : x > eps;}
constexpr int Ma = 710 + 100, inf = 0x3f3f3f3f;

template<int md>
struct Mint {
    ll x;
    ll nm(ll x) const {
        if (x < 0) x %= md, x += md;
        return x % md;
    }
    Mint inv(Mint x) const {
        Mint s(1);
        for (int b = md - 2; b; b >>= 1, x = x * x)
            if (b & 1) s = s * x;
        return s;
    }
    Mint(ll x=0) : x(nm(x)) {}
    Mint operator + (const Mint& b) const {
        return x + b.x;
    }
    Mint operator - (const Mint& b) const {
        return x - b.x;
    }
    Mint operator * (const Mint& b) const {
        return x * b.x;
    }
    Mint operator / (const Mint& b) const {
        return x * inv(b).x;
    }
    bool operator == (const Mint& a) const {
        return x == a.x;
    }
};

template<typename T, int k>
struct Hash {
    T pw[Ma];
    T h[Ma];
    Hash() {
        pw[0] = 1; for (int i = 1; i < Ma; i++) pw[i] = pw[i - 1] * k;
    }
    void build(const string& s) {
        for (int i = 0; i < sz(s); i++)
            h[i + 1] = h[i] * k + s[i];
    }
    T range(int l, int r) {
        return h[r + 1] - h[l] * pw[r - l + 1];
    }
};

struct HS {
    size_t operator () (const pair<int, int>& a) {
        return (a.F + a.S) ^ (a.F * a.S);
    }
};

template<typename T1=Mint<1000000007>, typename T2=Mint<1000000009>>
struct TH {
    Hash<T1, 133> h1;
    Hash<T2, 177> h2;
    pair<T1, T2> one{1, 1};
    void build(const string& s) {
        h1.build(s); h2.build(s);
    }
    pair<T1, T2> range(int l, int r) {
        return make_pair(h1.range(l, r), h2.range(l, r));
    }
    pair<T1, T2> pw(int x) {
        return mkp(h1.pw[x], h2.pw[x]);
    }
};

TH<> hs;

int f[Ma][Ma];

template<typename T1, typename T2>
pair<T1, T2> operator + (const pair<T1, T2>& a, const pair<T1, T2>& b) {
    return mkp(a.F + b.F, a.S + b.S);
}
template<typename T1, typename T2>
pair<T1, T2> operator - (const pair<T1, T2>& a, const pair<T1, T2>& b) {
    return mkp(a.F - b.F, a.S - b.S);
}
template<typename T1, typename T2>
pair<T1, T2> operator * (const pair<T1, T2>& a, const pair<T1, T2>& b) {
    return mkp(a.F * b.F, a.S * b.S);
}
template<typename T1, typename T2>
pair<T1, T2> operator / (const pair<T1, T2>& a, const pair<T1, T2>& b) {
    return mkp(a.F / b.F, a.S / b.S);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    string s; cin >> s;
    hs.build(s);
    memset(f, inf, sizeof f);
    for (int i = 0; i < n; i++) f[i][i] = 1;
    for (int l = 2; l <= n; l++)
        for (int i = 0; i + l <= n; i++) {
            for (int k = 1; k < l; k++) {
                cmin(f[i][i + l - 1],
                     f[i][i + k - 1] + f[i + k][i + l - 1]);
                if (k % (l - k)) continue;
                auto t = hs.range(i + k, i + l - 1);
                auto me = t * (hs.one - hs.pw(k)) /
                          (hs.one - hs.pw(l - k));
                if (me == hs.range(i, i + k - 1))
                    cmin(f[i][i + l - 1], f[i + k][i + l - 1]);
            }
        }
    /*rep (i, n) {
        fep (j, i, n)
         cerr << f[i][j] << '\t';
        cerr << endl;
    }*/
    cout << f[0][n - 1] << endl;
}
