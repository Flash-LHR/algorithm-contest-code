#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T& x) {
	x = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
	x *= f;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch) {
	print(x), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const db eps = 1e-6;
const int M = (int)1e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

ll quick(ll a, ll b, ll p = mod)
{
    ll s = 1;
    while(b)
    {
        if(b & 1) s = s * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return s % p;
}

ll inv(ll n, ll p = mod)
{
    return quick(n, p - 2, p);
}

int n, q;
char s[M + 5];

struct segT {
    int mx[M * 4 + 5];
    int w[M * 4 + 5][11];

    int lc(int k) {return k<<1;}
    int rc(int k) {return k<<1|1;}

    void push_up(int k) {
        mx[k] = max(mx[lc(k)], mx[rc(k)]);
        for(int i = 2; i <= 10; ++i) w[k][i] = (w[lc(k)][i] + w[rc(k)][i]) % mod;
    }

    void nmsl() {
        printf("-----------------------\n");
        for(int i = 1; i <= 9; ++i) {
            printf("%d: mx=%d w4=%d\n", i, mx[i], w[i][4]);
        }
        printf("---------------------\n");
    }

    void build(int k, int l, int r) {
        if(l == r) {
            mx[k] = s[l] - '0';
            for(int i = 2; i <= 10; ++i) w[k][i] = (ll)mx[k] * quick(i, n - l) % mod;
            return;
        }
        int mid = (l + r) >> 1;
        build(lc(k), l, mid);
        build(rc(k), mid + 1, r);
        push_up(k);
    }

    void update(int k, int l, int r, int a, int b) {
        if(l == r) {
            mx[k] = b;
            for(int i = 2; i <= 10; ++i) w[k][i] = (ll)mx[k] * quick(i, n - l) % mod;
            return;
        }
        int mid = (l + r) >> 1;
        if(a <= mid) update(lc(k), l, mid, a, b);
        else update(rc(k), mid + 1, r, a, b);
        push_up(k);
    }

    int queryMx(int k, int l, int r, int a, int b) {
        if(l >= a && r <= b) return mx[k];
        int mid = (l + r) >>1, mx = 0;
        if(a <= mid) mx = max(mx, queryMx(lc(k), l, mid, a, b));
        if(mid < b)  mx = max(mx, queryMx(rc(k), mid + 1, r, a, b));
        return mx;
    }

    int query(int k, int l, int r, int a, int b, int c) {
        if(l >= a && r <= b) return w[k][c];
        int mid = (l + r) >>1, sum = 0;
        if(a <= mid) (sum += query(lc(k), l, mid, a, b, c)) %= mod;
        if(mid < b)  (sum += query(rc(k), mid + 1, r, a, b, c)) %= mod;
        return sum;
    }
} tr;

/**

5 5
56789
1 3 3
1 1 8
2 2 5
2 5 5
2 1 1

6389
9
8
**/

void work() {
    scan(n), scan(q);
    scanf("%s", s + 1);
    tr.build(1, 1, n);
    for(int i = 1, op, x, y; i <= q; ++i) {
        scan(op), scan(x), scan(y);
        if(op == 1) tr.update(1, 1, n, x, y);
        else {
            int bs = max(2, tr.queryMx(1, 1, n, x, y) + 1);
            int pro = tr.query(1, 1, n, x, y, bs);
            int ans = (ll)pro * inv(quick(bs, n - y)) % mod;
            print(ans, '\n');
        }
    }
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; //scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}
