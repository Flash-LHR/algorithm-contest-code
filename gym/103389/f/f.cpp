#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

using ll = long long;
#define endl '\n'
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define ep emplace_back
#define mkp make_pair
constexpr int Ma = 2e3 + 100, inf = 0x3f3f3f3f;
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}

template<int md>
struct Mint {
    ll x;
    ll nm(ll x) {
        if (x < 0) x %= md, x += md;
        return x % md;
    }
    Mint inv(Mint a) {
        Mint s{1}; int b = md - 2;
        for (; b; b >>= 1, a = a * a)
            if (b & 1) s = s * a;
        return s;
    }
    Mint(ll x=0) : x(nm(x)) {}
    Mint operator + (const Mint& b) const {return x + b.x;}
    Mint operator - (const Mint& b) const {return x - b.x;}
    Mint operator * (const Mint& b) const {return x * b.x;}
    Mint operator / (const Mint& b) const {return *this * inv(b);}
    bool operator == (const Mint& b) const {return x == b.x;}
    bool operator != (const Mint& b) const {return x != b.x;}
};

template<typename T, int key>
struct Hash {
    T sum[Ma]; T pw[Ma];
    Hash() {
        pw[0] = 1;
        for (int i = 1; i < Ma; i++) pw[i] = pw[i - 1] * key;
    }
    void build(function<char(int)> f, int n) {
        sum[0] = 0;
        for (int i = 0; i < n; i++)
            sum[i + 1] = sum[i] * key + f(i);
    }
    T range(int l, int r) {
        return sum[r + 1] - sum[l] * pw[r - l + 1];
    }
};

constexpr int md1 = 1000000007, md2 = 1000000009;

using m1 = Mint<md1>;
using m2 = Mint<md2>;
using ull = unsigned long long;
struct THash {
    Hash<m1, 177> h1;
    Hash<m2, 233> h2;
    //Hash<ull, 131> h3;
    void build(int n, function<char(int)> f) {
        h1.build(f, n);
        h2.build(f, n);
        //h3.build(f, n);
    }
    pair<Mint<md1>, Mint<md2>> /*ull*/ range(int l, int r) {
        return mkp(h1.range(l, r), h2.range(l, r));
        //return h3.range(l, r);
    }
} rh[Ma], ch[Ma];

ll cal(int l, int r, function<pair<m1, m2>(int)> f) {
    vector<pair<m1, m2>> x;
    //vector<ull> x;
    x.reserve(r - l + 1);
    for (int i = l; i <= r; i++) x.emplace_back(f(i));
    vector<int> next(x.size() + 1);
    int i = 0, j = next[0] = -1;
    int n = x.size();
    while (i < n) {
        while (j != -1 and x[i] != x[j]) j = next[j];
        next[++i] = ++j;
    }
    return n - next[n];
}

char mz[Ma][Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    cout << fixed << setprecision(12);
    int n, q; cin >> n >> q;
    rep (i, n) cin >> mz[i];
    rep (i, n) {
        rh[i].build(n, [&] (int idx) {
                    return mz[i][idx];
                });
        ch[i].build(n, [&] (int idx) {
                    return mz[idx][i];
                });
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        cout << cal(x1, x2, [&] (int idx) {
                    return rh[idx].range(y1, y2);
                }) * cal(y1, y2, [&] (int idx) {
                        return ch[idx].range(x1, x2);
                    }) << endl;
    }

    return 0;
}
