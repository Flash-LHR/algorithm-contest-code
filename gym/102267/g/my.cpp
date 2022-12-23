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

int n;

struct segT
{
    ll a[M * 4 + 5], b[M * 4 + 5], c[M * 4 + 5], lz[M * 4 + 5];
    ll ori[M * 4 + 5];

    inline int lc(int k) {return k<<1;}
    inline int rc(int k) {return k<<1|1;}

    inline void push_up(int k)
    {
        int l = lc(k), r = rc(k);
        a[k] = a[l] + a[r];
        b[k] = min(b[l], b[r]);
        c[k] = c[l] + c[r];
    }

    inline void push_down(int k)
    {
        if(!lz[k]) return;
        int l = lc(k), r = rc(k);
        b[l] += lz[k], lz[l] += lz[k];
        b[r] += lz[k], lz[r] += lz[k];
        lz[k] = 0;
    }

    vector<int> die;

    int queryPos(int k, int l, int r, ll x)
    {
        if(l == r) return l;
        push_down(k);
        int mid = (l + r) >> 1, pos;
        if(a[lc(k)] + ori[mid + 1] <= x) pos = queryPos(rc(k), mid + 1, r, x - a[lc(k)]);
        else                             pos = queryPos(lc(k), l, mid, x);
        push_up(k);
        return pos;
    }

    int queryAlv(int k, int l, int r, int a, int b)
    {
        if(l >= a && r <= b) return c[k];
        push_down(k);
        int mid = (l + r) >> 1, s = 0;
        if(a <= mid) s += queryAlv(lc(k), l, mid, a, b);
        if(mid < b)  s += queryAlv(rc(k), mid + 1, r, a, b);
        push_up(k);
        return s;
    }

    ll querySum(int k, int l, int r, int x, int y)
    {
        if(l >= x && r <= y) return a[k];
        push_down(k);
        int mid = (l + r) >> 1; ll s = 0;
        if(x <= mid) s += querySum(lc(k), l, mid, x, y);
        if(mid < y)  s += querySum(rc(k), mid + 1, r, x, y);
        push_up(k);
        return s;
    }

    void queryDie(int k, int l, int r, int x, int y, ll z)
    {
        if(b[k] > z) return;
        if(l == r)
        {
            die.push_back(l);
            a[k] = 0, b[k] = (ll)2e18, c[k] = 0;
            return;
        }
        push_down(k);
        int mid = (l + r) >> 1;
        if(x <= mid && b[lc(k)] <= z) queryDie(lc(k), l, mid, x, y, z);
        if(mid < y  && b[rc(k)] <= z) queryDie(rc(k), mid + 1, r, x, y, z);
        push_up(k);
    }

    void add(int k, int l, int r, int x, int y, ll z)
    {
        if(l >= x && r <= y) return b[k] += z, lz[k] += z, void();
        push_down(k);
        int mid = (l + r) >> 1;
        if(x <= mid) add(lc(k), l, mid, x, y, z);
        if(mid < y)  add(rc(k), mid + 1, r, x, y, z);
        push_up(k);
    }

    void query(ll x)
    {
        int pos = (ori[1] > x ? 0 : queryPos(1, 1, n, x));
        int hug = (pos == n ? 0 : queryAlv(1, 1, n, pos + 1, n));
        die.clear();
        if(pos) queryDie(1, 1, n, 1, pos, x);
        int len = (int)die.size();
        printf("%d %d\n", len, hug);
        for(const int& p: die)
        {
            if(p < n) add(1, 1, n, p + 1, n, -ori[p]);
            ori[p] = 0;
        }
    }

    void update(int k, int l, int r, int p, ll aa, ll bb)
    {
        if(l == r)
        {
            ori[l] = a[k] = aa, b[k] = bb, c[k] = 1;
            return;
        }
        push_down(k);
        int mid = (l + r) >> 1;
        if(p <= mid) update(lc(k), l, mid, p, aa, bb);
        else         update(rc(k), mid + 1, r, p, aa, bb);
        push_up(k);
    } 

    void update(ll a, ll b, int c)
    {
        ll s = (c == 1 ? 0 : querySum(1, 1, n, 1, c - 1));
        add(1, 1, n, c + 1, n, a - ori[c]);
        update(1, 1, n, c, a, s + a + b + 1);
    }
} tr;

void work()
{
    read(n); ll a, b, x, s = 0;
    for(int i = 1; i <= n; ++i)
    {
        read(a), read(b);
        s += a;
        tr.update(1, 1, n, i, a, b + s + 1);
    }
    int q; read(q);
    for(int i = 1, op, c; i <= q; ++i)
    {
        read(op);
        if(op == 1)
        {
            read(x);
            tr.query(x);
        }
        else if(op == 2)
        {
            read(a), read(b), read(c);
            tr.update(a, b, c);
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


