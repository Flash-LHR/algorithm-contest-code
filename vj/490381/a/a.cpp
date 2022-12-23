#include <bits/stdc++.h>
using namespace std;

void work() {
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= 6; ++i) for(int j = i; j <= 6; ++j) if(i + j == n) ++ans;
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
