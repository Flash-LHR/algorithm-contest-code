#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)3e3;
const int inf = 0x3f3f3f3f;

int n, m, t;
int a[M + 5];
vector<int> g[M + 5];
int dis[M + 5];
int f[M + 5];

void bfs(int s) {
	queue<int> q;
	memset(dis, inf, sizeof dis);
	dis[s] = 0;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(const int &v: g[u]) {
			if(dis[v] == inf) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

void work() {
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 2; i <= n; ++i) scanf("%d", &a[i]);
	for(int i = 1, u, v; i <= m; ++i) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(1);
	memset(f, -inf, sizeof f);
	f[0] = 0;
	for(int i = 2; i <= n; ++i) {
		for(int j = 2 * dis[i]; j <= t; ++j) f[j] = max(f[j], f[j - 2 * dis[i]] + a[i]);
	}
	for(int i = 1, mx = 0; i <= t; ++i) {
		mx = max(mx, f[i]);
		printf("%d%c", mx, " \n"[i == t]);
	}

}

int main() {
	int T = 1; //scanf("%d", &T);
	while(T--) work();
	return 0;
}
