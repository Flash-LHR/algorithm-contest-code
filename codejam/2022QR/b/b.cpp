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

int a[4];

void work() {
	memset(a, inf, sizeof a);
	for(int i = 0; i < 3; ++i) {
		for(int j = 0, x; j < 4; ++j) {
			scan(x);
			a[j] = min(a[j], x);
		}
	}
	if(accumulate(a, a + 4, 0) < 1e6) return puts("IMPOSSIBLE"), void();
	else {
		int s = 1e6;
		for(int i = 0; i < 4; ++i) {
			if(a[i] <= s) print(a[i], " \n"[i == 3]), s -= a[i];
			else print(s, " \n"[i == 3]), s = 0;
		}
	}
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		printf("Case #%d: ", ca);
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

