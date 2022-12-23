#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)5e3;
const int N = (int)2e5;

int n, m;
int fa[M + 5];
int u[N + 5], v[N + 5], w[N + 5];
int best[M + 5];
bool vis[N + 5];

int tofind(int x) {
	if(x == fa[x]) return x;
	return fa[x] = tofind(fa[x]);
}

bool better(int a, int b) {
	if(b == 0) return 1;
	if(w[a] != w[b]) return w[a] < w[b];
	return a < b;
}

void boruvka() {
	ll ans = 0; int cnt = 0;
	iota(fa + 1, fa + n + 1, 1);
	memset(vis, 0, sizeof vis);
	bool update = true;
	while(update) {
		update = false;
		memset(best, 0, sizeof best);
		for(int i = 1, fu, fv; i <= m; ++i) if(!vis[i]) {
			fu = tofind(u[i]), fv = tofind(v[i]);
			if(fu == fv) continue;
			if(better(i, best[fu])) best[fu] = i;
			if(better(i, best[fv])) best[fv] = i;
		}
		for(int i = 1; i <= n; ++i) if(best[i] && !vis[best[i]]) {
			update = true;
			++cnt;
			ans += w[best[i]];
			vis[best[i]] = 1;
			fa[tofind(u[best[i]])] = tofind(v[best[i]]);
		}
	}
	if(cnt == n - 1) printf("%lld\n", ans);
	else printf("orz\n");
}

void work() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) scanf("%d %d %d", &u[i], &v[i], &w[i]);
	boruvka();
}

int main() {
	work();
	return 0;
}
