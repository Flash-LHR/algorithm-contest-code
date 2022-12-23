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

int num[20], pos;
ll f[20][7], pw[19];

ll dfs(int pos, int r, bool lim)
{
	if(pos == -1) return r != 0;
	if(!lim && ~f[pos][r]) return f[pos][r];
	ll res = 0; int up = (lim ? num[pos] : 9);
	for(int i = 0; i <= up; ++i)
	{
		if(i == 7) continue;
		res += dfs(pos - 1, (r + i * pw[pos]) % 7, lim && (i== up));
	}
	if(!lim) f[pos][r] = res;
	return res;
}

ll cal(ll n)
{
	ll m = n;
	pos = 0;
	while(n)
	{
		num[pos++] = n % 10;
		n /= 10;
	}
	return m - dfs(pos - 1, 0, 1);
}

void work()
{
	ll m, n; read(m), read(n);
	ll l = m + 1, r = (ll)1e18, mid;
	while(l < r)
	{
		mid = (l + r) >> 1;
		if(cal(mid) - cal(m) >= n) r = mid;
		else					   l = mid + 1;
	}
	print(r, '\n');
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    int T; read(T);
//    for(int ca = 1; ca <= T; ++ca)
//    {
//        work();
//    }
	memset(f, -1, sizeof(f));
	pw[0] = 1; for(int i = 1; i < 19; ++i) pw[i] = pw[i - 1] * 10;
    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


