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
const int N = (int)320;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m, block;
ll a[M + 5];
int id[M + 5];
ll sum[N + 5];
set<pair<
int L[N + 5], R[N + 5];

void parse() {
	block = (int)sqrt(n);
	for(int i = 1; i <= n; ++i) id[i] = (i - 1) / block + 1;
	for(int l = 1, r = 0; l <= n; l = r + 1) {
		while(r + 1 <= n && id[l] == id[r + 1]) ++r;
		L[id[l]] = l, R[id[l]] = r;
	}
}

void work() {
	scan(n), scan(m);
	parse();
	for(int i = 1, op, x, y, len, l, r; i <= m; ++i) {
		scan(op);
		if(op == 1) {
			scan(x), scan(y);
			a[x] += y, sum[id[x]] += y;
		} else if(op == 2) {
			scan(x), scan(y), scan(len);

		} else if(op == 3) {
			scan(l), scan(r);
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

