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

int n, L, R;
char s[M + 5];
int cnt[M + 5][4];

int cat(char ch) {
	if('A' <= ch && ch <= 'Z') return 0;
	else if('a' <= ch && ch <= 'z') return 1;
	else if('0' <= ch && ch <= '9') return 2;
	return 3;
}

bool ok(int l, int r, int i) {
	return cnt[r][i] - cnt[l - 1][i] > 0;
}

bool check(int l, int r) {
	int c = 0;
	for(int i = 0; i < 4; ++i) c += ok(l, r, i);
	return c >= 3;
}

int bs(int p) {
	if(p + L - 1 > n) return 0;
	int l = p + L - 1, r = min(n, p + R - 1), mid;
	while(l < r) {
		mid = (l + r) >> 1;
		if(check(p, mid)) r = mid;
		else l = mid + 1;
	}
	if(!check(p, r)) return 0;
	return min(n, p + R - 1) - r + 1;
}

void work() {
	scan(n), scan(L), scan(R);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 4; ++j) cnt[i][j] = cnt[i - 1][j];
		++cnt[i][cat(s[i])];
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans += bs(i);
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

