#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3ff33f3f3f3f;

int lg[M + 5];
vector<pair<int, int>> g[M + 5];
unordered_map<int, ll> dis[M + 5];
int vis[M + 5];

struct qnode {
	int u; ll dis;
	qnode(int _u, ll _dis): u(_u), dis(_dis){}
	bool operator<(const qnode &b) const {
		return dis > b.dis;
	}
};

priority_queue<qnode> q;

bool prefix(int a, int b) {
	return (b>>(lg[b] - lg[a])) == a;
}

void dijkstra(int s) {
	dis[s][s] = 0;
	q.push(qnode(s, 0));
	while(!q.empty()) {
		int u = q.top().u; q.pop();
		if(vis[u] == s) continue;
		vis[u] = s;
		for(const auto &[v, w]: g[u]) if(prefix(s, v)) {
			if(!dis[s].count(v) || dis[s][v] > dis[s][u] + w) {
				dis[s][v] = dis[s][u] + w;
				q.push(qnode(v, dis[s][v]));
			}
		}
	}
}

void work() {
	int n, m; scanf("%d %d", &n, &m);
	for(int i = 2; i <= n; ++i) lg[i] = lg[i / 2] + 1;
	for(int i = 1, u, v, w; i <= m; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i = 1; i <= n; ++i) dijkstra(i);
	int q; scanf("%d", &q);
	for(int i = 1, a, b, ta, tb; i <= q; ++i) {
		scanf("%d %d", &a, &b); ta = a, tb = b;
		ll mi = linf;
		stack<int> sa, sb;
		while(ta) sa.push(ta&1), ta >>= 1;
		while(tb) sb.push(tb&1), tb >>= 1;
		int u = 0;
		while(!sa.empty() && !sb.empty()) {
			if(sa.top() != sb.top()) break;
			u = u * 2 + sa.top();
			sa.pop(), sb.pop();
			if(dis[u].count(a) && dis[u].count(b)) mi = min(mi, dis[u][a] + dis[u][b]);
		}
		printf("%lld\n", mi == linf ? -1 : mi);
	}
}

int main() {
	work();
	return 0;
}

