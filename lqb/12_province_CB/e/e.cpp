#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n = 2021, m = 21;

struct qnode {
	int u;
	ll dis;
	qnode(int _u, ll _dis): u(_u), dis(_dis){}
	bool operator<(const qnode& b) const {
		return dis > b.dis;
	}
};

priority_queue<qnode> q;

ll dis[M + 5];
bool vis[M + 5];

void dijkstra(int s) {
	for(int i = 1; i <= n; ++i) {
		dis[i] = linf;
		vis[i] = 0;
	}
	dis[s] = 0;
	q.push(qnode(s, dis[s]));
	while(!q.empty()) {
		int u = q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int v = max(1, u - m); v <= min(n, u + m); ++v) {
			int w = lcm(u, v);
			if(!vis[v] && dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(qnode(v, dis[v]));
			}
		}
	}
}

void work() {
	dijkstra(1);
	printf("%lld\n", dis[n]);
}

int main() {
	work();	
	return 0;
}
