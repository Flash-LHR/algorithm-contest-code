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
const int M = (int)1e3;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m, q;
int tr[M + 5][M + 5];

int lowbit(int n) {
	return n&-n;
}

void update(int x, int y) {
	for(int i = x; i <= n; i += lowbit(i)) {
		for(int j = y; j <= m; j += lowbit(j)) {
			tr[i][j] ^= 1;
		}
	}
}

int query(int x, int y) {
	int ans = 0;
	for(int i = x; i >= 1; i -= lowbit(i)) {
		for(int j = y; j >= 1; j -= lowbit(j)) {
			ans ^= tr[i][j];
		}
	}
	return ans;
}

void work() {
	scan(n), scan(m), scan(q);
	for(int i = 1, op, x1, y1, x2, y2; i <= q; ++i) {
		scan(op), scan(x1), scan(y1), scan(x2), scan(y2);
		if(op == 1) {
			update(x1, y1);
			update(x1, y2 + 1);
			update(x2 + 1, y1);
			update(x2 + 1, y2 + 1);
			printf("-----------\n");
			for(int j = 1; j <= n; ++j) for(int k = 1; k <= m; ++k) {
				printf("%d %d: %d\n", j, k, query(j, k));
			}
			printf("-----------\n");
		} else {
			int ans = 0;
			ans ^= query(x2, y2);
			ans ^= query(x2, y1 - 1);
			ans ^= query(x1 - 1, y2);
			ans ^= query(x1 - 1, y1 - 1);
			print(ans, '\n');
		}
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

