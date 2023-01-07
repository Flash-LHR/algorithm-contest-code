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

const int M = (int)4e2;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)1e9 + 7;

int n, m;
char s[M + 5][M + 5];
bool vis[M + 5][M + 5];
char dir[M + 5][M + 5];
char path[M * M + 5];

//ESWN
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dfs(int ux, int uy) {
    vis[ux][uy] = 1;
    int cnt = 1;
    for (int i = 0, vx, vy; i < 4; i++) {
        vx = ux + dx[i], vy = uy + dy[i];
        if (vx < 1 || vx > n || vy < 1 || vy > m || vis[vx][vy] || s[vx][vy] == '#') continue;
        if (i == 0) {
            dir[2 * ux - 1][2 * uy] = 0;
            dir[2 * vx][2 * vy - 1] = 2;
        } else if (i == 1) {
            dir[2 * ux][2 * uy] = 1;
            dir[2 * vx - 1][2 * vy - 1] = 3;
        } else if (i == 2) {
            dir[2 * ux][2 * uy - 1] = 2;
            dir[2 * vx - 1][2 * vy] = 0;
        } else if (i == 3) {
            dir[2 * ux - 1][2 * uy - 1] = 3;
            dir[2 * vx][2 * vy] = 1;
        }
        cnt += dfs(vx, vy);
    }
    return cnt;
}

void getPath(int x, int y, int u)
{
    int d = dir[x][y];
    path[u] = "ESWN"[d];
    x += dx[d], y += dy[d];
    if (x != 1 || y != 1) getPath(x, y, u + 1);
}

void work()
{
    scan(n, m);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '*') ++cnt;
            dir[2 * i - 1][2 * j - 1] = 0;
            dir[2 * i - 1][2 * j] = 1;
            dir[2 * i][2 * j] = 2;
            dir[2 * i][2 * j - 1] = 3;

            vis[2 * i - 1][2 * j - 1] = 0;
            vis[2 * i - 1][2 * j] = 0;
            vis[2 * i][2 * j - 1] = 0;
            vis[2 * i][2 * j] = 0;
        }
    }
    path[cnt * 4] = '\0';
    cnt -= dfs(1, 1);
    if (cnt) return printf("IMPOSSIBLE\n"), void();
    getPath(1, 1, 0);
    printf("%s\n", path);
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    int T = 1; scan(T);
    for (int ca = 1; ca <= T; ++ca) {
        printf("Case #%d: ", ca);
        work();
    }
    // cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}