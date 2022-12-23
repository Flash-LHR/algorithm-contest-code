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
const int M = (int)2e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, a[M + 5], b[M + 5];
int c[4], d[4];
vector<pair<int, int>> v;

ll cal(int i, int j) {
	if(i == 2 && j == 2) return linf;
	if(j == 2) {
		ll ans = linf;
		i = (i == 1 ? 1 : n);
		int p1 = lower_bound(b + 2, b + n, a[i]) - b;
		if(2 <= p1 && p1 < n) ans = min(ans, (ll)abs(a[i] - b[p1]));
		int p2 = lower_bound(b + 2, b + n, a[i]) - b - 1;
		if(2 <= p2 && p2 < n) ans = min(ans, (ll)abs(a[i] - b[p2]));
		return ans;
	} else if(i == 2) {
		ll ans = linf;
		j = (j == 1 ? 1 : n);
		int p1 = lower_bound(a + 2, a + n, b[j]) - a;
		if(2 <= p1 && p1 < n) ans = min(ans, (ll)abs(a[p1] - b[j]));
		int p2 = lower_bound(a + 2, a + n, b[j]) - a - 1;
		if(2 <= p2 && p2 < n) ans = min(ans, (ll)abs(a[p2] - b[j]));
		return ans;
	} else {
		int p1 = (i == 1 ? 1 : n);
		int p2 = (j == 1 ? 1 : n);
		return (ll)abs(a[p1] - b[p2]);
	}
}

void work() {
	scan(n);
	for(int i = 1; i <= n; ++i) scan(a[i]);
	for(int i = 1; i <= n; ++i) scan(b[i]);
	sort(a + 2, a + n); sort(b + 2, b + n);
	ll ans = linf;
	for(int i = 0; i < (1<<v.size()); ++i) {
		bool f[2][4] = {0}; ll cur = 0;
		for(int j = 0; j < (int)v.size(); ++j) if(i>>j&1) {
			f[0][v[j].first] = f[1][v[j].second] = 1;
			cur += cal(v[j].first, v[j].second);
		}
		if(!f[0][1] || !f[0][3] || !f[1][1] || !f[1][3]) continue;
		/*if(cur == 5) {
			for(int j = 0; j < (int)v.size(); ++j) if(i>>j&1) {
				printf("<%d,%d>\n", v[j].first, v[j].second);
			}
		}*/
		ans = min(ans, cur);
	}
	print(ans, '\n');
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	for(int i = 1; i <= 3; ++i) for(int j = 1; j <= 3; ++j) v.push_back(make_pair(i, j));
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

