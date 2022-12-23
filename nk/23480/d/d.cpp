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

int num[20];
ll f[20][10][2];

bool check(int n) {
	return n == 2 || n == 3 || n == 5 || n == 7 || n == 11
		|| n == 13 || n == 17 || n == 19;
}

ll dfs(int pos, int pre, bool have1, bool limit, bool lead) {
	if(pos == -1) return have1;
	if(!limit && !lead && ~f[pos][pre][have1]) return f[pos][pre][have1];
	int up = (limit ? num[pos] : 9);
	ll res = 0;
	for(int i = 0; i <= up; ++i) {
		if(!lead && !check(pre + i)) continue;
		res += dfs(pos - 1, i, have1 || (i == 1), limit && (i == up), lead && (i == 0));
	}
	if(!limit && !lead) f[pos][pre][have1] = res;
	return res;
}

ll cal(ll n) {
	if(n == 0) return 0;
	int pos = 0;
	while(n) {
		num[pos++] = n % 10;
		n /= 10;
	}
	return dfs(pos - 1, 0, 0, 1, 1);
}

void work() {
	memset(f, -1, sizeof f);
	ll l, r; scan(l), scan(r);
	print(cal(r) - cal(l - 1), '\n');
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

