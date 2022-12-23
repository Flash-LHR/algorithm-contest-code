#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)5e3;
const int mod = (int)1e9 + 7;

int n;
char s[M + 5];
int f[M + 5][M + 5];
int mi[M + 5], m;
int sum[M + 5][M + 5];

int cal() {
	m = 0; int a = 0, b = 0, c = 0;
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '(') {
			--a;
			--b;
		} else {
			++a;
			++b;
			if(b > 0) c += b, b = 0;
			mi[m] = max(0, a);
		}
	}
	memset(f, 0, sizeof f);
	memset(sum, 0, sizeof sum);
	f[0][0] = 1;
	for(int i = 0; i <= c; ++i) sum[0][i] = 1;
	for(int i = 1; i <= m; ++i) {
		for(int j = mi[i]; j <= c; ++j) {
			f[i][j] = sum[i - 1][j];
			sum[i][j] = (sum[i][j - 1] + f[i][j]) % mod;
		}
	}
	return f[m][c];
}

void work() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int ans = cal();
	reverse(s + 1, s + n + 1);
	for(int i = 1; i <= n; ++i) s[i] ^= 1;
	ans = (ll)ans * cal() % mod;
	printf("%d\n", ans);
}

int main() {
	work();
	return 0;
}
