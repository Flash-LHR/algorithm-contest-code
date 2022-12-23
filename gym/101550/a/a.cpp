#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = double;
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
constexpr int Ma = 1e3 + 100, inf = 0x3f3f3f3f, Mx = 1e4 + 100;
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

int cnt[Ma][Ma];
int res[Mx][4];
int id[Ma][Ma], n, m;

bool ck(int r, int c) {
    return r >= 0 and r < n and c >= 0 and c < m and cnt[r][c] == 0;
}

int fa[Ma * Ma];
int find(int u) {while (u ^ fa[u]) u = fa[u] = fa[fa[u]]; return u;}
bool unio(int u, int v) {
    int p1 = find(u), p2 = find(v);
    if (p1 == p2) return false;
    fa[p2] = p1;
    return true;
}

int xz[] = {0, 0, 1, -1},
    yz[] = {1, -1, 0, 0};

void dfs(int r, int c, int who) {
    id[r][c] = who;
    if (cnt[r][c]) return ;
    rep (i, 4) {
        int rr = r + xz[i], cc = c + yz[i];
        if (ck(rr, cc) and !id[rr][cc])
            dfs(rr, cc, who);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int q; cin >> n >> m >> q;
    rep (i, n * m + 1) fa[i] = i;
    rep (i, q) {
        rep (j, 4) cin >> res[i][j], --res[i][j];
        auto& x = res[i];
        bool rx = x[0] <= x[2], ry = x[1] <= x[3];
        for (int ii = x[0]; (ii <= x[2]) == rx; ii += rx ? 1 : -1)
            for (int jj = x[1]; (jj <= x[3]) == ry; jj += ry ? 1 : -1)
                ++cnt[ii][jj];
    }
    /*rep (i, n) {
        rep (j, m) if (cnt[i][j]) cout << "1"; else cout <<"0";
        cerr << endl;
    }*/
    int who{0}, ans{0};
    rep (i, n) rep (j, m) if (!id[i][j]) dfs(i, j, ++who), ans += cnt[i][j] == 0;
    //cerr << "ans = " << ans << endl;
    stack<int> st;
    for (int i = q - 1; i >= 0; i--) {
        st.ep(ans);
        auto& x = res[i];
        bool rx = x[0] <= x[2], ry = x[1] <= x[3];
        for (int ii = x[0]; (ii <= x[2]) == rx; ii += rx ? 1 : -1)
            for (int jj = x[1]; (jj <= x[3]) == ry; jj += ry ? 1 : -1) {
                if (--cnt[ii][jj] == 0) {
                    ++ans;
                    vector<int> t(1, id[ii][jj]);
                    rep (k, 4) {
                        int rr = ii + xz[k], cc = jj + yz[k];
                        if (ck(rr, cc)) t.eb(find(id[rr][cc]));
                    }
                    rap (k, t) rap (kk, t) if (k != kk) ans -= unio(k, kk);
                }
            }
    }
    while (!st.empty()) cout << st.top() << endl, st.pop();
}

