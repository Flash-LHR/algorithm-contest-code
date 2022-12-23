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

const int M = (int)1e2;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int num[M + 5], pos;
int f[M + 5][2][M * 2 + 5];

int dfs(int pos, int pre, int sum, bool limit)
{
	if(pos == -1)
	{
		if(~pre) return (int)abs(sum - M);
		return 0;
	}
	if(!limit && ~pre && ~f[pos][pre][sum]) return f[pos][pre][sum];
	int res = 0, up = (limit ? num[pos] : 1);
	for(int i = 0; i <= up; ++i)
	{
		if(pre == -1)
		{
			(res += dfs(pos - 1, i ? i : -1, sum, limit && (i == up))) %= mod;
		}
		else
		{
			(res += dfs(pos - 1, i, sum + (i == pre ? 1 : -1), limit && (i == up))) %= mod;
		}
	}
	if(!limit && ~pre) f[pos][pre][sum] = res;
	return res;
}

int cal(ll n)
{
	pos = 0;
	while(n)
	{
		num[pos++] = (n&1);
		n >>= 1;
	}
	return dfs(pos - 1, -1, M, 1);
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
    int T; read(T);
    for(int ca = 1; ca <= T; ++ca)
    {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


