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

const int M = (int)1e5;
const int N = (int)1e6;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int prime[N + 5], cnt;
bool is_prime[N + 5];
int v[N + 5];

void init()
{
    memset(is_prime, 1, sizeof is_prime);
    cnt = is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i <= N; ++i)
    {
        if(is_prime[i])
        {
            prime[++cnt] = i;
            v[i] = i;
        }
        for(int j = 1; j <= cnt && i * prime[j] <= N; ++j)
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
        if((l - 1) / block != (b.l - 1) / block) return l < b.l;
        return r < b.r;
    }
} s[M + 5];

int id[M + 5], L[M + 5], R[M + 5];
vector<int> g[M + 5];
int buk[N + 5], buk2[N + 5];
int ans[M + 5];

inline void del(int p)
{
    for(const int& x: g[p]) --buk[x];
}

inline void add(int p, int& mx)
{
    for(const int& x: g[p]) mx = max(mx, ++buk[x]);
}

void work()
{
    read(n), read(q), block = (int)sqrt(n);
    for(int i = 1; i <= n; ++i) id[i] = L[i] = R[i] = 0;
    for(int i = 1, a; i <= n; ++i)
    {
        read(a);
        g[i].clear();
        while(a > 1)
        {
            int x = v[a];
            g[i].push_back(x);
            while(a % x == 0) a /= x;
        }
        id[i] = (i - 1) / block + 1;
        if(L[id[i]] == 0) L[id[i]] = i;
        R[id[i]] = i;
    }
    for(int i = 1; i <= q; ++i) read(s[i].l), read(s[i].r), s[i].id = i;
    sort(s + 1, s + q + 1);
    int l = 1, r = 0, lastBlock = 0, mx = 0;
    for(int i = 1; i <= q; ++i)
    {
        if(id[s[i].l] == id[s[i].r])
        {
            int mx = 0;
            for(int j = s[i].l; j <= s[i].r; ++j)
            {
                for(const int& x: g[j]) mx = max(mx, ++buk2[x]);
            }
            for(int j = s[i].l; j <= s[i].r; ++j)
            {
                for(const int& x: g[j]) --buk2[x];
            }
            ans[s[i].id] = mx;
            continue;
        }
        if(lastBlock != id[s[i].l])
        {
            while(r > R[id[s[i].l]]) del(r--);
            while(l < R[id[s[i].l]] + 1) del(l++);
            mx = 0, lastBlock = id[s[i].l];
        }
        while(r < s[i].r) add(++r, mx);
        int cur = mx, ll = l;
        while(ll > s[i].l) add(--ll, cur);
        ans[s[i].id] = cur;
        while(ll < l) del(ll++);
    }
    for(int i = 1; i <= q; ++i) print(ans[i], '\n');
    for(int i = l; i <= r; ++i)
    {
        for(const int& x: g[i]) --buk[x];
    }
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


