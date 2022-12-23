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
const int M = (int)3e5;
const int N = (int)1e5;
const ll mod = (ll)998244353;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int f[M + 5][3][9];

void work() {
	int n; scan(n);
	f[0][0][0] = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 3; ++j) {
			for(int k = 0; k < 9; ++k) if(f[i][j][k]) {
				for(int l = 0; l < 10; ++l) {
					if(!(i & 1)) (f[i + 1][(j + l) % 3][k] += f[i][j][k]) %= mod;
					else (f[i + 1][j][(k + l) % 9] += f[i][j][k]) %= mod;
				}
			}
		}
	}
	print(f[n][0][0], '\n');
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

