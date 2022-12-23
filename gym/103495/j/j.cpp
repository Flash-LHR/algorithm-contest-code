#include <bits/stdc++.h>
using namespace std;

const int M = (int)5e2;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int n, m;
int a[M + 5][M + 5];
bool vis[M + 5][M + 5];
vector<pair<int, int>> ans;

void bfs(int x, int y) {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(x, y, 0));
	vis[x][y] = 1;
	vector<pair<int, int>> v[2];
	while(!q.empty()) {
		tuple<int, int, int> u = q.front(); q.pop();
		v[get<2>(u)].push_back({get<0>(u), get<1>(u)});
		for(int i = 0; i < 4; ++i) {
			int xx = get<0>(u) + dx[i], yy = get<1>(u) + dy[i];
			if(xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || a[xx][yy] != a[x][y]) continue;
			vis[xx][yy] = 1;
			q.push(make_tuple(xx, yy, get<2>(u)^1));
		}
	}
	int sxf = 0;
	if(v[0].size() > v[1].size()) sxf = 1;
	for(const auto& p: v[sxf]) ans.push_back(p);
}

void work() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) scanf("%d", &a[i][j]);
	}
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) if(!vis[i][j]) {
		bfs(i, j);
	}
	if(ans.size() == 0) printf("0 0\n");
	else printf("1 %lu\n", ans.size());
	for(const auto &p: ans) printf("%d %d %d\n", p.first, p.second, 1);
}

int main() {
	work();
	return 0;
}
