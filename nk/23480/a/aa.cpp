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

int n, k, w, q;
char s[M + 5];
ll f[M + 5][4];
ll pre[4];
int qu[M + 5][4], ql[4], qr[4];

ll cal(int i, int j, int d) {
	return f[j][d - 1] + w - (ll)abs(k - (i - j)) * q;
}

void nmsl() {
	printf("---------------\n");
	for(int j = 2; j <= 3; ++j) {
		printf("qu[%d]:", j);
		for(int k = ql[j]; k <= qr[j]; ++k) printf(" %d", qu[j][k]);
		printf("\n");
	}
}

void work() {
	scan(n); scanf("%s", s + 1);
	scan(k), scan(w), scan(q);
	memset(f, -0x3f, sizeof f);
	memset(pre, -0x3f, sizeof pre);
	for(int i = 2; i <= 3; ++i) ql[i] = 1, qr[i] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 2; j <= 3; ++j) {
			while(ql[j] <= qr[j] && qu[j][ql[j]] < i - k) ++ql[j];
		}
		if(s[i] == '0') {
			f[i][1] = 0;
			for(int j = 2; j <= 3; ++j) {
				f[i][j] = max(f[i][j], w + pre[j]);
				if(ql[j] <= qr[j]) f[i][j] = max(f[i][j], cal(i, qu[j][ql[j]], j));
			}
		}
		for(int j = 2; j <= 3; ++j) {
			pre[j] -= q;
			if(1 <= i - k) pre[j] = max(pre[j], f[i - k][j - 1] - q);
			while(ql[j] <= qr[j] && cal(i, qu[j][qr[j]], j) <= cal(i, i, j)) --qr[j];
			qu[j][++qr[j]] = i;
		}
	}
	ll mx = 0;
	for(int i = 1; i <= n; ++i) mx = max({mx, f[i][1], f[i][2], f[i][3]});
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

