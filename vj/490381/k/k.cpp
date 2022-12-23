#include <bits/stdc++.h>
using namespace std;

void work() {
	int n, k; scanf("%d %d", &n, &k);
	for(int i = 1; i <= k; ++i) {
		for(int j = i; j <= n; j += k) printf("%d ", j);
	}
	printf("\n");
}

int main() {
	work();
	return 0;
}
