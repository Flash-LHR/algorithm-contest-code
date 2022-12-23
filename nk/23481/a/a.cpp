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
const int N = (int)1;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m;
int a[M + 5], b[M + 5];
int d[M + 5];

struct Hash {
	int mod[N] = {(ll)1e9 + 7};
	int p[M + 5][N], h[M + 5][N];

	void init(int n, int a[]) {
		p[0][0] = 1;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < N; ++j) {
				p[i][j] = (ll)p[i - 1][j] * 131 % mod[j];
				h[i][j] = ((ll)h[i - 1][j] * 131 % mod[j] + a[i]) % mod[j];
			}
		}
	}
	
	int getH(int l, int r) {
		return ((h[r][0] - (ll)h[l - 1][0] * p[r - l + 1][0] % mod[0] + mod[0]) % mod[0]);
	}

} h[2];

bool equ(int l1, int r1, int l2, int r2) {
	return h[0].getH(l1, r1) == h[1].getH(l2, r2);
}

int cal(int p) {
	int l = 0, r = p, mid;
	while(l < r) {
		mid = (l + r + 1) >> 1;
		if(equ(p - mid + 1, p, n - mid + 1, n)) l = mid;
		else r = mid - 1;
	}
	return r;
}

void work() {
	scan(n); m = n;
	for(int i = 1; i <= n; ++i) scan(a[i]), b[i] = a[i];
	sort(b + 1, b + m + 1); m = unique(b + 1, b + m + 1) - (b + 1);
	for(int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
	h[0].init(n, a); reverse(a + 1, a + n + 1);
	h[1].init(n, a); //reverse(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		int j = cal(i);
		if(j) ++d[1], --d[j + 1];
	}
	for(int i = 1; i <= n; ++i) print(d[i] += d[i - 1], i == n ? '\n' : ' ');
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



