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
const int M = (int)1e6;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int randint(int l, int r) {
	return rand() % (r - l + 1) + l;
}

int p[M + 5];

void work() {
	int n = randint((int)1e6, (int)1e6);
	int m = randint((int)1e5, (int)1e5);
	printf("%d %d\n", n, m);
	for(int i = 1; i <= n; ++i) print(randint(1, (int)1e9), i == n ? '\n' : ' ');
	iota(p + 1, p + n + 1, 1);
	random_shuffle(p + 1, p + n + 1);
	for(int i = 2; i <= n; ++i) {
		printf("%d %d\n", p[randint(1, i - 1)], p[i]);
	}
	for(int i = 1, x, y; i <= m; ++i) {
		x = randint(1, n), y = randint(1, n);
		printf("%d %d\n", x, y);
	}
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	srand(time(NULL));
	int T = 1; //scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

