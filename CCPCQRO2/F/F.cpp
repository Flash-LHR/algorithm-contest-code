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
const ll mod = (ll)998244353;

char s[M + 5], t[11] = "@nunhehheh";
int f[M + 5][10], sum[10];

void work()
{
    scanf("%s", s + 1);
	int n = strlen(s + 1);
	memset(sum, 0, sizeof(sum));
	f[0][0] = 1, sum[0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 9; j >= 1; --j)
		{
			if(s[i] == t[j]) f[i][j] = sum[j - 1], (sum[j] += f[i][j]) %= mod;
			else f[i][j] = 0;
		}
	}
	int a = 1, ans = 0;
	for(int i = n; i >= 1; --i)
	{
		(ans += 1ll * f[i][9] * (a - 1) % mod) %= mod;
		if(s[i] == 'a') (a *= 2) %= mod;
	}
	print(ans, '\n');
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T; read(T);
    for(int ca = 1; ca <= T; ++ca)
    {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


