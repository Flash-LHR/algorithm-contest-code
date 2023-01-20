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

const int M = (int)4e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)998244353;

struct TA
{
    int n; int tree[M + 5];
    void init(int _n) {n = _n; for(int i = 0; i <= n; ++i) tree[i] = 0;}
    inline int lowbit(int n) {return n&-n;}
    void add(int a, ll b) {for(int i = a; i <= n; i += lowbit(i)) tree[i] += b;}
    ll ask(int r) {ll s = 0; for(int i = r; i; i -= lowbit(i)) s += tree[i]; return s;}
    ll ask(int l, int r) {return ask(r) - ask(l - 1);}
} tr;

int cnt[M + 5];
int L[M + 5], R[M + 5], id[M + 5];

void work()
{
    int n, m; scan(n, m);
    for (int i = 1; i <= m; i++) {
        scan(L[i], R[i]);
        cnt[L[i]]++, cnt[R[i] + 1]--;
        id[i] = i;
    }
    for (int i = 1; i <= M; i++) cnt[i] += cnt[i - 1];
    sort(id + 1, id + m + 1, [&](int a, int b) {return L[a] < L[b];});
    int ans = 0, add = 0; tr.init(M);
    for (int l = 1, i = 0; l < n; l++) if (cnt[l]) {
        while (i + 1 <= m && L[id[i + 1]] <= l) tr.add(R[id[++i]], 1);
        int r = n - l;
        if (r < l) break;
        if (r == l) {
            (add += (ll)cnt[l] * cnt[r] % mod) %= mod;
            (add += -tr.ask(r, M) + mod) %= mod;
        } else {
            (ans += (ll)cnt[l] * cnt[r] % mod) %= mod;
            (ans += -tr.ask(r, M) + mod) %= mod;
        }
    }
    ans = (ans * 2 % mod + add) % mod;
    print(ans, '\n');
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