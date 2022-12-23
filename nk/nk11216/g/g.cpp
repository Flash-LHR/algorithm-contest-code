#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T& x)
{
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
    x *= f;
}

template <typename T>
void print(T x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch)
{
    print(x), putchar(ch);
}

typedef double db;
typedef long long ll;

const int M = (int)3e6;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

bool is_prime[M + 5];
int prime[M + 5], cnt;
int v[M + 5];

void init()
{
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i <= M; ++i)
    {
        if(is_prime[i])
        {
            prime[++cnt] = i;
            v[i] = i;
        }
        for(int j = 1; j <= cnt && i * prime[j] <= M; ++j)
        {
            is_prime[i * prime[j]] = 0;
            v[i * prime[j]] = prime[j];
            if(i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

struct TA
{
    int n; ll tree[M + 5];
    void init(int _n) {n = _n; for(int i = 0; i <= n; ++i) tree[i] = 0;}
    inline int lowbit(int n) {return n&-n;}
    void add(int a, ll b) {for(int i = a; i <= n; i += lowbit(i)) tree[i] += b;}
    ll ask(int r) {ll s = 0; for(int i = r; i; i -= lowbit(i)) s += tree[i]; return s;}
    ll ask(int l, int r) {return ask(r) - ask(l - 1);}
} tr;

struct node
{
    int n, k, id;
    bool operator<(const node& b) const
    {
        return n < b.n;
    }
} s[M + 5];

int ans[M + 5];

void work()
{
    init();
    int q; read(q);
    for(int i = 1; i <= q; ++i)
    {
        read(s[i].n), read(s[i].k), s[i].id = i;
    }
    sort(s + 1, s + q + 1);
    tr.init(M);
    for(int i = 1, p = 1; i <= q; ++i)
    {
        while(p + 1 <= s[i].n) tr.add(v[++p], 1);
        ans[s[i].id] = tr.ask(M) - tr.ask(s[i].k - 1);
    }
    for(int i = 1; i <= q; ++i) print(ans[i], '\n');
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    int T; read(T);
//    for(int ca = 1; ca <= T; ++ca)
//    {
//        work();
//    }
    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


