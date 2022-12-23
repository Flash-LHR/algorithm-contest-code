#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e2;
const int N = (int)1e4;

bool f[M + 5][N + 5];

void work() {
	int n, x; scanf("%d %d", &n, &x);
	f[0][0] = 1;
	for(int i = 1, a, b; i <= n; ++i) {
		scanf("%d %d", &a, &b);
		for(int j = 0; j <= x; ++j) if(f[i - 1][j]) {
			if(j + a <= x) f[i][j + a] = 1;
			if(j + b <= x) f[i][j + b] = 1;
		}
	}
	puts(f[n][x] ? "Yes" : "No");
}

int main() {
	work();
	return 0;
}


