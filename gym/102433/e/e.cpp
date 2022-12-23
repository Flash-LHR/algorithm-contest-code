#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using db = double;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define ep emplace
#define eb emplace_back
#define mkp make_pair
#define mkt make_tuple

constexpr int Ma = 2e5 + 100;

template<int md>
struct Mint {
    static ll nm(ll x) {
        if (x < 0) x %= md, x += md;
        return x % md;
    }
    static Mint fast(Mint a, int b) {
        Mint s{1};
        for (; b; b >>= 1, a = a * a)
            if (b & 1) s = s * a;
        return s;
    }
    static Mint inv(Mint x) {
        return fast(x, md - 2);
    }
    ll x;
    Mint(ll x=0) : x(nm(x)) {}
    Mint operator + (const Mint& b) {return x + b.x;}
    Mint operator - (const Mint& b) {return x - b.x;}
    Mint operator * (const Mint& b) {return x * b.x;}
    Mint operator / (const Mint& b) {return *this * inv(b);}
};


using mint = Mint<11092019>;
ostream& operator << (ostream& out, mint x) {
    out << x.x;
    return out;
}

gp_hash_table<char, int> ct;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    mint ans{1};
    string s; cin >> s;
    rap (i, s) ++ct[i];
    rap (i, ct) ans = ans * (i.second + 1);
    cout << ans.x << endl;
}
