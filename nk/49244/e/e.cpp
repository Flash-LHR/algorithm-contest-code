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
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)1e9 + 7;

int a[M + 5];

void work()
{
    int n, m, len; scan(n, m, len);
    for (int i = 1; i <= n; i++) scan(a[i]), a[i] = !!a[i];
    int ans = 0;
    for (int i = 1; i + len + 1 <= n; i++)
        if (a[i] == 0 || a[i + len + 1] == 0) ++ans;
    for (int i = 1, pos, val; i <= m; i++) {
        scan(pos, val); val = !!val;
        if (val != a[pos]) {
            if (pos + len + 1 <= n && a[pos] == 0 && a[pos + len + 1] == 1) --ans;
            if (pos + len + 1 <= n && a[pos] == 1 && a[pos + len + 1] == 1) ++ans;
            if (pos - len - 1 >= 1 && a[pos] == 0 && a[pos - len - 1] == 1) --ans;
            if (pos - len - 1 >= 1 && a[pos] == 1 && a[pos - len - 1] == 1) ++ans;
            a[pos] = val;
        }
        print(ans, '\n');
    }
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