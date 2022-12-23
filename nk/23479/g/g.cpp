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

int n;
int a[M + 5];

ll quick(ll a, ll b, ll p = mod)
{
    ll s = 1;
    while(b)
    {
        if(b & 1) s = s * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return s % p;
}

void work() {
    scan(n);
    for(int i = 1; i <= n; ++i) scan(a[i]);
    sort(a + 1, a + n + 1);
    int ans = 1;
    for(int i = 1; i <= n; ++i) ans = (ll)ans * quick(a[i], quick(2, i - 1, mod - 1)) % mod;
    for(int i = 1; i <= n; ++i) ans = (ll)ans * quick(a[i], quick(2, n - i, mod - 1)) % mod;
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
