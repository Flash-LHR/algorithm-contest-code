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

int n, d;
int a[M + 5];
ll f[M + 5][M + 5][2];

int cal(int a, int b) {
    return min((a - b + d) % d, (b - a + d) % d);
}

void work()
{
    scan(n, d);
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) scan(a[i]), f[i][i][0] = f[i][i][1] = 0;
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            f[l][r][0] = min(f[l][r][0], f[l + 1][r][0] + cal(a[l], a[l + 1]));
            f[l][r][0] = min(f[l][r][0], f[l + 1][r][1] + cal(a[l], a[r]));
            f[l][r][1] = min(f[l][r][1], f[l][r - 1][0] + cal(a[r], a[l]));
            f[l][r][1] = min(f[l][r][1], f[l][r - 1][1] + cal(a[r], a[r - 1]));
        }
    }
    ll mi = linf;
    mi = min(mi, f[1][n][0] + cal(a[1], 0));
    mi = min(mi, f[1][n][1] + cal(a[n], 0));
    print(mi, '\n');
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