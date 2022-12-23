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

const int M = (int)2e5;
const int N = (int)17;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int m, n, q;
char s[M + 5];
int last[26];
int f[M + 5][N + 5];

void work()
{
    read(m), read(n);
    scanf("%s", s + 1);
    for(int i = 0; i < m; ++i) last[i] = n + 1;
    f[n + 1][0] = n + 1;
    for(int i = n; i >= 0; --i)
    {
        for(int j = 0; j < m; ++j) f[i][0] = max(f[i][0], last[j]);
        last[s[i] - 'a'] = i;
    }
    for(int j = 1; j <= N; ++j)
    {
        for(int i = 0; i <= n + 1; ++i) f[i][j] = f[f[i][j - 1]][j - 1];
    }
    read(q);
    for(int i = 1, l, r; i <= q; ++i)
    {
        read(l), read(r); --l;
        int ans = 0;
        for(int j = N; j >= 0; --j)
        {
            if(f[l][j] <= r)
            {
                l = f[l][j];
                ans |= (1<<j);
            }
        }
        print(ans + 1, '\n');
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


