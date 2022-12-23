#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const ll p = (ll)998244353;

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

ll quick(ll a, ll b, ll p)
{
    a %= p;
    ll s = 1;
    while(b)
    {
        if(b & 1)   s = s * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return s % p;
}

int phi(int n)
{
    int ans = n;
    for(int i = 1; i <= cnt && 1ll * prime[i] * prime[i] <= n; ++i)
    {
        if(n % prime[i])    continue;
        ans = ans / prime[i] * (prime[i] - 1);
        while(n % prime[i] == 0) n /= prime[i];
    }
    if(n > 1) ans = ans / n * (n - 1);
    return ans;
}

void work()
{
    int n; scanf("%d", &n);
    ll ans = 0;
    for(int d = 1; 1ll * d * d <= n; ++d)
    {
        if(n % d)   continue;
        ans = (ans + quick(n, d - 1, p) * phi(n / d) % p) % p;
        if(d != n / d) ans = (ans + quick(n, n / d - 1, p) * phi(d) % p) % p;
    }
    printf("%lld\n", ans);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
    init();
    int T = 1; //scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca)
    {
//        printf("Case %d: ", ca);
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}
