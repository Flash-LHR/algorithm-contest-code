#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

int n, q;
char s[M + 5], t[M + 5];
int nx[M + 5][26];

void work() {
	scanf("%d%d%s", &n, &q, s + 1);
	for(int i = 0; i < 26; ++i) nx[n + 1][i] = n + 1;
	for(int i = n; i >= 1; --i) {
		for(int j = 0; j < 26; ++j) nx[i][j] = nx[i + 1][j];
		nx[i][s[i] - 'a'] = i;
	}
	while(q--) {
		scanf("%s", t + 1);
		int m = strlen(t + 1); bool f = 1;
		for(int i = 1, j = 1; i <= m; ++i, ++j) {
			j = nx[j][t[i] - 'a'];
			if(j == n + 1) {
				f = 0;
				break;
			}
		}
		puts(f ? "YES" : "NO");
	}
}

int main() {
	work();
	return 0;
}
