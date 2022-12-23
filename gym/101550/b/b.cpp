#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using db = double;
using ull = uint64_t;;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define F first
#define S second
#define mkt make_tuple
#define mkp make_pair
#define eb emplace_back
#define ep emplace
#define sz(x) (int)x.size()
#define state(x) (1<<(x))
#define endl '\n'
constexpr int Ma = 1e5 + 100, inf = 0x3f3f3f3f, Mx = 1e4 + 100;
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

template<int k>
struct Hash {
    vector<ull> tot; int size;
    void build(char* s) {
        int n = strlen(s); size = n;
        tot.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            tot[i + 1] = tot[i] * k + s[i];
    }
    ull pre(int r) {
        return tot[r + 1];
    }
};

Hash<131> hs[Ma], h;
gp_hash_table<ull, int> ck;

char s[Ma * 20];
int f[Ma];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    cout << fixed << setprecision(12);
    int n, m; cin >> n >> m;
    rep (i, n) {
        cin >> s;
        hs[i].build(s);
        rep (j, hs[i].size) if (ck.find(hs[i].pre(j)) == ck.end())
            ck[hs[i].pre(j)] = i;
    }
    while (m--) {
        cin >> s;
        int len = strlen(s);
        h.build(s);
        rep (i, len) f[i] = inf;
        f[0] = 1;
        rep (i, len) {
            if (ck.find(h.pre(i)) != ck.end()) {
                int who = ck[h.pre(i)];
                int l = i, r = min(len, hs[who].size);
                while (r - l > 1) {
                    int mid(l + (r - l) / 2);
                    if (hs[who].pre(mid) == h.pre(mid)) l = mid;
                    else r = mid;
                }
                cmin(f[l], f[i] + 1 + hs[who].size - l - 1);
                //cerr << "reg: " << i << ' ' << f[i] << endl;
                //cerr << who << ' ' << l << ' ' << f[l] << endl;
            }
            cmin(f[i + 1], f[i] + 1);
        }
        cout << f[len - 1] << endl;
        //cout.flush();
        //assert(false);
    }
}

