#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const int N = (int)16;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3ff33f3f3f3f;

int lg[M + 5];
vector<pair<int, int>> g[M + 5];
ll dis[M + 5][N + 1];
int vis[M + 5];

struct qnode {
	int u; ll dis;
	qnode(int _u, ll _dis): u(_u), dis(_dis){}
	bool operator<(const qnode &b) const {
		return dis > b.dis;
	}
};

priority_queue<qnode> q;

void dijkstra(int s) {
	dis[s][0] = 0;
	q.push(qnode(s, dis[s][0]));
	while(!q.empty()) {
		int u = q.top().u; q.pop();
		if(vis[u] == s) continue;
		vis[u] = s;
		for(const auto &[v, w]: g[u]) if(s < v) {
			if(dis[v][lg[v] - lg[s]] > dis[u][lg[u] - lg[s]] + w) {
				dis[v][lg[v] - lg[s]] = dis[u][lg[u] - lg[s]] + w;
				q.push(qnode(v, dis[v][lg[v] - lg[s]]));
			}
		}
	}
}

int getLca(int a, int b) {
	while(a != b) {
		if(a > b) a>>=1;
		else b>>=1;
	}
	return a;
}

void work() {
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 2; i <= n; ++i) {
		lg[i] = lg[i / 2] + 1;
		for(int j = 0; j <= N; ++j) dis[i][j] = linf;
	}
	for(int i = 1, u, v, w; i <= m; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i = 1; i <= n; ++i) dijkstra(i);
	int q; scanf("%d", &q);
	for(int i = 1, a, b; i <= q; ++i) {
		scanf("%d %d", &a, &b);
		ll mi = linf;
		int lca = getLca(a, b);
		int da = lg[a] - lg[lca], db = lg[b] - lg[lca];
		while(lca) {
			mi = min(mi, dis[a][da] + dis[b][db]);
			++da, ++db, lca>>=1;
		}
		printf("%lld\n", mi == linf ? -1 : mi);
	}
}

int main() {
	work();
	return 0;
}
