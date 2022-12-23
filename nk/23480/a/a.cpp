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
const int M = (int)1e6;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n;
char s[M + 5];
int k, w, q;
ll f[M + 5][4];

struct segT {
	ll mx[M * 4 + 5], lz[M * 4 + 5];
	
	int lc(int k) {return k<<1;}
	int rc(int k) {return k<<1|1;}

	void push_up(int k) {
		mx[k] = max(mx[lc(k)], mx[rc(k)]);
	}

	void push_down(int k) {
		if(!lz[k]) return;
		mx[lc(k)] += lz[k], mx[rc(k)] += lz[k];
		lz[lc(k)] += lz[k], lz[rc(k)] += lz[k];
		lz[k] = 0;
	}

	void build(int k, int l, int r) {
		lz[k] = 0;
		if(l == r) return mx[k] = w + (ll)(-::k - l + 1) * q, void();
		int mid = (l + r) >> 1;
		build(lc(k), l, mid);
		build(rc(k), mid + 1, r);
		push_up(k);
	}

	void add(int k, int l, int r, int a, int b, ll c) {
		if(l >= a && r <= b) {
			mx[k] += c;
			lz[k] += c;
			return;
		}
		push_down(k);
		int mid = (l + r) >> 1;
		if(a <= mid) add(lc(k), l, mid, a, b, c);
		if(mid < b)  add(rc(k), mid + 1, r, a, b, c);
		push_up(k);
	}

	ll query(int k, int l, int r, int a, int b) {
		if(l >= a && r <= b) return mx[k];
		push_down(k);
		int mid = (l + r) >> 1; ll mx = -linf;
		if(a <= mid) mx = max(mx, query(lc(k), l, mid, a, b));
		if(mid < b)  mx = max(mx, query(rc(k), mid + 1, r, a, b));
		push_up(k);
		return mx;
	}
} tr[4];

void nmsl() {
	printf("---------------------\n");
	for(int i = 1; i <= 3; ++i) {
		printf("tr[%d]:", i);
		for(int j = 1; j <= 9; ++j) printf("\t%d: mx=%lld lz=%lld\n", j, tr[i].mx[j], tr[i].lz[j]);
	}
	printf("------------------------\n");
}

void work() {
	scan(n);
	scanf("%s", s + 1);
	scan(k), scan(w), scan(q);
	tr[1].build(1, 1, n);
	tr[2].build(1, 1, n);
	tr[3].build(1, 1, n);
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '0') {
			if(i >= 1) f[i][1] = 0; else f[i][1] = -linf;
			if(i >= 2) f[i][2] = tr[1].query(1, 1, n, 1, i - 1); else f[i][2] = -linf;
			if(i >= 3) f[i][3] = tr[2].query(1, 1, n, 1, i - 1); else f[i][3] = -linf;
		} else f[i][1] = f[i][2] = f[i][3] = -linf;
		for(int j = 1; j <= 2; ++j) {
			if(1 <= i - k) tr[j].add(1, 1, n, 1, i - k, -q);
			tr[j].add(1, 1, n, max(1, i - k + 1), n, q);
			tr[j].add(1, 1, n, i, i, f[i][j]);
		}
	}
	ll mx = 0;
	for(int i = 1; i <= n; ++i) {
		if(i >= 1) mx = max(mx, f[i][1]);
		if(i >= 2) mx = max(mx, f[i][2]);
		if(i >= 3) mx = max(mx, f[i][3]);
	}
	print(mx, '\n');
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

