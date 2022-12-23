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
const ll mod = (ll)998244353;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n;
int a[M + 5];
int pw[M + 5];
int l[M + 5], r[M + 5];

void work() {
	scan(n);
	pw[0] = 1;
	for(int i = 1; i <= n; ++i) scan(a[i]), pw[i] = pw[i - 1] * 2 % mod;	
	l[1] = 1; for(int i = 2; i <= n; ++i) l[i] = (a[i - 1] == a[i] ? l[i - 1] : i);
	r[n] = n; for(int i = n - 1; i; --i)  r[i] = (a[i] == a[i + 1] ? r[i + 1] : i);
	int ans = 1;
	for(int i = 1; i <= n; i = r[i] + 1) {
		if(i == 1 || r[i] == n ||
		   (a[i - 1] < a[i] && a[r[i]] > a[r[i] + 1]) ||
		   (a[i - 1] > a[i] && a[r[i]] < a[r[i] + 1])) {
			ans = (ll)ans * ((pw[r[i] - i + 1] - 1 + mod) % mod) % mod;
		}
		else ans = (ll)ans * pw[r[i] - i + 1] % mod;
	}
	print(ans, '\n');
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


