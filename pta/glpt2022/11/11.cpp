#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

int n, m;
int dep[M + 5];
vector<int> g[M + 5];
bool vis[M + 5];
int fa[M + 5];

void dfs(int u) {
	for(const int &v: g[u]) {
		dep[v] = dep[u] + 1;
		dfs(v);
	}
}

void work() {
	scanf("%d %d", &n, &m);
	int rt = -1;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &fa[i]);
		if(fa[i] == -1) rt = i;
		else g[fa[i]].push_back(i);
	}
	dfs(rt);
	int ans = 0, mxi = rt; vis[rt] = 1;
	for(int i = 1, x; i <= m; ++i) {
		scanf("%d", &x);
		if(vis[x]) {
			printf("%d\n", ans);
			continue;
		}
		if(dep[x] <= dep[mxi]) {
			while(!vis[x]) vis[x] = 1, ans += 2, x = fa[x];
		} else {
			ans += dep[mxi];
			mxi = x;
			while(!vis[x]) vis[x] = 1, ++ans, x = fa[x];
			ans -= dep[x];
		}
		printf("%d\n", ans);
	}
}

int main() {
	work();
	return 0;
}
