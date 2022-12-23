#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e2;
const int N = (int)1e5;
const int O = (int)1e5;

int n, a[M + 5];
bool f[M + 5][N + O + 5];

void work() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	f[0][0 + O] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = -N; j <= N; ++j) if(f[i - 1][j + O]) {
			f[i][j + O] = 1;
			if(j + a[i] + O <= 2 * N) f[i][j + a[i] + O] = 1;
			if(j - a[i] + O >= 0 && j - a[i] + O <= 2 * N) f[i][j - a[i] + O] = 1;
		}
		/*printf("i=%d\t", i);
		for(int j = -N; j <= N; ++j) {
			if(f[i][j + O]) printf("%d ", j);
		}
		printf("\n");*/
	}
	int cnt = 0;
	for(int i = 1; i <= N; ++i) if(f[n][i + O]) ++cnt;
	printf("%d\n", cnt);
}

int main() {
	work();
	return 0;
}
