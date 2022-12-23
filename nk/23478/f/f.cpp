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
char s[M + 5];
int a[M + 5];
int pw[M + 5];
int fa[M + 5];
int cnt[M + 5][10];
int L[M + 5], R[M + 5], C[M + 5];
set<pair<int, int>> st[M + 5];
const int inv9 = 111111112;
int ANS;

void init() {
	pw[0] = 1;
	for(int i = 1; i <= M; ++i) pw[i] = (ll)pw[i - 1] * 10 % mod;
}

void query() {
	print(ANS, '\n');
}

int tofind(int x) {
	if(x == fa[x]) return x;
	return fa[x] = tofind(fa[x]);
}

void Union(int x, int y) {
	x = tofind(x), y = tofind(y);
	if(x != y) {
		fa[x] = y;
		L[y] = min(L[x], L[y]);
		R[y] = max(R[x], R[y]);
		for(int i = 0; i < 10; ++i) cnt[y][i] += cnt[x][i];
	}
}

int gaof = 0;

void gao(int p, int q) { // q -> p
	int pf = tofind(p), qf = tofind(q);
	int pl = L[pf], pr = R[pf], pc = C[pf];	
	int ql = L[qf], qr = R[qf], qc = C[qf];
	st[pc].erase(make_pair(pl, pr));
	if(gaof == 1) st[qc].erase(make_pair(ql, qr));
	int pseat = n - pl + 1, qseat = n - ql + 1;
	for(int i = 9; i >= 0; --i) {
		ANS = (ANS - (ll)(pw[cnt[pf][i]] - 1 + mod) % mod * inv9 % mod * i % mod * pw[pseat -= cnt[pf][i]] % mod + mod) % mod;
		ANS = (ANS - (ll)(pw[cnt[qf][i]] - 1 + mod) % mod * inv9 % mod * i % mod * pw[qseat -= cnt[qf][i]] % mod + mod) % mod;
	}
	Union(q, p);
	int f = tofind(p);
	int l = L[f], r = R[f];
	int seat = n - L[f] + 1;
	for(int i = 9; i >= 0; --i) {
		(ANS += (ll)(pw[cnt[f][i]] - 1 + mod) % mod * inv9 % mod * i % mod * pw[seat -= cnt[f][i]] % mod) %= mod;
	}
	st[pc].insert(make_pair(l, r));
}

void nmsl() {
	cout << "-----------------------------\n";
	for(int i = 1; i <= n; ++i) {
		int fa = tofind(i);
		printf("%d: fa=%d C=%d L=%d R=%d\n", i, fa, C[fa], L[fa], R[fa]);
	}
	for(int i = 1; i <= m; ++i) {
		cout << "i=" << i << "\n";
		for(auto x: st[i]) cout << x.first << " " << x.second << "\n";
		cout << "\n";
	}
}

void update(int x, int y) {
	for(auto [l, r]: st[x]) {
		gaof = 0;
		if(l > 1 && C[tofind(l - 1)] == y) gao(l - 1, l), gaof = 1;
		//nmsl();
		//printf("*********************************************************\n");
		if(r < n && C[tofind(r + 1)] == y) gao(r + 1, r), gaof = 2;
		if(!gaof) {
			C[tofind(l)] = y;
			st[y].insert(make_pair(l, r));
		}
	}
	st[x].clear();
	//nmsl();
}

void work() {
	scan(n), scan(m), scan(k);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i) scan(a[i]), fa[i] = L[i] = R[i] = i, C[i] = a[i], cnt[i][s[i] - '0'] = 1;
	for(int l = 1, r = 0; l <= n; l = r + 1) {
		while(r + 1 <= n && a[l] == a[r + 1]) Union(l, ++r);
		st[a[l]].insert(make_pair(l, r));
		int seat = n - l + 1;
		for(int i = 9; i >= 0; --i) {
			(ANS += (ll)(pw[cnt[r][i]] - 1 + mod) % mod * inv9 % mod * i % mod * pw[seat -= cnt[r][i]] % mod) %= mod;
		}
	}
	query();
	for(int i = 1, x, y; i <= k; ++i) {
		scan(x), scan(y);
		if(x != y) update(x, y);
		query();
	}
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	init();
	int T = 1; //scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

