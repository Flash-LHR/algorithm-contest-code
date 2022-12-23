#include <bits/stdc++.h>
using namespace std;

char s[2][100][100];

void work() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%s", s[0][i] + 1);
	for(int i = 1; i <= n; ++i) scanf("%s", s[1][i] + 1);
	if(s[0][n][strlen(s[0][n] + 1)] != '3' && s[0][n][strlen(s[0][n] + 1)] != '4')
		return printf("NO\n"), void();
	for(int i = 1; i <= n; ++i) {
		int u = s[0][i][strlen(s[0][i] + 1)] - '0', 
		    v = s[1][i][strlen(s[1][i] + 1)] - '0';
		if(u <= 2 && v <= 2) return printf("NO\n"), void();
		if(u >= 3 && v >= 3) return printf("NO\n"), void();
	}
	printf("YES\n");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
