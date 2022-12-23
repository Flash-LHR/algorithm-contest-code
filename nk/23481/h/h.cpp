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

int n;
char s[20];
int f[M + 5];
int pw[10];

int dfs(int u) {
	//printf("u=%d\n", u);
	if(~f[u]) return f[u];
	int a[10] = {};
	int tmp = u;
	for(int i = 0; i < n; ++i) {
		a[i] = tmp % 3;
		tmp /= 3;
	}
	/*printf("a:");
	for(int i = 0; i < n; ++i) printf("%d,", a[i]);
	printf("\n");*/
	unordered_set<int> st;
	for(int j = 1; j < n; ++j) {
		if(a[j] != 2) continue;
		for(int i = 0; i < j; ++i) {
			int v = u - a[j] * pw[j] - a[i] * pw[i];
			v += 1 * pw[j];
			//printf("u=%d i=%d j=%d v=%d-%d*%d-%d*%d,v=%d\n", u, i, j,u, a[j], pw[j], a[i], pw[i], v);
			if(a[i] == 1) v += 2 * pw[i];
			else if(a[i] == 2) v += 1 * pw[i];
			else assert(0);
			st.insert(dfs(v));
		}
	}
	if(a[0] == 2) {
		int v = u - a[0] * pw[0];
		v += 1 * pw[0];
		st.insert(dfs(v));
	}
	for(int i = 0; ; ++i) if(!st.count(i)) return f[u] = i;
}

void work() {
	scan(n);
	scanf("%s", s);
	int u = 0;
	for(int i = n - 1; i >= 0; --i) u = u * 3 + (s[i] == 'b' ? 1 : 2);
	puts(dfs(u) ? "Yes" : "No");
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	pw[0] = 1;
	for(int i = 1; i < 10; ++i) pw[i] = pw[i - 1] * 3;
	memset(f, -1, sizeof f);
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

