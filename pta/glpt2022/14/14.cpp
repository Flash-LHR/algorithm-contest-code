#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const int N = (int)1e4;
const int inf = 0x3f3f3f3f;

vector<int> g[M + 5];
int a[M + 5], len;
int ans, n, r;

void cal() {
	for(int i = 1; i <= n; ++i) printf("%d ", a[i]);
	printf("\n");
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) if(a[i] > a[j]) ++ans;
	}
}

void dfs(int u, int fa, int len) {
	a[len] = u;
	if(len == n) cal();
	do {
		f();
	} while(next_permutation(g[u].begin(), g[u].end()));
}

void work() {
	 scanf("%d %d", &n, &r);
	for(int i = 2, u, v; i <= n; ++i) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(r, 0, 1);
	printf("%d\n", ans);

}

int main() {
	work();
	return 0;
}
