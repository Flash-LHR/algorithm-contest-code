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
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, m;
struct node
{
    char op;
    int t, m, a;
} s[M + 5];
int d[2][M * 4 + 5];
int c[2][M * 4 + 5];

void add(int o, int l, int r)
{
    //printf("l=%d r=%d\n", l, r);
    ++c[o][l + M];
    ++d[o][l + M], --d[o][r + 1 + M];
}

void work()
{
    read(n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%c %d %d %d", &s[i].op, &s[i].t, &s[i].m, &s[i].a);
        getchar();
        add(s[i].op == 'h', s[i].t - s[i].a, s[i].t - s[i].a + s[i].m - 1);
    }
    for(int i = 1; i <= 4 * M; ++i) d[0][i] += d[0][i - 1], d[1][i] += d[1][i - 1];
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        ans += d[s[i].op != 'h'][s[i].t - s[i].a + M];
    }
    for(int i = 0; i <= 4 * M; ++i) ans -= 1ll * c[0][i] * c[1][i];
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


