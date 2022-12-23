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
typedef unsigned long long ull;

const int M = (int)2e3;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, q;
char s[M + 5][M + 5];
ull rh[M + 5][M + 5], ch[M + 5][M + 5], p[M + 5], a[M + 5];
int nx[M + 5];

int kmp(int n)
{
    nx[1] = 0;
    for(int i = 2, j = 0; i <= n; ++i)
    {
        while(j > 0 && a[i] != a[j + 1]) j = nx[j];
        if(a[i] == a[j + 1]) ++j;
        nx[i] = j;
    }
    return n - nx[n];
}

int calr(int x1, int y1, int x2, int y2)
{
    for(int i = x1; i <= x2; ++i) a[i - x1 + 1] = rh[i][y2] - rh[i][y1 - 1] * p[y2 - y1 + 1];
    return kmp(x2 - x1 + 1);
}

int calc(int x1, int y1, int x2, int y2)
{
    for(int i = y1; i <= y2; ++i) a[i - y1 + 1] = ch[i][x2] - ch[i][x1 - 1] * p[x2 - x1 + 1];
    return kmp(y2 - y1 + 1);
}

void work()
{
    read(n), read(q);
    for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
    p[0] = 1; 
    for(int i = 1; i <= n; ++i)
    {
        rh[i][0] = ch[0][i] = 0;
        p[i] = p[i - 1] * 131;
        for(int j = 1; j <= n; ++j)
            rh[i][j] = rh[i][j - 1] * 131 + s[i][j] - 'a' + 1,
            ch[i][j] = ch[i][j - 1] * 131 + s[j][i] - 'a' + 1;
    }
    for(int i = 1, x1, y1, x2, y2; i <= q; ++i)
    {
        read(x1), read(y1), read(x2), read(y2);
        print(calr(x1, y1, x2, y2) * calc(x1, y1, x2, y2), '\n');
    }
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


