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

int n, m;
int a[M + 5];
int f[M + 5];
int back[M + 5];
int b[M + 5];

void work() {
	scan(m); n = 0;
	for(int i = 1; i <= m; ++i) scan(a[i]);
	f[0] = 1;
	for(int i = 1; i <= m; ++i) {
		b[2 * i] = (a[i] - f[i] + mod) % mod;
		n += b[2 * i];
		for(int j = 1; j <= b[2 * i]; ++j) {
			for(int k = m; k >= 0; --k) {
				if(k >= 2 * i) (f[k] += f[k - 2 * i]) %= mod;
				if(k >= i) (f[k] += f[k - i]) %= mod;
			}
		}
	}
	print(n, '\n');
	for(int i = 1; i <= 2 * m; ++i) {
		for(int j = 1; j <= b[2 * i]; ++j) print(2 * i, ' ');
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

