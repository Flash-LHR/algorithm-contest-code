#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T>
inline void scan(T &n) {
	n = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) {n = n * 10 + ch - '0'; ch = getchar();}
	if(f == -1) n = -n;
}

const int M = (int)2e3;
const int mod = (int)998244353;

struct node {
	int x, y;
} a[M + 5];

pair<int, int> cnt[2][M + 5][M + 5];
char s[M + 5][M * 2 + 5];

void work() {
	int n, m, k, t; scanf("%d%d%d%d", &n, &m, &k, &t);
	ll ans = 0;
	for(int i = 1; i <= k; ++i) {
		scanf("%d%d", &a[i].x, &a[i].y);
		ans += cnt[0][a[i].x][a[i].y].second;
		++cnt[0][a[i].x][a[i].y].second;
	}
	printf("%lld\n", ans);
	for(int i = 1; i <= k; ++i) scanf("%s", s[i] + 1);
	for(int i = 1, u; i <= t; ++i) {
		u = i&1;
		for(int j = 1; j <= k; ++j) {
			--cnt[u^1][a[j].x][a[j].y].second;
			ans -= cnt[u^1][a[j].x][a[j].y].second;
			if(s[j][i] == 'L') a[j].y--;
			else if(s[j][i] == 'R') a[j].y++;
			else if(s[j][i] == 'U') a[j].x--;
			else a[j].x++;
			//printf("i=%d j=%d x=%d y=%d\n", i, j, a[j].x, a[j].y);
			if(cnt[u][a[j].x][a[j].y].first < i) {
				//printf("here1\n");
				cnt[u][a[j].x][a[j].y].first = i;
				cnt[u][a[j].x][a[j].y].second = 1;
			} else {
				//printf("here2\n");
				ans += cnt[u][a[j].x][a[j].y].second;
				cnt[u][a[j].x][a[j].y].second++;
			}
			//printf("\tans=%lld\n", ans);
		}
		printf("%lld\n", ans);
	}
}

int main() {
	work();
	return 0;
}
