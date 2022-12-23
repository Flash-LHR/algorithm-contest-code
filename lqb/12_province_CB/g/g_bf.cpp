#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

int n;
int a[M + 5];
set<int> st;

void dfs(int u, int w) { //第u个砝码，w：左边重量之和-右边重量之和
	if(u == n + 1) {
		if(w > 0)
			st.insert(w);
		return;
	}
	dfs(u + 1, w);
	dfs(u + 1, w + a[u]);
	dfs(u + 1, w - a[u]);
}

void work() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	dfs(1, 0);
	printf("%d\n", st.size());
}

int main() {
	work();
	return 0;
}
