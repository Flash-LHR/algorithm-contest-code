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

char s[M + 5]; int n, m;
bool vis[M + 5][M + 5];

bool dfs(int pos, int rem)
{
	if(vis[pos][rem]) return false;
	if(pos == -1) return rem == 0;
	if(s[pos] == '?') {
		for(int i = (pos == m - 1); i <= 9; ++i) {
			s[pos] = i + '0';
			if(dfs(pos - 1, (rem * 10 + i) % n)) return true;
			s[pos] = '?';
		}
	} else if(dfs(pos - 1, (rem * 10 + s[pos] - '0') % n)) return true;
	vis[pos][rem] = true;
	return false;
}

void work() {
	scanf("%s %d", s, &n);
	m = strlen(s);
	reverse(s, s + m);
	if(dfs(m - 1, 0)) {
		reverse(s, s + m);
		printf("%s\n", s);
	} else printf("*\n");
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

