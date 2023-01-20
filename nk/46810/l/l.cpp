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

const int M = (int)5e3;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)1e9 + 7;

ll cnt[M + 5];
ll cnt2[M + 5][M + 5];
ll ans[M + 5];

void work()
{
    int n, p; scan(n, p);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        scan(a[i]);
        a[i] %= p;
        for (int j = 1; j < i; j++) {
            cnt[a[i] * a[j] % p] += 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (i != j) {
            cnt2[i][a[i] * a[j] % p] += 2;
        }
    }

    for (int i = 0; i < p; i++) if (cnt[i]) {
        for (int j = 1; j <= n; j++) {
            ans[(a[j] + i) % p] += cnt[i] - cnt2[j][i];
        }
    }

    for (int i = 0; i < p; i++) print(ans[i], " \n"[i == p - 1]);
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    int T = 1; //scan(T);
    for (int ca = 1; ca <= T; ++ca) {
        // printf("Case #%d: ", ca);
        work();
    }
    // cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}