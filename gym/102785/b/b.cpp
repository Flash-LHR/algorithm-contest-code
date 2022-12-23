#include <bits/stdc++.h>
using namespace std;

#define seg(x) x.begin(), x.end()
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
#define endl '\n'
#define ep emplace
#define eb emplace_back
#define F first
#define S second
constexpr int Ma = 550;

bool bug[Ma][Ma];
bool vis[Ma * Ma];
bool dark[Ma][Ma];

int xz[] = {-1, 1, 0, 0, 0},
    yz[] = {0, 0, 1, -1, 0};

int fa[Ma * Ma];
int id[Ma][Ma];
int find(int u) {while (fa[u] ^ u) u = fa[u] = fa[fa[u]]; return u;}
bool unio(int u, int v) {
    int p1 = find(u), p2 = find(v);
    if (p1 == p2) return false;
    if (p2 > p1) swap(p1, p2);
    fa[p2] = p1; vis[p1] |= vis[p2];
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, q; cin >> n >> m >> q;
    int free = n * n;
    rep (i, n * n + 1) fa[i] = i;
    rep (i, n) rep (j, n) id[i][j] = i * n + j;
    /*rep (i, n) unio(free, id[0][i]),
               unio(free, id[n - 1][i]),
               unio(free, id[i][0]),
               unio(free, id[i][n - 1]);*/
    auto ck = [&] (int r, int c) {
        return r >= 0 and r < n and c >= 0 and c < n;
    };
    rep (_, m) {
        int r, c; cin >> r >> c; bug[r][c] = 1;
        vis[id[r][c]] = true;
        dark[r][c] = true;
        rep (i, 4) {
            int rr = r + xz[i], cc = c + yz[i];
            if (!ck(rr, cc)) unio(free, id[r][c]);
        }
        if (vis[free])
            return cout << "0" << endl, 0;
    }
    fep (idx, 1, q + 1) {
        int r, c; cin >> r >> c;
        dark[r][c] = true;
        rep (i, 4) {
            int rr = r + xz[i], cc = c + yz[i];
            if (ck(rr, cc)) {
                if (dark[rr][cc])
                    unio(id[r][c], id[rr][cc]);
            } else unio(free, id[r][c]);
        }
        if (vis[free]) return cout << idx << endl, 0;
    }
    assert(false);
}

