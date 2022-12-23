#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

int n;
char s[M + 5];
int nx[M + 5];

void work() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 2; i <= n; ++i) if(s[i] == s[1]) {
		printf("Wrong Answer\n");
		return;
	}
	printf("Correct\n");/*
	nx[1] = 0;
	for(int i = 2, j = 0; i <= n; ++i) {
		while(j && s[i] != s[j + 1]) j = nx[j];
		if(s[i] == s[j + 1]) ++j;
		nx[i] = j;
	}
	puts(nx[n] ? "Wrong Answer" : "Correct");*/
}

int main() {
	work();
	return 0;
}
