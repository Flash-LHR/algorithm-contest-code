#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m, s;
vector<pair<int, int>> g[M + 5];

/**
g[u]: vector<pair<int, int>>
		vector<v, w>
*/

ll dis[M + 5]; //1到i的距离
bool vis[M + 5]; //1到i的最短距离是否已经确定

struct qnode {
	int u;
	ll dis;
	qnode(int _u, ll _dis): u(_u), dis(_dis){}
	bool operator<(const qnode& b) const {
		return dis > b.dis;
	}
};

priority_queue<qnode> q;
//m * log(n)
void dijkstra(int s) {
	for(int i = 1; i <= n; ++i) {
		dis[i] = linf;
		vis[i] = false;
	}
	dis[s] = 0;
	q.push(qnode(s, dis[s]));
	while(!q.empty()) {
		int u = q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < (int)g[u].size(); ++i) {
			int v = g[u][i].first, w = g[u][i].second;
			if(!vis[v] && dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(qnode(v, dis[v]));
			}
		}
	}	
}

void work() {
	scanf("%d %d %d", &n, &m, &s);
	for(int i = 1, u, v, w; i <= m; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
	}
	dijkstra(s);
	for(int i = 1; i <= n; ++i) printf("%lld%c", dis[i] == linf ? INT_MAX : dis[i], " \n"[i == n]);
}

int main() {
	work();
	return 0;
}
