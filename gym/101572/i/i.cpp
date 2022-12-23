#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = double;
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
constexpr int Ma = 600, inf = 0x3f3f3f3f;
constexpr db dinf = numeric_limits<db>::max();
#define ep emplace_back
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}

string name[Ma];
gp_hash_table<string, int> id;

int g[Ma][Ma], f[Ma][Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    rep (i, n) cin >> name[i], id[name[i]] = i;
    memset(g, inf, sizeof g);
    memset(f, -1, sizeof f);
    rep (i, n) {
        string t; cin >> t; int who = id[t];
        int k; cin >> k;
        rep (j, k) {
            string p; cin >> p;
            while (cin >> p, p.back() == ',') {
                p.pop_back();
                g[who][id[p]] = 1;
            }
            g[who][id[p]] = 1;
        }
    }
    rep (i, n) if (g[i][i] == 1) {
        cout << name[i] << endl;
        return 0;
    }
    rep (i, n) rep (j, n) if (g[i][j] == 1 and g[j][i] == 1) {
        cout << name[i] << ' ' << name[j] << endl;
        return 0;
    }
    int ans = inf; vector<int> av;
    function<void(int, int, bool)> gen = [&] (int l, int r, bool ct) {
        if (f[l][r] != -1) {
            gen(l, f[l][r], ct and true); gen(f[l][r], r, false);
        } else {
            if (ct) av.ep(l);
            av.ep(r);
        }
    };
    rep (k, n) {
        int ii{-1}, jj{-1};
        rep (i, n) rep (j, n) {
            if (g[j][i] != inf and g[i][k] == 1 and g[k][j] == 1 and
                !cmin(ans, g[j][i] + g[i][k] + g[k][j]))
                ii = i, jj = j;
        }
        if (ii != -1 and jj != -1) {
            av.clear();
            gen(jj, ii, true); av.ep(k);
        }
        rep (i, n) rep (j, n) if (!cmin(g[i][j], g[i][k] + g[k][j]))
            f[i][j] = k;
    }
    if (ans == inf) cout << "SHIP IT" << endl;
    else {
        rep (i, sz(av)) cout << name[av[i]] << " \n"[i == sz(av) - 1];
    }
}
