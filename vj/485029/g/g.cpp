#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e2;
const int N = (int)1e4;

int n, m;
char s[M + 5][M + 5];
int dx[] = {-1, -1, 1, 1};
int dy[] = {1, -1, 1, -1};

void work() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) if(s[i][j] == '1') {
			for(int k = 0; k < 4; ++k) {
				int x = i + dx[k], y = j + dy[k];
				if(x < 1 || x > n || y < 1 || y > m) continue;
				if(s[x][y] == '0' && s[i][y] == '1' && s[x][j] == '1') return printf("No\n"), void();
			}
		}
	}
	printf("Yes\n");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}

