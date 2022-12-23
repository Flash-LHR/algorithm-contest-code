#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;

const int M = (int)1e5;
const int N = 4;
const db eps = 1e-7;
const int inf = 0x3f3f3f3f;

int n;
int a[4][M + 5];
ll p[N + 1][M + 5];
ll h[4][N + 1][M + 5];
ll mod[N + 1] = {0, (int)1e9 + 7, (int)1e9 + 9, (int)1000000021, (int)1000000033};
map<pair<pair<ll, ll>, pair<ll, ll>>, int> mp;
ll ha[N + 1][M + 5];

ll quick(ll a, ll b, ll p) {
	ll s = 1;
	while(b) {
		if(b & 1) (s *= a) %= p;
		(a *= a) %= p;
		b >>= 1;
	}
	return s % p;
}

ll inv(ll n, ll p) {
	return quick(n, p - 2, p);
}

void gao(int pos, bool isA = false) {
	ll cur[N + 1] = {0};
	for(int j = 1; j <= N; ++j) {
		for(int i = 1; i <= n; ++i) {
			(cur[j] += (ll)a[pos][i] * p[j][i] % mod[j]) %= mod[j];
		}
	}
	for(int i = 1; i <= n; ++i) {
		//for(int j = 1; j <= N; ++j) printf("i=%d cur[%d]=%lld\n", i, j, cur[j]);
		//printf("\n");
		if(isA) {
			for(int j = 1; j <= N; ++j) ha[j][i - 1] = cur[j];
		} else if(!mp.count(make_pair(make_pair(cur[1], cur[2]), make_pair(cur[3], cur[4])))) {
			mp[make_pair(make_pair(cur[1], cur[2]), make_pair(cur[3], cur[4]))] = i - 1;
		}
		
		for(int j = 1; j <= N; ++j) {
			cur[j] = (cur[j] - (ll)a[pos][i] * p[j][1] % mod[j] + mod[j]) % mod[j];
			(cur[j] *= inv(131, mod[j])) %= mod[j];
			(cur[j] += (ll)a[pos][i] * p[j][n] % mod[j]) %= mod[j];
		}
	}
}

void work() {
	scanf("%d", &n);
	for(int i = 1; i <= 3; ++i) for(int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
	for(int i = 1; i <= N; ++i) {
		p[i][0] = 1;
		for(int j = 1; j <= n; ++j) {
			p[i][j] = (ll)p[i][j - 1] * 131 % mod[i];
		}
	}
	for(int i = 1; i <= 3; ++i) {
		for(int j = 1; j <= N; ++j) {
			for(int k = 1; k <= n; ++k) {
				h[i][j][k] = (h[i][j][k - 1] + (ll)a[i][k] * p[j][k] % mod[j]) % mod[j];
				//printf("h[%d][%d][%d]=%lld\n", i, j, k, h[i][j][k]);
			}
			//printf("\n");
		}
	}
	//printf("A:\n");
	gao(1, 1);
	//printf("B:\n");
	gao(2, 0);
	/*for(int i = 1; i <= N; ++i) {
		for(int j = 0; j < n; ++j) printf("ha[%d][%d]=%lld\n", i, j, ha[i][j]);
		printf("\n");
	}

	printf("mp:\n");
	for(auto x: mp) printf("<%lld,%lld,%lld,%lld : %d>\n", x.first.first.first, x.first.first.second, 
									  x.first.second.first, x.first.second.second, x.second);
		*/
	int ans = inf;
	for(int i = 0; i < n; ++i) {
		pair<pair<ll, ll>, pair<ll, ll>> cur = make_pair(
				make_pair((h[3][1][n] - ha[1][i] + mod[1]) % mod[1], 
						  (h[3][2][n] - ha[2][i] + mod[2]) % mod[2]), 
			    make_pair((h[3][3][n] - ha[3][i] + mod[3]) % mod[3], 
			              (h[3][4][n] - ha[4][i] + mod[4]) % mod[4]));
		/*printf("i=%d\n", i);
		printf("cur=<%lld,%lld,%lld,%lld>\n", cur.first.first, cur.first.second, 
											  cur.second.first, cur.second.second);*/
		if(mp.count(cur)) {
			//printf("i=%d mp[cur]=%d\n", i, mp[cur]);
			ans = min(ans, i + mp[cur]);
		}
	}
	if(ans == inf) ans = -1;
	printf("%d\n", ans);
}

int main() {
	work();
	return 0;
}
