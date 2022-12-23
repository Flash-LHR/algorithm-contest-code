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

int n, a, b, c;
char s[M + 5];
int cnt[2];

ll cal(int x, int y) {
    ll ans = 0;
    if(x & 1) ans += a, --x, --y;
    if(a < b) {
        ans += (ll)a * min(x, y);
        ans += (ll)b * (max(x, y) - min(x, y)) / 2;
    } else {
        ans += (ll)b * (x + y) / 2;
    }
    return ans;
}

void work() {
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; ++i) ++cnt[s[i] - '0'];
	scan(a), scan(b), scan(c);
	ll mi = linf;
	for(int i = 0; i <= n; ++i) {
		mi = min(mi, cal(i, n - i) + (ll)c * (ll)abs(cnt[0] - i));
		//printf("i=%d mi=%lld\n", i, mi);
	}
	print(mi, '\n');
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


