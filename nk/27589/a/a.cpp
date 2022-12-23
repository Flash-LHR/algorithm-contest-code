#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e6;

char s[M + 5];
char t[M + 5];
int nx[M + 5];

void get_nx(char *s) {
	for(int i = 2, j = 0; s[i]; ++i) {
		while(j && s[j + 1] != s[i]) j = nx[j];
		if(s[j + 1] == s[i]) ++j;
		nx[i] = j;
	}
}

void work() {
	scanf("%s%s", s + 1, t + 1);
	get_nx(t);
	int n = strlen(s + 1), m = strlen(t + 1);
	for(int i = 1, j = 0; i <= n; ++i) {
		while(j && s[i] != t[j + 1]) j = nx[j];
		if(s[i] == t[j + 1]) ++j;
		if(j == m) {
			printf("%d\n", i - m + 1);
			j = nx[j];
		}
	}
	for(int i = 1; i <= m; ++i) printf("%d%c", nx[i], " \n"[i == m]);
}

int main() {
	work();
	return 0;
}
