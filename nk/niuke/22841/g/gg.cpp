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

const int M = (int)1e6;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int prime[M + 5], cnt;
bool is_prime[M + 5];
int v[M + 5];

void init()
{
    memset(is_prime, 1, sizeof is_prime);
    cnt = is_prime[0] = is_prime[1] = 0;
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
            if(i % prime[j] == 0) break;
        }
    }
}

int n, q, block;

struct qnode
{
    int l, r, id;
    bool operator<(const qnode& b) const
    {
        if(l / block != b.l / block) return l < b.l;
        return r < b.r;
    }
} s[M + 5];
int ans[M + 5], res;
vector<int> g[M + 5];

int c[2][M + 5];

void add(int n)
{
    for(const int& x: g[n])
    {
        if(++c[0][++c[1][x]] == 1) ++res;
    }
}

void del(int n)
{
    for(const int& x: g[n])
    {
        if(--c[0][c[1][x]--] == 0) --res;
    }
}

void work()
{
    read(n), read(q); block = (int)sqrt(n);
    for(int i = 1, a; i <= n; ++i)
    {
        g[i].clear();
        read(a);
        while(a > 1)
        {
            int x = v[a];
            g[i].push_back(x);
            while(a % x == 0) a /= x;
        }
    }
    for(int i = 1; i <= q; ++i) read(s[i].l), read(s[i].r), s[i].id = i;
    sort(s + 1, s + q + 1);
    int l = 1, r = 0; res = 0;
    for(int i = 1; i <= q; ++i)
    {
        while(r < s[i].r) add(++r);
        while(r > s[i].r) del(r--);
        while(l < s[i].l) del(l++);
        while(l > s[i].l) add(--l);
        ans[s[i].id] = res;
    }
    for(int i = 1; i <= q; ++i) print(ans[i], '\n');
    for(int i = l; i <= r; ++i) del(i);
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    init();
    int T; read(T);
    for(int ca = 1; ca <= T; ++ca)
    {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


