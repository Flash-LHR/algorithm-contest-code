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

const int M = (int)6e2;
const int N = (int)1e5;
const db eps = 1e-6;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int u;
db f[M + 5][M + 5][2];
int v[20] = {1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5, 20};

db dfs(int n, int m, int k)
{
    if(n == 0) return (u == 0 ? 1.0 : 0.0);
    if(m == 0) return (u == 0 ? 0.0 : 1.0);
    if(f[n][m][k] > -eps) return f[n][m][k];
    int cnt = 0; f[n][m][k] = 0.0;
    if(k == 0)
    {
        for(int i = 0; i < 20; ++i)
        {
            if(v[i] <= n)
            {
                ++cnt;
                f[n][m][k] += dfs(n - v[i], m, k^1);
            }
        }
        if(cnt == 20) f[n][m][k] /= 20;
        else f[n][m][k] /= 20 - cnt;
    }
    else
    {
        for(int i = 0; i < 20; ++i)
        {
            cnt = 0; double s = 0.0;
            for(int j = -1; j <= 1; ++j)
            {
                if(v[(i + j + 20) % 20] <= m)
                {
                    ++cnt;
                    s += dfs(n, m - v[(i + j + 20) % 20], k^1);
                }
            }
            printf("i=%d s=%f cnt=%d\n", i, s, cnt);
            if(cnt == 3) f[n][m][k] = max(f[n][m][k], s / 3);
            else f[n][m][k] = max(f[n][m][k], s / (3 - cnt));
        }
    }
    printf("f[%d][%d][%d]=%f\n", n, m, k, f[n][m][k]);
    return f[n][m][k];
}

void work()
{
   int n; read(n);
   printf("%.9f\n", dfs(n, n, u = 1));
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
    for(int i = 0; i <= M; ++i) for(int j = 0; j <= M; ++j) f[i][j][0] = f[i][j][1] = -1.0;
    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


