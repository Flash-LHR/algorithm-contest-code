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

int n, m;
ll a[M + 5];
map<ll, set<pair<ll, int>>> mp;
bool flag;

ll cal(ll x)
{
	if(x == 0) return 0;
	if(a[n] == 0)
	{
		auto it = mp[x].lower_bound(make_pair(x, 0));
		if(it != mp[x].end() && it->first == x) return it->second;
		else return -1;
	}
	ll k = x / a[n], r = x % a[n];
	if(mp[r].empty()) return -1;
	//printf("k = %lld r = %lld\n", k, r);
	auto it = mp[r].upper_bound(make_pair(k, inf));
	if(it == mp[r].begin()) return -1;
	--it;
	//printf("it.f = %lld it.s = %d\n", it->first, it->second);
	return (k - it->first) * n + it->second;
}

void work()
{
	mp.clear();
    read(n), read(m);
	for(int i = 1; i <= n; ++i) read(a[i]), a[i] += a[i - 1];
	flag = (a[n] < 0);
	if(flag) for(int i = 1; i <= n; ++i) a[i] = -a[i];
	if(a[n] == 0)
	{
		for(int i = 1; i <= n; ++i) mp[a[i]].insert(make_pair(a[i], i));
	}
	else
	{
		for(int i = 1; i <= n; ++i)
		{
			auto it = mp[a[i] % a[n]].lower_bound(make_pair(a[i] / a[n], 0));
			if(it == mp[a[i] % a[n]].end() || it->first != a[i] / a[n])
				mp[a[i] % a[n]].insert(make_pair(a[i] / a[n], i));
			ll x = (a[i] % a[n] + a[n]) % a[n];
			it = mp[x].lower_bound(make_pair(-(x - a[i]) / a[n], 0));
			if(it == mp[x].end() || it->first != -(x - a[i]) / a[n])
				mp[x].insert(make_pair(-(x - a[i]) / a[n], i));
		}
	}/*
	for(auto x: mp)
	{
		printf("x.first = %lld:", x.first);
		for(auto y: mp[x.first])
		{
			printf(" <%lld,%d>", y.first, y.second);
		}
		printf("\n");
	}*/
	ll x, ans;
	for(int i = 1; i <= m; ++i)
	{
		read(x);
		ans = (ll)1e18;
		if(flag) x = -x;
		ans = min(ans, cal(x));
		print(ans == (ll)1e18 ? -1 : ans, '\n');
	}
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


