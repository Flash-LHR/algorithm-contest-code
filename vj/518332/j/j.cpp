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
const int M = (int)3e2;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n;
int a[M + 5][M + 5];

bool check(int x, int y, int l, int &cur)
{
	static int b[4];
	b[0] = a[x][y];
	b[1] = a[x][y + l];
	b[2] = a[x + l][y];
	b[3] = a[x + l][y + l];
	sort(b, b + 4);
	if(b[0] == b[1] && b[1] == b[2] && b[2] < b[3]) {
		cur = b[0];
		return true;
	}
	return false;
}

void work() {
	scan(n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) scan(a[i][j]);
	int mx = -1, cur = -1;
	for(int i = 1; i < n; ++i)
		for(int j = 1; j < n; ++j)
			for(int k = 1; i + k <= n && j + k <= n; ++k) {
				if(check(i, j, k, cur)) mx = max(mx, cur);
			}
	print(mx, '\n');
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

