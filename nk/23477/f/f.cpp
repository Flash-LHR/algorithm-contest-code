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
const int M = (int)1e6;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, q;
char s[M + 5];
vector<int> pro;
int id[M + 5];
int a[M + 5];

ll quick(ll a, ll b, ll p = mod) {
	ll s = 1;
	while(b) {
		if(b & 1) (s *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return s % mod;
}

ll inv(ll n, ll p = mod) {
	return quick(n, p - 2, p);
}

void work() {
	scan(n), scan(q);
	scanf("%s", s + 1);
	s[0] = '+', s[n] = '+';
	for(int i = 1; i <= n; ++i) scan(a[i]);
	int cnt = 0;
	for(int i = 0, pre = -1; i <= n; ++i) {
		if(s[i] == '+') {
			int cur = 1;
			for(int j = pre + 1; j <= i; ++j) {
				id[j] = cnt;
				cur = (ll)cur * a[j] % mod;
			}
			pro.push_back(cur);
			pre = i, ++cnt;
		}
	}
	int sum = 0; for(auto x: pro) (sum += x) %= mod;
	/*for(int i = 1; i <= n; ++i) printf("%d: %d\n", i, id[i]);
	for(auto x: pro) printf("x=%d\n", x);*/
	for(int i = 1, x, y; i <= q; ++i) {
		scan(x), scan(y);
		sum = (sum - pro[id[x]] + mod) % mod;
		pro[id[x]] = (ll)pro[id[x]] * inv(a[x]) % mod;
		a[x] = y;
		pro[id[x]] = (ll)pro[id[x]] * a[x] % mod;
		sum = (sum + pro[id[x]]) % mod;
		print(sum, '\n');
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

