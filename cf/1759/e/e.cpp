#include <bits/stdc++.h>
using namespace std;

const int M = (int)2e5;

int n, h;
int a[M + 5];
int mx;

void dfs(int u, long long h, int g, int b)
{
	mx = max(mx, u);
	if (u == n + 1) return;
	if (h > a[u]) dfs(u + 1, h + a[u] / 2, g, b);
	else {
		if (g >= 1 && h * 2 > a[u]) dfs(u + 1, h * 2 + a[u] / 2, g - 1, b);
		if (b >= 1 && h * 3 > a[u]) dfs(u + 1, h * 3 + a[u] / 2, g, b - 1);
		if (g >= 2 && h * 4 > a[u]) dfs(u + 1, h * 4 + a[u] / 2, g - 2, b);
		if (g >= 1 && b >= 1 && h * 6 > a[u]) dfs(u + 1, h * 6 + a[u] / 2, g - 1, b - 1);
		if (g >= 2 && b >= 1 && h * 12 > a[u]) dfs(u + 1, h * 12 + a[u] / 2, g - 2, b - 1);
	}
}

void work()
{
	scanf("%d %d", &n, &h);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	mx = 0;
	dfs(1, h, 2, 1);
	printf("%d\n", mx - 1);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
