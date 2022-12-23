#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)5e2;
const int inf = 0x3f3f3f3f;

int n, m, s, d;
int a[M + 5];
vector<pair<int, int>> g[M + 5];
bool vis[M + 5];
int dis[M + 5];
int num[M + 5];
ll f[M + 5];
int pre[M + 5];

struct qnode {
	int u, dis, num;
	qnode(int _u, int _dis, int _num): u(_u), dis(_dis), num(_num) {}
	bool operator<(const qnode& b) const {
		if(dis != b.dis) return dis > b.dis;
		return num < b.num;
	}
};

priority_queue<qnode> q;

void dijkstra() {
	for(int i = 0; i < n; ++i) {
		vis[i] = 0;
		dis[i] = inf;
		num[i] = 0;
	}
	f[s] = 1;
	q.push(qnode(s, dis[s] = 0, num[s] = a[s]));
	while(!q.empty()) {
		int u = q.top().u; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(const auto &[v, w]: g[u]) {
			if(dis[v] > dis[u] + w) {
				f[v] = f[u];
				dis[v] = dis[u] + w;
				num[v] = num[u] + a[v];
				pre[v] = u;
				q.push(qnode(v, dis[v], num[v]));
			} else if(dis[v] == dis[u] + w) {
				f[v] += f[u];
				if(num[v] < num[u] + a[v]) {
					num[v] = num[u] + a[v];
					pre[v] = u;
					q.push(qnode(v, dis[v], num[v]));
				}
			}
		}
	}
}

void work() {
	scanf("%d %d %d %d", &n, &m, &s, &d);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0, u, v, w; i < m; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	dijkstra();
	printf("%lld %d\n", f[d], num[d]);
	stack<int> st; st.push(d); while(d != s) st.push(d = pre[d]);
	while(!st.empty()) {
		if(d == -1) printf(" ");
		d = -1;
		printf("%d", st.top());
		st.pop();
	}
	printf("\n");
}

int main() {
	work();
	return 0;
}
