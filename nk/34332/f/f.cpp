#include <bits/stdc++.h>
using namespace std;

vector<int> g[10];

void add(int u, int v) {
	g[u].push_back(v);
}

void init() {
	add(1, 2), add(1, 3);
	add(2, 1), add(2, 4);
	add(3, 1), add(3, 4);
	add(4, 5), add(4, 6), add(4, 2), add(4, 3);
	add(5, 4), add(5, 7);
	add(6, 4), add(6, 7);
	add(7, 5), add(7, 6);
}

int cal(int a1, int a2, int b1, int b2) {
	queue<pair<int, int>> q;
	int dis[10][10]; memset(dis, -1, sizeof dis);
	dis[a1][a2] = 0;
	q.push({a1, a2});
	pair<int, int> p1, p2;
	p1 = make_pair(b1, b2), p2 = make_pair(b2, b1);
	while(!q.empty()) {
		auto u = q.front(); q.pop();
		if(u == p1 || u == p2) return dis[u.first][u.second];
		for(const int &v: g[u.first]) if(dis[v][u.second] == -1) {
			dis[v][u.second] = dis[u.first][u.second] + 1;
			q.push({v, u.second});
		}
		for(const int &v: g[u.second]) if(dis[u.first][v] == -1) {
			dis[u.first][v] = dis[u.first][u.second] + 1;
			q.push({u.first, v});
		}
	}
	return -1;
}

void work() {
	int a1, a2, b1, b2; scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
	printf("%d\n", cal(a1, a2, b1, b2));
}

int main() {
	init();
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
