#include <bits/stdc++.h>
using namespace std;

const int M = (int)5e5;

int dx[] = {1, 0, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 0, -1, -1};

map<pair<int, int>, int> id;
int fa[M + 5], sz[M + 5], idCnt;

int tofind(int x) {
	if(x == fa[x]) return x;
	return fa[x] = tofind(fa[x]);
}

void work() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 6;
	for(int i = 1, op, x, y; i <= n; ++i) {
		scanf("%d %d %d", &op, &x, &y);
		if(!id.count(make_pair(x, y)))
			id[make_pair(x, y)] = ++idCnt;
		if(op == 1) {
			int sxf = 0;
			for(int j = 0, xx, yy; j < 6; ++j) {
				xx = x + dx[j], yy = y + dy[j];
				if(!id.count(make_pair(xx, yy))) continue;
				int u = tofind(id[make_pair(x, y)]), 
					v = tofind(id[make_pair(xx, yy)]);
				++sxf;
				if(u != v) {
					fa[u] = v;
					sz[v] += sz[u];
				}
			}
			sz[tofind(id[make_pair(x, y)])] -= 2 * sxf;
		} else if(op == 2) {
			printf("%d\n", sz[tofind(id[make_pair(x, y)])]);
		}
	}
}

int main() {
	work();
	return 0;
}
