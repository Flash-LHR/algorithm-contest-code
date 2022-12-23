#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define sz(x) (int)x.size()
#define lowbit(x) ((x)&(-(x)))
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
using ll=long long;
constexpr int Ma = 320, mod = 1e9 + 7;

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

int c[Ma];
int go[Ma];
bool vis[Ma];
int val[Ma];
Mint f[100100];
int in[Ma], id[Ma];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m, T; cin >> n >> m >> T;
    int cur = 0;
    rep (i, n) cin >> c[i], go[i] = -1;
    rep (i, m) {
        int u; cin >> u; --u;
        cin >> go[u]; --go[u];
        ++in[go[u]];
    }
    iota(id, id + n, 0);
    sort(id, id + n, [&] (int a, int b) {
                    return in[a] < in[b];
                });
    rep (t, n) {
        int i = id[t];
        if (!vis[i]) {
            //cerr << "go " << i << endl;
            int cnt{1};
            vector<int> q(1, i);
            int now = go[i]; vis[i] = true;
            while (now != i and now != -1) {
                vis[now] = true;
                q.emplace_back(now);
                now = go[now]; ++cnt;
            }
            if (now == i) {
                cout << "0" << endl;
                return 0;
            }
            int money = 0;
            rep (j, sz(q)) {
                money += c[q[j]];
                val[cur++] = money;
                if (j == sz(q) - 1) break;
                T -= money;
            }
        }
    }
    //cerr << T << endl;
    if (T < 0) cout << "0" << endl;
    else {
        f[0] = 1;
        rep (i, cur)
            for (int j = 0; j + val[i] <= T; j++)
                f[j + val[i]] = f[j + val[i]] + f[j];
        cout << f[T] << endl;
    }
}

