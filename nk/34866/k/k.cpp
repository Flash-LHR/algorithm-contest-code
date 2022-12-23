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
const int N = (int)5e2 + 10;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n;
int x[M + 5], y[M + 5];
bool vis[N + 5][N + 5];
bool is[N + 5][N + 5];

void work() {
	scan(n);
	for(int i = 1; i <= n; ++i) {
		scan(x[i]), scan(y[i]);
		is[x[i]][y[i]] = 1;
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) if(!vis[x[i]][y[i]]) {
		int len = 1;
		vis[x[i]][y[i]] = 1;
		int curx = x[i] + 1, cury = y[i] + 1;
		while(curx <= N && cury <= N && is[curx][cury] && !vis[curx][cury]) {
			++len;
			vis[curx][cury] = 1;
			++curx, ++cury;
		}
		curx = x[i] - 1, cury = y[i] - 1;
		while(curx >= 1 && cury >= 1 && is[curx][cury] && !vis[curx][cury]) {
			++len;
			vis[curx][cury] = 1;
			--curx, --cury;
		}
		ans += 2ll * len * (len + 1) / 2;
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

