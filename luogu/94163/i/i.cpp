#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;
const int inf = 0x3f3f3f3f;

int n, m, p, q;
vector<int> g[M + 5];
int dis[M + 5];

void bfs()
{
	queue<int> q;
	for (int i = 1, x; i <= p; ++i) {
		scanf("%d", &x);
		dis[x] = 0;
		q.push(x);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (const int &v: g[u]) {
			if (dis[v] == inf) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

void work()
{
	scanf("%d %d", &n, &m);
	memset(dis, inf, sizeof dis);
	for (int i = 1, u, v; i <= m; ++i) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	scanf("%d %d", &p, &q);
	bfs();
	int mi = inf;
	for (int i = 1, x; i <= q; ++i) scanf("%d", &x), mi = min(mi, dis[x]);
	if (mi == inf) printf("N0\n");
	else printf("%d\n", mi);
}

int main()
{
	work();
	return 0;
}
