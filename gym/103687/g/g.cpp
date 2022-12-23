#include <bits/stdc++.h>
using namespace std;

typedef double db;

const int M = (int)1e3;

int n, v1, v2;
struct point {
	int x, y;
} p[M + 5];

db dis[M + 5];
db w[M + 5][M + 5];
bool vis[M + 5];

struct qnode {
	int u; db dis;
	qnode(int _u, db _dis): u(_u), dis(_dis){}
	bool operator<(const qnode &b) const {
		return dis > b.dis;
	}
};

priority_queue<qnode> q;

void dijkstra(int s, int t) {
	dis[s] = 0;
	q.push(qnode(s, dis[s]));
	while(!q.empty()) {
		int u = q.top().u; q.pop();
		if(vis[u]) continue;
		if(u == t) return;
		vis[u] = 1;
		for(int i = 1; i <= n + 2; ++i) {
			if(u == s) {
				if(dis[i] > dis[u] + w[u][i] / v1) {
					dis[i] = dis[u] + w[u][i] / v1;
					q.push(qnode(i, dis[i]));
				}
			} else {
				db t = 0.0;
				if(3 * v2 >= w[u][i]) t = w[u][i] / v2;
				else t = 3 + (w[u][i] - 3 * v2) / v1;
				if(dis[i] > dis[u] + t) {
					dis[i] = dis[u] + t;
					q.push(qnode(i, dis[i]));
				}
			}
		}
	}
}

void work() {
	scanf("%d", &n);
	for(int i = 1; i <= n + 2; ++i) scanf("%d%d", &p[i].x, &p[i].y), dis[i] = 1e20, vis[i] = 0;
	scanf("%d%d", &v1, &v2);
	for(int i = 1; i <= n + 2; ++i) for(int j = 1; j <= n + 2; ++j) {
		db dx = p[i].x - p[j].x, 
		   dy = p[i].y - p[j].y;
		w[i][j] = sqrt(dx * dx + dy * dy);
	}
	dijkstra(n + 1, n + 2);
	printf("%.12f\n", dis[n + 2]);
}

int main() {
	int T = 1; //scanf("%d", &T);
	while(T--) work();
	return 0;
}
