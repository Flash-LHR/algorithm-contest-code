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

char s[M + 5];
int f[M + 5][M + 5][M + 5];

int fac[M + 5], inv[M + 5], invfac[M + 5];

void init()
{
    fac[0] = fac[1] = inv[1] = invfac[0] = invfac[1] = 1;
    for (int i = 2; i <= M; i++) {
        fac[i] = (ll)fac[i - 1] * i % mod;
        inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
        invfac[i] = (ll)invfac[i - 1] * inv[i] % mod;
    }
}

int invC(int n, int m)
{
    return (ll)fac[m] * fac[n - m] % mod * invfac[n] % mod;
}

void work()
{
    int n; scan(n);
    scanf("%s", s + 1);
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int k = 0; k <= n; k++) f[i][j][k] = 0;
    for (int i = 1; i <= n; i++) {
        int cnt[26] = {0};
        for (int j = i; j <= n; j++) {
            f[1][i][j] = (f[1][i][j - 1] + 1) % mod;
            f[2][i][j] = (f[2][i][j - 1] + cnt[s[j] - 'a']) % mod;
            ++cnt[s[j] - 'a'];
        }
    }
    for (int i = 3; i <= n; i++) {
        for (int len = i; len <= n; len++) {
            for (int j = 1; j + len - 1 <= n; j++) {
                int k = j + len - 1;
                if (s[j] != s[k]) f[i][j][k] = ((f[i][j + 1][k] + f[i][j][k - 1]) % mod - f[i][j + 1][k - 1] + mod) % mod;
                else f[i][j][k] = (((f[i][j + 1][k] + f[i][j][k - 1]) % mod - f[i][j + 1][k - 1] + mod) % mod + f[i - 2][j + 1][k - 1]) % mod;
            }
        }
    }
    int ans = 1;
    for (int i = 1; i < n; i++) ans = (ans + (ll)f[n - i][1][n] * invC(n, i) % mod) % mod;
    print(ans, '\n');
}

int main()
{
    init();
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