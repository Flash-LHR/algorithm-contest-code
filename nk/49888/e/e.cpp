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

const int M = (int)1e6;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)1e9 + 7;

int f[M + 5], g[M + 5];

void init() {
    auto cal = [](int n) {
        int c = !!(n & (n - 1));
        while (n) {
            ++c;
            n >>= 1;
        }
        return c - 1;
    };

    f[1] = 0;
    for (int i = 2; i <= M; i++) f[i] = f[i - 1] + (g[i] = cal(i));
}

void work()
{
    int n, k; scan(n, k);
    if (f[n] < k) return print(-1, '\n');
    int l = 1, r = n;
    for (int i = n; i >= 1; i--) {
        if (f[i - 1] >= k) print(l++, ' ');
        else k -= g[i], print(r--, ' ');
    }
    putchar('\n');
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    init();
    int T = 1; //scan(T);
    for (int ca = 1; ca <= T; ++ca) {
        work();
    }
    // cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}