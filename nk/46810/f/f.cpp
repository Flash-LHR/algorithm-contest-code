#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T &n)
{
    n = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {n = n * 10 + ch - '0'; ch = getchar();}
    if (f == -1) n = -n;
}

template <typename T, typename... A>
inline void scan(T &n, A&... a)
{
    scan(n), scan(a...);
}

template <typename T>
void print(T n)
{
    if (n < 0) putchar('-'), n = -n;
    if (n > 9) print(n / 10);
    putchar(n % 10 + '0');
}

template <typename T>
void print(T n, char ch)
{
    print(n), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const int M = (int)5e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)1e9 + 7;

int n, k;
int a[M + 5][4];
bool vis[2][M + 5][4];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void bfs0(int sx, int sy)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) vis[0][i][j] = false;
    }
    vis[0][sx][sy] = true;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty()) {
        auto [ux, uy] = q.front(); q.pop();
        for (int i = 2; i < 4; i++) {
            int vx = ux + dx[i], vy = uy + dy[i];
            if (vx < 1 || vx > n || vy < 0 || vy > 3 || vis[0][vx][vy] || a[vx][vy]) continue;
            vis[0][vx][vy] = true;
            q.push({vx, vy});
        }
    }
}

void bfs1(int sx, int sy)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) vis[1][i][j] = false;
    }
    vis[1][sx][sy] = true;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty()) {
        auto [ux, uy] = q.front(); q.pop();
        for (int i = 0; i < 2; i++) {
            int vx = ux + dx[i], vy = uy + dy[i];
            if (vx < 1 || vx > n || vy < 0 || vy > 3 || vis[1][vx][vy] || a[vx][vy]) continue;
            vis[1][vx][vy] = true;
            q.push({vx, vy});
        }
    }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                           
void work()
{
    scan(n, k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            a[i][j] = 0;
        }
    }
    for (int i = 1, x, y; i <= k; i++) {
        scan(x, y);
        a[x][y] ^= 1;
    }
    bfs0(1, 1);
    bfs1(n, 3);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) if (!(i == 1 && j == 1)) {
            if (vis[0][i][j] && vis[1][i][j]) ++ans;
        }       
    }
    print(ans, '\n');
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    int T = 1; scan(T);
    for (int ca = 1; ca <= T; ++ca) {
        // printf("Case #%d: ", ca);
        work();
    }
    // cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}