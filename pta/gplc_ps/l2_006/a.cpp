#include <bits/stdc++.h>
using namespace std;

const int M = (int)30;

int n;
int back[M + 5];
int mid[M + 5];
bool vis[M + 5];
int son[M + 5][2];

void dfs(int l1, int r1, int l2, int r2) {
	int rt = back[r1], pos = -1, l = -1;
	for(int i = l2; i <= r2; ++i) if(mid[i] == rt) pos = i;
	if(l2 < pos) {
		for(int i = l2; i < pos; ++i) vis[mid[i]] = 1;
		for(int i = l1; i <= r1; ++i) if(vis[back[i]]) {l = i; break;}
		for(int i = l2; i < pos; ++i) vis[mid[i]] = 0;
		son[rt][0] = back[l + pos - l2 - 1];
		dfs(l, l + pos - l2 - 1, l2, pos - 1);
	}
	if(pos < r2) {
		for(int i = pos + 1; i <= r2; ++i) vis[mid[i]] = 1;
		for(int i = l1; i <= r1; ++i) if(vis[back[i]]) {l = i; break;}
		for(int i = pos + 1; i <= r2; ++i) vis[mid[i]] = 0;
		son[rt][1] = back[l + r2 - pos - 1];
		dfs(l, l + r2 - pos - 1, pos + 1, r2);
	}
}

void bfs(int u) {
	queue<int> q;
	q.push(u);
	bool f = 0;
	while(!q.empty()) {
		if(f) printf(" ");
		f = 1;
		u = q.front(); q.pop();
		printf("%d", u);
		if(son[u][0]) q.push(son[u][0]);
		if(son[u][1]) q.push(son[u][1]);
	}
	printf("\n");
}

void work() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &back[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", &mid[i]);
	dfs(1, n, 1, n);
	bfs(back[n]);
}

int main() {
	work();
	return 0;
}
