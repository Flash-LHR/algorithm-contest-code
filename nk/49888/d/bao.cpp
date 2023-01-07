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

const int M = (int)1e2;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)1e9 + 7;

int sg[M + 5][M + 5];

int dfs(int a, int b) {
    if (~sg[a][b]) return sg[a][b];
    set<int> st;
    if (a >= 1 && b >= 2) st.insert(dfs(a - 1, b - 2));
    if (a >= 2 && b >= 1) st.insert(dfs(a - 2, b - 1));
    for (int i = 0; ; i++) if (!st.count(i)) return i;
}

void work()
{
    memset(sg, -1, sizeof sg);
    for (int i = 1; i <= 20; i++) {
        for (int j = i; j <= 20; j++) {
            printf("i=%d j=%d %d\n", i, j, dfs(i, j) == 0);
        }
        printf("\n");
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