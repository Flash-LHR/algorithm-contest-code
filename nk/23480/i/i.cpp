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

int n, q;
int a[M + 5];
ll sum[M + 5];

void work() {
	scan(n), scan(q);
	for(int i = 1, pre, t; i <= n; ++i) {
		scan(t);
		if(i > 1) a[i - 1] = t - pre;
		pre = t;
	}
	int m = n - 1;
	sort(a + 1, a + m + 1);
	for(int i = 1; i <= m; ++i) sum[i] = sum[i - 1] + a[i];
	for(int i = 1, k, p; i <= q; ++i) {
		scan(k), scan(p);
		int pos = lower_bound(a + 1, a + m + 1, k) - a;
		if(sum[m] - sum[pos - 1] - (ll)(m - pos + 1) * k >= p) puts("Yes");
		else puts("No");
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

