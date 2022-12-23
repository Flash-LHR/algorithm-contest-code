#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e6;

char s[M + 5];
int nx[M + 5];
bool vis[M + 5];

void work() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 2; i <= n; ++i) {
		nx[i] = nx[i - 1];
		while(nx[i] && s[nx[i] + 1] != s[i]) nx[i] = nx[nx[i]];
		if(s[nx[i] + 1] == s[i]) ++nx[i];
		if(i < n) vis[nx[i]] = true;
	}
	if(nx[n] && vis[nx[n]]) return s[nx[n] + 1] = '\0', printf("%s\n", s + 1), void();
	if(nx[nx[n]]) return s[nx[nx[n]] + 1] = '\0', printf("%s\n", s + 1), void();
	printf("Just a legend\n");
}
	
int main() {
	work();
	return 0;
}

