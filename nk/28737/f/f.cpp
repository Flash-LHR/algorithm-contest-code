#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e6;

int n, k;
char s[M + 5];
int nx[M + 5];
vector<int> g[M + 5];
int sz[M + 5];

void get_nx() {
	nx[1] = 0;
	for(int i = 2, j = 0; i <= n; ++i) {
		while(j && s[i] != s[j + 1]) j = nx[j];
		if(s[i] == s[j + 1]) ++j;
		nx[i] = j;
	}
}

void dfs(int u) {
	sz[u] = 1;
	for(const int &v: g[u]) {
		dfs(v);
		sz[u] += sz[v];
	}
}

void work() {
	scanf("%d%d%s", &n, &k, s + 1);
	get_nx();
	for(int i = 1; i <= n; ++i) g[nx[i]].push_back(i);
	dfs(0);
	int p = n; while(p && sz[p] < k) p = nx[p];
	if(p == 0) printf("-1\n");
	else s[p + 1] = '\0', printf("%s\n", s + 1);
}

int main() {
	work();
	return 0;
}
