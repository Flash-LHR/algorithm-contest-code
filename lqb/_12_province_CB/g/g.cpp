#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e2;
const int N = (int)1e5;

bool f[M + 5][N * 2 + 5];

void work() {
	int n; scanf("%d", &n);
	f[0][N] = 1;
	for(int i = 1, w; i <= n; ++i) {
		scanf("%d", &w);
		for(int j = 0; j <= 2 * N; ++j) if(f[i - 1][j]) {
			f[i][j] = 1;
			f[i][j + w] = 1;
			f[i][j - w] = 1;
		}
	}
	int c = 0; for(int i = N + 1; i <= 2 * N; ++i) if(f[n][i]) ++c;
	printf("%d\n", c);
}

int main() {
	work();
	return 0;
}
