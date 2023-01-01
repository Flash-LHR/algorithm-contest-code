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

void work()
{
    int n, k; scan(n, k);
    vector<vector<int>> ans(k + 1, vector<int>(n + 1, 0));
    int p = 1;

    auto add = [&](int &x, int y, int len, int val) {
        while (len-- > 0) {
            ans[x][y] += val;
            x = x % k + 1;
        }
    };

    for (int j = 1; j <= n; j++) {
        if (j % k == 0)
            add(p, j, k, j / k);
        else {
            int x = j - k * (j / k);
            add(p, j, x, (j + k - 1) / k);
            int tmp_p = p;
            add(p, j, k - x, j / k);
            p = tmp_p;
        }
    }
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++) print(ans[i][j], " \n"[j == n]);
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