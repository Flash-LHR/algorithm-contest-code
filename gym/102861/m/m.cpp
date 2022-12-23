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
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, q;
ll x[M + 5], y[M + 5];
int m; ll u[M + 5];
int id[M + 5];
vector<int> v;

struct TA
{
    int n;
    vector<int> tree[M + 5];
    void init(int _n)
    {
        n = _n;
        for(int i = 0; i <= n; ++i) tree[i].clear();
    }
    inline int lowbit(int n) {return n&-n;}
    void add(int p, int id)
    {
        while(p <= n)
        {
            tree[p].push_back(id);
            p += lowbit(p);
        }
    }
    void query(int p, ll val)
    {
        while(p)
        {
            for(const auto& i: tree[p])
            {
                if(2 * y[i] + x[i] >= val) v.push_back(i);
                else break;
            }
            p -= lowbit(p);
        }
    }
} tr;

void work()
{
    read(n), read(q);
    for(int i = 1; i <= n; ++i) read(x[i]), read(y[i]), id[i] = i, u[i] = 2 * y[i] - x[i];
    m = n, sort(u + 1, u + m + 1), m = unique(u + 1, u + m + 1) - (u + 1);
    sort(id + 1, id + n + 1, [&](int a, int b) {return 2 * y[a] + x[a] > 2 * y[b] + x[b];});
    tr.init(n);
    for(int i = 1; i <= n; ++i) tr.add(lower_bound(u + 1, u + m + 1, 2 * y[id[i]] - x[id[i]]) - u, id[i]);
    ll a, b, ans = 0;
    for(int i = 1, r; i <= q; ++i)
    {
        read(a), read(b);
        a = -1 - ((ans + a) % mod), b = (ans + b) % mod;
        r = upper_bound(u + 1, u + m + 1, 2 * b - a) - (u + 1), ans = 0;
        if(r)
        {
            v.clear();
            tr.query(r, 2 * b + a);
            sort(v.begin(), v.end()); reverse(v.begin(), v.end());
            for(const auto& x: v) ans = (ans * 5782344ll + x) % mod;
        }
        print(ans, '\n');
    }
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


