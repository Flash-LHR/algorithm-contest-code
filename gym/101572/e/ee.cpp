#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T& x)
{
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
    x *= f;
}

template <typename T>
void print(T x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch)
{
    print(x), putchar(ch);
}

typedef double db;
typedef long long ll;

const int M = (int)5e2;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, m;
int a[M + 5][M + 5];
queue<pair<int, int>> q;
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
bool vis[M + 5][M + 5];

void work()
{
    read(n), read(m);
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) read(a[i][j]);
    int sx, sy; read(sx), read(sy);
    ll ans = 0;
    vis[sx][sy] = 1, q.push(make_pair(sx, sy));
    while(!q.empty())
    {
        auto [ux, uy] = q.front(); q.pop();
        ans += -max(a[sx][sy], a[ux][uy]);
        for(int i = 0; i < 8; ++i)
        {
            int vx = ux + dx[i], vy = uy + dy[i];
            if(vx < 1 || vx > n || vy < 1 || vy > m || vis[vx][vy] || a[vx][vy] > 0) continue;
            q.push(make_pair(vx, vy));
            vis[vx][vy] = 1;
        }
    }
    print(ans, '\n');
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    int T; read(T);
//    for(int ca = 1; ca <= T; ++ca)
//    {
//        work();
//    }
    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


