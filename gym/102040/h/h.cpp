#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define endl '\n'
#define ep emplace_back
#define F first
#define S second
const int Ma = 200 + 10, mod = 78294349;
using ll = long long;
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

char mz[Ma][Ma];
int id[Ma][Ma];
int bid[Ma][Ma];
int go[Ma];
bool is[Ma * Ma]; int prim[Ma * Ma], cnt;
int res[Ma * Ma];

ll fast(ll a, ll b) {
    ll s{1};
    for (a %= mod; b; b >>= 1, a = a * a % mod)
        if (b & 1) s = s * a % mod;
    return s;
}

void solve() {
    int n, m; cin >> n >> m;
    rep (i, n) cin >> mz[i];
    int cur{0};
    rep (i, n) rep (j, m) if (mz[i][j] == '#') id[i][j] = ++cur, bid[i][j] = id[i][j];
                          else id[i][j] = bid[i][j] = 0;
    memset(res, 0, sizeof(int) * cnt);
    rep (i, n) {
        for (int j = m - 1; j >= 0; j--) if (id[i][j]) {
            for (int k = j + 1; k < m; k++) {
                if (id[i][k] == 0) {
                    swap(id[i][k], id[i][k - 1]);
                } else break;
            }
        }
    }
    rep (j, m) {
        for (int i = 0; i < n; i++) if (id[i][j]) {
            for (int k = i - 1; k >= 0; k--) {
                if (id[k][j] == 0) {
                    swap(id[k][j], id[k + 1][j]);
                } else break;
            }
        }
    }
    rep (i, n) {
        for (int j = 0; j < m; j++) if (id[i][j]) {
            for (int k = j - 1; k >= 0; k--) {
                if (id[i][k] == 0) {
                    swap(id[i][k], id[i][k + 1]);
                } else break;
            }
        }
    }
    rep (j, m) {
        for (int i = n - 1; i >= 0; i--) if (id[i][j]) {
            for (int k = i + 1; k < n; k++) {
                if (id[k][j] == 0) {
                    swap(id[k][j], id[k - 1][j]);
                } else break;
            }
        }
    }
    //cerr << "show" << endl;
    /*rep (i, n) {
        rep (j, m) cout << id[i][j] << ' ';
        cout << endl;
    }*/
    rep (i, n) rep (j, m) if (id[i][j]) {
        //cerr << bid[i][j] << ' ' << id[i][j] << endl;
        go[bid[i][j]] = id[i][j];
    }
    bool vis[cur + 1];
    rep (i, cur + 1) vis[i] = false;
    for (int i = 1; i <= cur; i++) if (!vis[i]) {
        int len{1}; vis[i] = true;
        int now = go[i];
        while (now != i) {
            vis[now] = true, now = go[now], ++len;
            //cerr << now << endl;
        }
        //cerr << len << endl;
        rep (j, cnt) if (len >= prim[j]) {
            int t{0};
            while (len % prim[j] == 0) ++t, len /= prim[j];
            cmax(res[j], t);
        } else break;
    }
    ll ans{1};
    for (int i = 0; i < cnt; i++) if (res[i])
        ans *= fast(prim[i], res[i]), ans %= mod;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    is[1] = is[0] = true;
    for (int i = 2; i < Ma * Ma; i++) {
        if (!is[i]) prim[cnt++] = i;
        for (int j = 0; j < cnt and prim[j] * i < Ma * Ma; j++) {
            is[prim[j] * i] = true;
            if (i % prim[j] == 0) break;
        }
    }
    int t; cin >> t;
    rep (qq, t) {
        cout << "Case " << qq + 1 << ": ";
        solve();
    }
}
