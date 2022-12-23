#include <bits/stdc++.h>
using namespace std;

void work() {
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i = 1, u = 0; i <= n; ++i) {
		if(1 <= u && u <= 5) ++ans;
		u = (u + 1) % 7;
	}
	printf("%d\n", ans);
}

int main() {
	work();
	return 0;
}
