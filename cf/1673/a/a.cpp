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
const int M = (int)2e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

char s[M + 5];

void work() {
	scanf("%s", s);
	int n = strlen(s);
	if(n & 1) {
		int ans1 = 0, ans2 = 0;
		for(int i = 0; i < n; ++i) ans1 += s[i] - 'a' + 1;
		if(s[0] < s[n - 1]) ans1 -= s[0] - 'a' + 1, ans2 += s[0] - 'a' + 1;
		else ans1 -= s[n - 1] - 'a' + 1, ans2 += s[n - 1] - 'a' + 1;
		if(ans1 > ans2) printf("Alice %d\n", ans1 - ans2);
		else printf("Bob %d\n", ans2 - ans1);
	} else {
		int ans = 0;
		for(int i = 0; i < n; ++i) ans += s[i] - 'a' + 1;
		printf("Alice %d\n", ans);
	}
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

