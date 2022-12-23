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
const int M = (int)5e5;
const int N = (int)19;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n; ll k;
int a[M + 5];

void work() {
	scan(n), scan(k);
	for(int i = 1; i <= n; ++i) scan(a[i]);
	vector<ll> v;
	for(int l = 1; l <= n; ++l) {
		int mi = inf, mx = -inf;
		for(int r = l; r <= n; ++r) {
			mi = min(mi, a[r]), mx = max(mx, a[r]);
			v.push_back(-(ll)(mx - mi) * (r - l + 1));
		}
	}
	sort(v.begin(), v.end());
	printf("%lld\n", -v[k - 1]);
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

