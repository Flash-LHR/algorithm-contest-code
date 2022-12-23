#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const int inf = 0x3f3f3f3f;

int n, p, f, a[M + 5];
vector<int> g[M + 5];

bool inside(int l, int r, int a) {
	return l <= a && a <= r;
}

void dfs(int l, int r, bool neg) {
	int u = p;
	int ll = l, lr = a[u] - 1;
	int rl = a[u], rr = r;
	if(neg) swap(ll, rl), swap(lr, rr);
	if(p + 1 <= n && inside(ll, lr, a[p + 1])) {
		g[u].push_back(++p);
		dfs(ll, lr, neg);
	}
	if(p + 1 <= n && inside(rl, rr, a[p + 1])) {
		g[u].push_back(++p);
		dfs(rl, rr, neg);
	}
}

void dfsAns(int u) {
	if(g[u].size() >= 1) dfsAns(g[u][0]);
	if(g[u].size() >= 2) dfsAns(g[u][1]);
	if(f) printf(" ");
	f = 1;
	printf("%d", a[u]);
}

void work() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	p = 1; dfs(-inf, inf, 0);
	if(p == n) {
		printf("YES\n");
		dfsAns(1);
		printf("\n");
		return;
	}
	for(int i = 1; i <= n; ++i) g[i].clear();
	p = 1; dfs(-inf, inf, 1);
	if(p == n) {
		printf("YES\n");
		dfsAns(1);
		printf("\n");
		return;
	}
	printf("NO\n");
}

int main() {
	work();
	return 0;
}

