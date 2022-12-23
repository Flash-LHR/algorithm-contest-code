#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T& x)
{
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
    x *= f;
}

template <typename T>
void print(T x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch)
{
    print(x), putchar(ch);
}

typedef double db;
typedef long long ll;

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

ll pw[13];
int num[13], pos;
ll f[13][110][110][110];

ll dfs(int pos, int tar, int ds, int r, bool lim)
{
	if(pos == -1)
	{
		return tar == ds && r == 0;
	}
	if(!lim && ~f[pos][tar][ds][r]) return f[pos][tar][ds][r];
	ll res = 0; int up = (lim ? num[pos] : 9);
	for(int i = 0; i <= up; ++i)
	{
		res += dfs(pos - 1, tar, ds + i, (r + i * pw[pos]) % tar, lim && (i == up));
	}
	if(!lim) f[pos][tar][ds][r] = res;
	return res;
}

ll cal(ll n)
{
	pos = 0;
	while(n)
	{
		num[pos++] = n % 10;
		n /= 10;
	}
	ll ans = 0;
	for(int i = 1; i < 110; ++i)
	{
		ans += dfs(pos - 1, i, 0, 0, 1);
	}
	return ans;
}

void work()
{
    ll n; read(n);
	print(cal(n), '\n');
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
	memset(f, -1, sizeof(f));
	pw[0] = 1; for(int i = 1; i < 14; ++i) pw[i] = pw[i - 1] * 10;
    int T; read(T);
    for(int ca = 1; ca <= T; ++ca)
    {
		printf("Case %d: ", ca);
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


