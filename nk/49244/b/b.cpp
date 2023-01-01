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

const int M = (int)1e3;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)1e9 + 7;

char s[M + 5][M + 5];

void work()
{
    int n, m; scan(n, m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);

    auto f = [&](int x, int y) {
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) if (s[i][j] == '#') {
                mx = max(mx, (int)abs(i - x) + (int)abs(j - y));
            }
        }
        return mx;
    };

    int mx = 0;
    mx = max(mx, f(1, 1));
    mx = max(mx, f(1, m));
    mx = max(mx, f(n, 1));
    mx = max(mx, f(n, m));
    print(mx, '\n');
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