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
typedef __int128 ll;
typedef unsigned long long ull;

const db eps = 1e-6;
const int M = (int)5e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, a[M + 5];
int m, b[M + 5];
int k, cnt[M + 5];
pair<int, int> pa[M + 5];

int tofind(int x) {
	return lower_bound(b + 1, b + m + 1, x) - b;
}

ll calc(int cx, int cy, int x, int y) {
	return ((ll)cx * cx + (ll)cy * cy) * (x + y);
}

void work() {
	scan(n); k = m = n;
	for(int i = 1; i <= n; ++i) scan(a[i]), b[i] = a[i];
	sort(b + 1, b + m + 1), m = unique(b + 1, b + m + 1) - (b + 1);
	for(int i = 1; i <= n; ++i) ++cnt[tofind(a[i])];
	for(int i = 1, u; i <= n; ++i) {
		u = cnt[tofind(a[i])];
		if(a[i] > pa[u].first) {
			pa[u].second = pa[u].first;
			pa[u].first = a[i];
		} else if(a[i] != pa[u].first && a[i] > pa[u].second) {
			pa[u].second = a[i];
		}
	}
	sort(cnt + 1, cnt + k + 1), k = unique(cnt + 1, cnt + k + 1) - (cnt + 1);
	if(m == 1) {
		printf("-1\n");
		return;
	}
	ll ans = -1;
	for(int i = 1; i <= k; ++i) {
		if(pa[cnt[i]].second) ans = max(ans, calc(cnt[i], cnt[i], pa[cnt[i]].first, pa[cnt[i]].second));
		for(int j = i + 1; j <= k; ++j) {
			ans = max(ans, calc(cnt[i], cnt[j], pa[cnt[i]].first, pa[cnt[j]].first));
		}
	}
	print(ans, '\n');
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

