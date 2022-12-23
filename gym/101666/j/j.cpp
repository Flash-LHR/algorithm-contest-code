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

struct segT
{
    int n; ll s[M * 4 + 5], lz[M * 4 + 5];
    void init(int n)
    {
        this->n = n + 1;
        memset(s, 0, sizeof s);
        memset(lz, 0, sizeof lz);
    }

    int lc(int k) {return k<<1;}
    int rc(int k) {return k<<1|1;}

    void push_down(int k)
    {
        int l = lc(k), r = rc(k);
        lz[l] += lz[k], lz[r] += lz[k];
        s[l] += lz[k], s[r] += lz[k];
        lz[k] = 0;
    }

    void add(int k, int l, int r, int a, int b, ll c)
    {
        if(l >= a && r <= b) return lz[k] += c, s[k] += c, void();
        if(lz[k]) push_down(k);
        int mid = (l + r) >> 1;
        if(a <= mid) add(lc(k), l, mid, a, b, c);
        if(mid < b) add(rc(k), mid + 1, r, a, b, c);
    }

    void add(int l, int r, ll c)
    {
        add(1, 1, n, l + 1, r + 1, c);
    }

    ll ask(int k, int l, int r, int a)
    {
        if(l == r) return s[k];
        if(lz[k]) push_down(k);
        int mid = (l + r) >> 1;
        if(a <= mid) return ask(lc(k), l, mid, a);
        else return ask(rc(k), mid + 1, r, a);
    }

    ll ask(int a)
    {
        return ask(1, 1, n, a + 1);
    }
} tr[2];

vector<tuple<int, int, int>> seg[2];

void init()
{
    int l[2] = {0, 0};
    for(int i = 1, r = 0, u; r <= 2 * M; ++i)
    {
        r += i, u = (r&1);
        seg[u].push_back(make_tuple(l[u] + 1, r, i));
        l[u] = r;
    }
    /*printf("nmsl: 0\n");
    for(const auto& t: seg[0]) printf("l=%d r=%d d=%d\n", get<0>(t), get<1>(t), get<2>(t));
    printf("nmsl: 1\n");
    for(const auto& t: seg[1]) printf("l=%d r=%d d=%d\n", get<0>(t), get<1>(t), get<2>(t));
    */
}

void add(int a, int f)
{
    for(int i = 0; i < 2; ++i)
    {
        //printf("i=%d\n", i);
        for(const auto& t: seg[i])
        {
            int l = get<0>(t), r = get<1>(t), d = get<2>(t);
            int ll = a + l, rr = a + r;
            if(rr >= 0 && ll <= M)
            {
                ll = max(0, ll), rr = min(rr, M);
                //printf("ll=%d rr=%d\n", ll, rr);
                tr[i].add(ll, rr, f * d);
            }
            ll = a - r, rr = a - l;
            if(rr >= 0 && ll <= M)
            {
                ll = max(0, ll), rr = min(rr, M);
                //printf("ll=%d rr=%d\n", ll, rr);
                tr[i].add(ll, rr, f * d);
            }
        }
    }
}

/*
1 1
10
1
t 0
*/

void work()
{
    tr[0].init(M), tr[1].init(M), init();
    int n, t; read(n), read(t);
    for(int i = 1, a; i <= n; ++i) read(a), add(a, 1);
    int q; read(q); char op;
    for(int i = 1, a; i <= q; ++i)
    {
        op = getchar(), read(a);
        //printf("op=%c a=%d\n", op, a);
        if(op == '+')      add(a, 1);
        else if(op == '-') add(a, -1);
        else if(op == 't') t = a;
        print(tr[t&1].ask(t), '\n');
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


