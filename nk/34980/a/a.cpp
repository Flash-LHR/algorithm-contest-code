#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int s) {
	if(u == 0) {
		if(s == 17) printf("ok\n");
		return;
	}
	dfs(u - 1, s + u);
	dfs(u - 1, s - u);
}

void work() {
	int n; scanf("%d", &n);
	dfs(n, 0);
}

int main() {
	work();
	return 0;
}
