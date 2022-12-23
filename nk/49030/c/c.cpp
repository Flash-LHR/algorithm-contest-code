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
    int n; scan(n);
    vector<int> a(n), b(n), p(n);
    for (int &x: a) scan(x);
    for (int &x: b) scan(x);
    iota(p.begin(), p.end(), 0);
    vector<int> ans(3);
    do {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[p[i]] > b[i]) ++cur;
            else if (a[p[i]] < b[i]) --cur;
        }
        if (cur > 0) ans[0]++;
        else if (cur < 0) ans[1]++;
        else ans[2]++;
    } while(next_permutation(p.begin(), p.end()));
    printf("%d %d %d\n", ans[0], ans[1], ans[2]);
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