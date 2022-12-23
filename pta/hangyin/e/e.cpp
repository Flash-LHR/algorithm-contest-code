#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;

const int M = (int)4;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n = 4;
int c[M + 5];
int a[M + 5][M + 5];

bool check(int id[]) {
	int cur[M + 5];
	for(int i = 1; i <= n; ++i) cur[i] = c[i];
	for(int i = 1, u; i <= n; ++i) {
		u = id[i];
		if(cur[u] != c[u]) return 0;
		cur[u] = 0;
		for(int j = 1; j <= n; ++j) cur[j] = min(cur[j] + a[i][j], c[j]);
	}
	return 1;
}

void work() {
	for(int i = 1; i <= n; ++i) scanf("%d", &c[i]);
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
	/*int id[5] = {0, 1, 2, 3, 4};
	do {
		if(check(id)) {
			printf("Yes\n");
			return;
		}
	} while(next_permutation(id + 1, id + 5));
	printf("No\n");*/
	for(int i = 1; i <= n; ++i) {
		int s = 0;
		for(int j = 1; j <= n; ++j) s += a[j][i];
		if(s < c[i]) return printf("No\n"), void();
	}
	printf("Yes\n");
}

int main() {
	int T = 1; //scanf("%d", &T);
	while(T--) work();
	return 0;
}
