#include <bits/stdc++.h>
using namespace std;

const int M = (int)3e5;
const int inf = 0x3f3f3f3f;

int n, a[M + 5];
int pos[M + 5], pre[M + 5], suf[M + 5];

void work() {
	scanf("%d", &n);
	memset(pos, inf, sizeof(int) * (n + 2));
	pre[0] = suf[n + 1] = inf;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if(pos[a[i]] == inf) pos[a[i]] = i;
	}
	for(int i = 1, j = n; i <= n; ++i, --j)
		pre[i] = min(pre[i - 1], pos[i]), 
		suf[j] = min(suf[j + 1], pos[j]);
	int ans = 0;
	for(int i = 1; i <= n; ++i) ans = max(ans, i - min(pre[a[i] - 1], suf[a[i] + 1]));
	printf("%d\n", ans);
}

int main() {
	work();
	return 0;
}
