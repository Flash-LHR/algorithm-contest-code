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
int cnt[10] = {0};
int pw[M + 5];
int inv9 = 111111112;

void init() {
	pw[0] = 1;
	for(int i = 1; i <= M; ++i) pw[i] = (ll)pw[i - 1] * 10 % mod;
}

void query() {
	int ans = 0;
	for(int l = 1, r = 0; l <= n; l = r + 1) {
		memset(cnt, 0, sizeof cnt);
		while(r + 1 <= n && a[l] == a[r + 1]) ++cnt[s[++r] - '0'];
		for(int i = 9; i >= 0; --i) {
			ans = (ll)ans * pw[cnt[i]] % mod;
			(ans += (ll)(pw[cnt[i]] - 1 + mod) % mod * inv9 % mod * i % mod) %= mod;
		}
	}
	print(ans, '\n');
}

void update(int x, int y) {
	for(int i = 1; i <= n; ++i) if(a[i] == x) a[i] = y;
}

void work() {
	scan(n), scan(m), scan(k);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i) scan(a[i]);
	query();
	for(int i = 1, x, y; i <= k; ++i) {
		scan(x), scan(y);
		update(x, y);
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

