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

int n, k;
int a[M + 5];
int b[M + 5];
vector<pair<int, int>> ans;

void work() {
	scan(n), scan(k);
	auto cal = [](ll x) {
		int c = 0;
		while(x > 1) ++c, x >>= 1;
		return c;
	};
	for(int i = 1; i <= n; ++i) {
		ll x; scan(x);
		a[i] = cal(x);
		b[i] = a[i] - a[i - 1];
	}
	/*for(int i = 1; i <= n; ++i) printf("%d ", a[i]); printf("\n");
	for(int i = 1; i <= n; ++i) printf("%d ", b[i]); printf("\n");*/
	ans.clear();
	for(int i = 1, j = 1; i <= n; ++i) if(b[i]) {
		if(b[i] < 0 || i + k - 1 > n) return print(-1, '\n'), void();
		while(b[i]) {
			while(j <= n && b[j] >= 0) ++j;
			if(j - i < k) return print(-1, '\n'), void();
			if(j == n + 1) {
				while(b[i]) ans.push_back(make_pair(i, n)), --b[i];
			} else {
				int mi = min(b[i], -b[j]);
				while(mi--) ans.push_back(make_pair(i, j - 1)), --b[i], ++b[j];
			}
		}
	}
	int m = (int)ans.size();
	print(m, '\n');
	for(int i = 0; i < m; ++i) print(ans[i].first, ' '), print(ans[i].second, '\n');
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

