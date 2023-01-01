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

typedef long long ll;
typedef unsigned long long ull;

const int M = (int)5e5;
const int N = (int)3 * M;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)998244353;

int x[M + 5], y[M + 5];
int a[N + 5], len;
bool s[4][N + 5];
int f[4][N + 5];

void work()
{
    int n, m; scan(n), scan(m);
    a[++len] = 1, a[++len] = n;
    for (int i = 1; i <= m; i++) {
        scan(x[i], y[i]);
        a[++len] = y[i];
        a[++len] = y[i] + 1;
        a[++len] = y[i] + 2;
    }
    sort(a + 1, a + len + 1);
    while (len >= 1 && a[len] > n) --len;
    len = unique(a + 1, a + len + 1) - (a + 1);
    for (int i = 1; i <= m; i++) {
        s[x[i]][lower_bound(a + 1, a + len + 1, y[i]) - a] = 1;
    }
    f[1][1] = 1;
    for (int j = 1; j <= len; j++) {
        for (int i = 1; i <= 3; i++) if (f[i][j]) {
            if (s[i][j]) {
                (f[max(1, i - 1)][j + 1] += f[i][j]) %= mod;
                (f[i][min(len, j + 2)] += f[i][j]) %= mod;
                (f[min(3, i + 1)][j + 1] += f[i][j]) %= mod;
            } else (f[i][j + 1] += f[i][j]) %= mod;
        }
    }
    print(f[1][len], '\n');
    print(f[2][len], '\n');
    print(f[3][len], '\n');
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    int T = 1; //scan(T);
    for (int ca = 1; ca <= T; ++ca) {
        work();
    }
    // cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}