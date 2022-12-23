#include <bits/stdc++.h>
using namespace std;

const int Ma = 33, inf = 0x3f3f3f3f;
using ll=long long;
const ll linf = 0x3f3f3f3f3f3f3f3f;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define F first
#define S second
#define mkp make_pair

bool vis[Ma][Ma];
int ans, n, m;
vector<pair<int, int>> g[Ma * Ma];

bool spfa() {
    priority_queue<pair<int, int>> q;
    static bool vis[Ma * Ma];
    static int dis[Ma * Ma], in[Ma * Ma];
    memset(vis, 0, sizeof(bool) * n * m);
    memset(in, 0, sizeof(int) * n * m);
    memset(dis, inf, sizeof(int) * n * m);
    dis[0] = 0;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto t = q.top(); q.pop();
        vis[t.S] = false;
        rap (i, g[t.S]) {
            if (dis[i.F] > dis[t.S] + i.S) {
                in[i.F]++;
                if (in[i.F] > n * m) return false;
                dis[i.F] = dis[t.S] + i.S;
                if (!vis[i.F])
                    q.emplace(-dis[i.F], i.F);
                vis[i.F] = true;
            }
        }
    }
    ans = dis[n * m - 1];
    return true;
}

signed main() {
    while (~scanf("%d%d", &n, &m) and n + m) {
        int w; scanf("%d", &w);
        rep (i, n) rep (j, m) vis[i][j] = false;
        while (w--) {
            int x, y; scanf("%d%d", &x, &y);
            vis[x][y] = true;
        }
        int xz[] = {1, -1, 0, 0},
            yz[] = {0, 0, 1, -1};
        auto ck = [&] (int x, int y) {
            return x >= 0 and x < n and y >= 0 and y < m and !vis[x][y];
        };
        rep (i, n) rep (j, m) {
            g[i * m + j].clear();
            if (i == n - 1 and j == m - 1) continue;
            if (!vis[i][j]) {
                rep (k, 4) {
                    int r = i + xz[k], c = j + yz[k];
                    if (ck(r, c))
                        g[i * m + j].emplace_back(r * m + c, 1);
                }
            }
        }
        int q; scanf("%d", &q);
        while (q--) {
            int x, y; scanf("%d%d", &x, &y);
            g[x * m + y].clear();
            int xx, yy;  scanf("%d%d", &xx, &yy);
            int v; scanf("%d", &v);
            g[x * m + y].emplace_back(xx * m + yy, v);
        }
        if (!spfa()) puts("Never");
        else if (ans == inf) {
            puts("Impossible");
        } else printf("%d\n", ans);
    }

    return 0;
}
