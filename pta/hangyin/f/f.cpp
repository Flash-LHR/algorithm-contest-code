#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)3e5;
int n, k;
int de[M + 5];
vector<int> g[M + 5];
vector<int> ans;

void dfs(int u, int fa) {
	if(k) {
		ans.push_back(u);
		--k;
	}
	for(const auto& v: g[u]) {
		if(v == fa) continue;
		dfs(v, u);
	}
}

void work() {
	scanf("%d %d", &n, &k);
	for(int i = 2, u, v; i <= n; ++i) {
		scanf("%d %d", &u, &v);
		++de[u], ++de[v];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int rt = -1;
	for(int i = 1; i <= n; ++i) if(de[i] <= 1) rt = i;
	dfs(rt, 0);
	for(const auto& x: ans) printf("%d ", x);
	printf("\n");
}

int main() {
	work();
	return 0;
}
