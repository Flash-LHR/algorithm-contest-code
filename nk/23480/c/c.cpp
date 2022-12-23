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
const int M = (int)21;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, k, s;
int p[M];
int a[M][4];
struct node {
	int score, cnt;
} f[1<<M][M];

void gao(node& cur, const node& pre, int u, bool f, int tar) {
	int mx = max(a[u][0], a[u][1]);
	if(f) mx = max({mx, a[u][2], a[u][3]});
	node now;
	now.score = pre.score + mx;
	now.cnt = pre.cnt + (now.score >= tar);
	if(now.cnt > cur.cnt || (now.cnt == cur.cnt && now.score > cur.score)) cur = now;
}

void work() {
	scan(n), scan(k), scan(s);
	for(int i = 0; i < n; ++i) scan(p[i]);
	for(int i = 0; i < n; ++i) for(int j = 0; j < 4; ++j) scan(a[i][j]);
	for(int i = 0; i < (1<<n); ++i) {
		for(int j = 0; j < k; ++j) {
			f[i][j].score = f[i][j].cnt = -inf;
		}
	}
	f[0][0].score = s, f[0][0].cnt = 0;
	for(int i = 0; i < (1<<n); ++i) {
		int tar = p[__builtin_popcount(i)];
		for(int j = 0; j < n; ++j) if(!(i>>j&1)) {
			for(int l = 0; l <= k; ++l) {
				if(f[i][l].score < 0) continue;
				gao(f[i|(1<<j)][l], f[i][l], j, 0, tar);
				if(l < k) gao(f[i|(1<<j)][l + 1], f[i][l], j, 1, tar);
			}
		}
	}
	/*for(int i = 0; i < (1<<n); ++i) {
		for(int j = 0; j <= k; ++j) {
			if(f[i][j].score >= 0) printf("i=%d j=%d score=%d cnt=%d\n", i, j, f[i][j].score, f[i][j].cnt);
		}
		printf("\n");
	}*/
	int mx = 0;
	for(int i = 0; i <= k; ++i) mx = max(mx, f[(1<<n)-1][i].cnt);
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

