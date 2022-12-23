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

void dfs(int n, vector<int> v) {
	if(n == 0) {
		printf("%d\n", v[0]);
		return;
	}
	vector<int> vv(1<<(n-1));
	for(int i = 0; i < (1<<(n-1)); ++i) {
		if((v[i<<1] + v[i<<1|1]) % 2 == 1) vv[i] = min(v[i<<1], v[i<<1|1]);
		else vv[i] = max(v[i<<1], v[i<<1|1]);
	}
	dfs(n - 1, vv);
}

void work() {
	int n; scan(n);
	print((1<<n)-1, '\n');
	return;
	vector<int> v(1<<n);
	for(int i = 0; i < (1<<n); ++i) v[i] = i + 1;
	dfs(n, v);
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

