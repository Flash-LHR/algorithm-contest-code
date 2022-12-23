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

const int M = (int)2e5;
const int N = (int)5e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

bool is_prime[N + 5];
int prime[N + 5], cnt;
int v[N + 5];

void init()
{
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
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
            if(i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

struct segT
{
    int one[M * 4 + 5];
    int s[M * 4 + 5], val[M * 4 + 5];

    inline int lc(int k) {return k<<1;}
    inline int rc(int k) {return k<<1|1;}
    inline void push_up(int k) {s[k] = s[lc(k)] + s[rc(k)], one[k] = one[lc(k)]|one[rc(k)];}

    void build(int k, int l, int r)
    {
        if(l == r)
        {
            read(val[k]);
            one[k] = (val[k] == 1);
            s[k] = is_prime[val[k]];
            return;
        }
        int mid = (l + r) >> 1;
        build(lc(k), l, mid);
        build(rc(k), mid + 1, r);
        push_up(k);
    }

    void update(int k, int l, int r, int a, int b, int c)
    {
        if(one[k] == 0 && s[k] == 0) return;
        if(l == r)
        {
            if(l == 1) return;
            if(one[k] == 1 && c == 1 && is_prime[l])
            {
                one[k] = 0, s[k] = 1;
            }
            else
            one[k] = s[k] = 0;
            //printf("k=%d l=%d r=%d a=%d b=%d c=%d s=%d\n", k, l, r, a, b, c, s[k]);
            return;
        }
        int mid = (l + r) >> 1;
        if(a <= mid) update(lc(k), l, mid, a, b, c);
        if(mid < b)  update(rc(k), mid + 1, r, a, b, c);
        push_up(k);
        //printf("k=%d l=%d r=%d s=%d\n", k, l, r, s[k]);
    }

    int query(int k, int l, int r, int a, int b)
    {
        if(l >= a && r <= b) return s[k];
        int mid = (l + r) >> 1, s = 0;
        if(a <= mid) s += query(lc(k), l, mid, a, b);
        if(mid < b)  s += query(rc(k), mid + 1, r, a, b);
        return s;
    }
} tr;

void work()
{
    init();
    int n, m; read(n), read(m);
    tr.build(1, 1, n);
    for(int i = 1, op, l, r, x; i <= m; ++i)
    {
        read(op);
        if(op == 1)
        {
            read(l), read(r), read(x);
            if(x) tr.update(1, 1, n, l, r, x);
            print(tr.query(1, 1, n, l, r), '\n');
        }
        else if(op == 2)
        {
            read(l), read(r);
            print(tr.query(1, 1, n, l, r), '\n');
        }
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


