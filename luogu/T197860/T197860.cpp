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
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n;
int a[M + 5];
int f[2][10];
int len[2];

void work() {
	scan(n);
	for(int i = 1; i <= n; ++i) scan(a[i]);
	ll ans = 0;
	for(int l = 1; l <= n; ++l) {
		f[0][len[0] = 1] = a[l];
		f[1][len[1] = 1] = -a[l];
		for(int r = l + 1; r <= n; ++r) {
			if(a[r] >= f[0][len[0]]) f[0][++len[0]] = a[r];
			else f[0][upper_bound(f[0] + 1, f[0] + len[0] + 1, a[r]) - f[0]] = a[r];
			if(-a[r] >= f[1][len[1]]) f[1][++len[1]] = -a[r];
			else f[1][upper_bound(f[1] + 1, f[1] + len[1] + 1, -a[r]) - f[1]] = -a[r];
			if(max(len[0], len[1]) == 3) {
				ans += n - r + 1;
				break;
			}
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

