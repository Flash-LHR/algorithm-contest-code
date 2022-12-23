#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;
const int N = (int)1e2;
const int inf = 0x3f3f3f3f;

int n, m, q;
vector<int> g[M + 5];
vector<int> buk[N + 5];
int dis[N + 5][M + 5];

void bfs(int s) {
	for(int i = 1; i <= n; ++i) dis[s][i] = inf;
	queue<int> q;
	for(const int &x: buk[s]) {
		dis[s][x] = 0;
		q.push(x);
	}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(const int &v: g[u]) if(dis[s][v] == inf) {
			dis[s][v] = dis[s][u] + 1;
			q.push(v);
		}
	}
}

void work() {
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1, w; i <= n; ++i) {
		scanf("%d", &w);
		buk[w].push_back(i);
	}
	for(int i = 1, u, v; i <= m; ++i) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i <= N; ++i) bfs(i);
	for(int i = 1, p, a; i <= q; ++i) {
		scanf("%d %d", &p, &a);
		int mi = inf;
		for(int j = 1; j <= a; ++j) mi = min(mi, dis[j][p]);
		printf("%d\n", mi == inf ? -1 : mi);
	}

}

int main() {
	work();
	return 0;
}
