#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = a, i##_ = (x); i < i##_; i++)
#define S second
#define F first
#define endl '\n'
#define sz(x) (int)x.size()
#define mkp make_pair
#define ep emplace_back
using ll=long long;
using db=double;
template<typename T>
T cmax(T& a, const T& b) {return a >= b or (a = b, false);}
template<typename T>
T cmin(T& a, const T& b) {return a <= b or (a = b, false);}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

constexpr db eps = 1e-9;
int sign(db x) {return x < -eps ? -1 : x > eps;}
constexpr int Ma = 1000 + 100, inf = 0x3f3f3f3f;

char mz[Ma][Ma];
int id[Ma][Ma], cnt;

int n, m;

bool ck(int a, int b) {
    return a >= 0 and a < n and b >= 0 and b < m;
}

int xz[] = {1, -1, 0, 0, 1, -1, -1, 1},
    yz[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool al;

vector<pair<int, int>> res[Ma * Ma];

void dfs(int r, int c, int who, char t) {
    if (r == 0 or c == 0 or r == n - 1 or c == m - 1)
        al = false;
    id[r][c] = who;
    res[who].emplace_back(r, c);
    rep (i, 8) {
        int rr = r + xz[i], cc = c + yz[i];
        if (ck(rr, cc) and mz[rr][cc] == t) {
            dfs(rr, cc, who, t);
        }
    }
}
bool vis[Ma][Ma];

void dfs(int r, int c, set<int>& ck) {
    vis[r][c] = true;
    rep (i, 8) {
        int rr = r + xz[i], cc = c + yz[i];
        if (ck(rr, cc)) {
            if (id[rr][cc] == id[r][c] and !vis[rr][cc]) dfs(rr, cc);
            else ck.emplace(id[rr][cc]);
        }
    }
}

int ans[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> m >> n;
    rep (i, n) cin >> mz[i];
    queue<pair<int, int>> q;
    rep (i, n) rep (j, m) if (id[i][j] == 0) {
        al = true;
        dsf(i, j, ++cnt, mz[i][j]);
        if (mz[i][j] == '#' and al) q.emplace(i, j);
    }
    while (!q.empty()) {
        set<int> ck;
        auto [r, c] = q.front(); q.pop();
        dfs(r, c, ck);
        int x{-1}, y{-1};
        sort(seg(res[id[r][c]]));
        vector<int> ck;
        auto& rc = res[id[r][c]];
        bool can{true};
        if (ck.size() == 1) {
            rep (i, sz(rc)) {
                if (!can) break;
                int len{0}; int aim = rc[i].S;
                while (i < i_ and rc[i].F == r) {
                    if (aim != rc[i].S) can = false;
                    ++aim; ++len; ++i;
                }
                if (x != -1) {
                    if (len != ck.back() and x != ck[0])
                        can = false;
                } else if (i and len != ck[0]) {
                    x = len;
                    y = ck[0] - 2 * x;
                    if (y <= 0) can = false;
                }
                ck.ep(len);
            }
            can &= ck.size() == 3 * x + 2 * y and
                   all_of(ck.begin(), ck.begin() + x,
                          [&] (int t) { return t == x + y + x;}) and
                   all_of(ck.begin() + x, ck.begin() + 2 * x + 2 * y,
                          [&] (int t) { return t == x; }) and
                   all_of(ck.begin() + 2 * x + 2 * y, ck.begin() + 3 * x + 2 * y,
                           [&] (int t) {return t == x + y + x;});
            ans[2] += can;
        } else if (ck.size() == 2) {
            rap (i, sz(rc)) {
                if (!can) break;
                int len{0}; int aim = rc[i].S;
                while (i < i_ and rc[i].F == r) {
                    if (aim != rc[i].S) {
                        if (ck.empty()) can = false;
                        y = rc[i].F - aim;
                        x = ck[0] - y;
                        if (x & 1) can = false;
                        x /= 2;
                    }
                    ++aim; ++len; ++i;
                }
            }
        } else if (ck.size() == 3) {
            ;
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
}
