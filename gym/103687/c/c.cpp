#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

void work() {
	int n, m, x; scanf("%d%d%d", &n, &m, &x);
	int ans = 0;
	for(int i = 1, a; i <= n; ++i) {
		scanf("%d", &a);
		if(a >= x) ++ans;
	}
	for(int i = 1, a; i <= m; ++i) {
		scanf("%d", &a);
		if(a <= x) ++ans;
	}
	printf("%d\n", ans);
}

int main() {
	int T = 1; //scanf("%d", &T);
	while(T--) work();
	return 0;
}
