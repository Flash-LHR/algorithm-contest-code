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

bool is_prime[M + 5];
int prime[M + 5], cnt;

void init()
{
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i <= M; ++i)
    {
        if(is_prime[i])
        {
            prime[++cnt] = i;
        }
        for(int j = 1; j <= cnt && i * prime[j] <= M; ++j)
        {
            is_prime[i * prime[j]] = 0;
            if(i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

map<pair<int, int>, pair<ll, ll>> mp;

void work() {
	int a, b; scan(a), scan(b);
	if(a > b) swap(a, b);
	ll c = a, d = b;
	for(int i = 1; i <= cnt; ++i) if(__gcd(prime[i], b) == 1) {
		while(c <= b) c *= prime[i];
		break;
	}
	for(int i = 1; i <= cnt; ++i) if(__gcd((ll)prime[i], c) == 1) {
		while(d <= b) d *= prime[i];
		break;
	}
	printf("%lld %lld\n", c, d);

}

int main() {
	/*ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	init();
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

