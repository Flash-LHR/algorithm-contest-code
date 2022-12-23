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
const int M = (int)1e2;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m;
char s[M + 5][M + 5];

void work() {
	scan(n), scan(m);
	for(int i = 1; i <= 2 * n + 1; ++i) {
		char ch1, ch2;
		(i & 1) ? (ch1 = '+', ch2 = '-') : (ch1 = '|', ch2 = '.');
		for(int j = 1; j <= 2 * m + 1; ++j) s[i][j] = (j & 1) ? ch1 : ch2;
		s[i][2 * m + 2] = '\0';
	}
	s[1][1] = s[1][2] = s[2][1] = '.';
	for(int i = 1; i <= 2 * n + 1; ++i) printf("%s\n", s[i] + 1);
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		printf("Case #%d:\n", ca);
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

