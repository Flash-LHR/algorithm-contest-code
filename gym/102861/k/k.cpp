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

const int M = (int)1e2;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, m;
bool a[M + 5][M + 5];

void nmsl()
{
    printf("-------------------\n");
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n + 1; ++j) printf("%d ", a[i][j]);
        printf("\n");
    }
}

int gauss(int n, int m)
{
    //nmsl();
    int c, r;
    for(c = 1, r = 1; c <= m; ++c)
    {
        int t = r;
        for(int i = r; i <= n; ++i)
        {
            if(a[i][c])   t = i;
        }
        if(!a[t][c]) continue;
        for(int i = c; i <= m + 1; ++i) swap(a[t][i], a[r][i]);
        for(int i = 1; i <= n; ++i)
        {
            if(i == r)  continue;
            if(a[i][c])
            {
                for(int j = m + 1; j >= c; --j)
                {
                    a[i][j] ^= a[r][j];
                }
            }
        }
        ++r;
    }
    //nmsl();
    for(int i = r; i <= n; ++i)
    {
        if(a[i][m + 1])   return -1;
    }
    return m - r + 1;
}

void work()
{
    read(n), read(m);
    for(int i = 1; i <= n; ++i) a[i][i] = a[i][n + 1] = true;
    for(int i = 1, x, y; i <= m; ++i)
    {
        read(x), read(y);
        a[x][y] = a[y][x] = true;
        a[x][n + 1] ^= 1, a[y][n + 1] ^= 1;
    }
    for(int i = 1; i <= n; ++i) if(a[i][n + 1]) a[i][i] = false;
    /*for(int i = 1; i <= 2 * n; ++i)
    {
        for(int j = 1; j <= n + 1; ++j) printf("%d ", a[i][j]);
        printf("\n");
    }*/
    int r = gauss(n, n);
    puts(r == -1 ? "N" : "Y");
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


