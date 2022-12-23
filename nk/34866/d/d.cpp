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
const int M = (int)5e5;
const int N = (int)19;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n; ll k;
int a[M + 5];
int mx[M + 5][N];
int mi[M + 5][N];
int lg[M + 5];

int getMx(int l, int r) {
	int k = lg[r - l + 1];
	return max(mx[l][k], mx[r - (1<<k) + 1][k]);
}

int getMi(int l, int r) {
	int k = lg[r - l + 1];
	return min(mi[l][k], mi[r - (1<<k) + 1][k]);
}

ll f(int l, int r) {
	return (ll)(getMx(l, r) - getMi(l, r)) * (r - l + 1);
}

ll check(ll mid) {
	ll ans = 0;
	for(int l = 1, r = 0; l <= n; ++l) {
		while(r + 1 <= n && f(l, r) <= mid) ++r;
		if(f(l, r) > mid) ans += n - r + 1;
	}
	return ans;
}

void work() {
	scan(n), scan(k);
	memset(mx, -inf, sizeof mx);
	memset(mi, inf, sizeof mi);
	for(int i = 1; i <= n; ++i) {
		scan(a[i]);
		mx[i][0] = mi[i][0] = a[i];
	}
	for(int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
	for(int j = 1; j < N; ++j) {
		for(int i = 1; i + (1<<j) - 1 <= n; ++i) {
			mx[i][j] = max(mx[i][j - 1], mx[i + (1<<(j-1))][j - 1]);
			mi[i][j] = min(mi[i][j - 1], mi[i + (1<<(j-1))][j - 1]);
		}
	}
	ll l = 0, r = (ll)1e15, mid;
	while(l < r) {
		mid = (l + r) >> 1;
		if(check(mid) > k - 1) l = mid + 1;
		else r = mid;
		//printf("l=%lld mid=%lld r=%lld\n", l, mid, r);
	}
	print(r, '\n');
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

