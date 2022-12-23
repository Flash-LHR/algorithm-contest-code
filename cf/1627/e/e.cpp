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

int n, m, k;
int x[M + 5];
struct node {
	int a, b, c, d, h;
	bool operator<(const node& y) const {
		if(a != y.a) return a < y.a;
		return b < y.b;
	}
} s[M + 5];

map<pair<int, int>, ll> f;
int st[M + 5], tp;

void update(int l, int r) {
	tp = 0;
	for(int i = l; i <= r; ++i) {
		if(tp) f[make_pair(s[i].a, )]
	}
}

void work() {
	f.clear();
	scan(n), scan(m), scan(k);
	for(int i = 1; i <= n; ++i) scan(x[i]);
	for(int i = 1; i <= k; ++i) scan(s[i].a), scan(s[i].b), s[i].f = 1, scan(s[i].c), scan(s[i].d), scan(s[i].h);
	s[0].a = 1, s[0].b = 1, s[k + 1].a = n, s[k + 1].b = m; ++k;
	sort(s, s + k + 1);
	for(int i = 0; i <= k; ++i) {
		f[make_pair(s[i].a, s[i].b)] = linf;
		if(0 < i && i < k) f[make_pair(s[i].c, s[i].d)] = linf;
	}
	f[make_pair(1, 1)] = 0;
	for(int l = 0, r = -1; l <= k; l = r + 1) {
		while(r + 1 <= k && s[l].a == s[r + 1].a) ++r;
		update(l, r);
		for(int i = l; i <= r; ++i) if(0 < i && i < k) f[make_pair(s[i].c, s[i].d)] = f[make_pair(s[i].a, s[i].b)] - s[i].h;
	}
	if(f[make_pair(n, m)] > linf / 2) print(-1, '\n');
	else print(f[make_pair(n, m)], '\n');
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

