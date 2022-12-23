#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

int ans;
int f[M + 5];

void dfs(int u) {
	if(u == 0) {
		++ans;
		return;
	}
	for(int i = 1; i <= u; ++i) dfs(u - i);
}

void work() {
	int k; scanf("%d", &k);
	dfs(k);
	printf("%d\n", ans);
}

int main() {
	work();
	return 0;
}
