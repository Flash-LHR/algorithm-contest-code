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

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)1e9 + 7;

ll f[M + 5][4][4];

void work()
{
    int n, k; scan(n, k);
    vector<int> w(k);
    for (int &x: w) scan(x);

    auto cal = [&](int n, int kk, int a, int b) {
        memset(f, 0x3f, sizeof f);
        f[1][a][b] = w[a] + w[b];
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < kk; j++) {
                for (int k = 0; k < kk; k++) {
                    for (int l = 0; l < kk; l++) if (!(j == k && k == l)) {
                        f[i][j][k] = min(f[i][j][k], f[i - 1][l][j] + w[k]);
                    }
                }
            }
        }
        ll cur = linf;
        for (int i = 0; i < kk; i++) {
            for (int j = 0; j < kk; j++) if (!(i == j && j == a) && !(j == a && a == b)) {
                cur = min(cur, f[n - 1][i][j]);
            }
        }
        return cur;
    };

    ll mi = linf;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; ++j) {
            mi = min(mi, cal(n, k, i, j));
        }
    }
    if (mi == linf) printf("Ginger666\n");
    else print(mi, '\n');
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    int T = 1; //scan(T);
    for (int ca = 1; ca <= T; ++ca) {
        // printf(
        work();
    }
    // cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}