#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

const int n = 2021, m = 21;
ll dis[M + 5];
bool vis[M + 5];
struct qnode {
	int u; ll dis;
	qnode(int _u, ll _dis): u(_u), dis(_dis){}
	bool operator<(const qnode& b) const {
		return dis > b.dis;
	}
};
priority_queue<qnode> q;

int lcm(int a, int b) {
	return a / __gcd(a, b) * b;
}

void work() {
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	q.push(qnode(1, dis[1]));
	while(!q.empty()) {
		int u = q.top().u; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int v = max(1, u - m); v <= min(n, u + m); ++v) {
			if(dis[v] > dis[u] + lcm(u, v)) {
				dis[v] = dis[u] + lcm(u, v);
				q.push(qnode(v, dis[v]));
			}
		}
	}
	printf("%lld\n", dis[n]);
}

int main() {
	work();
	return 0;
}

