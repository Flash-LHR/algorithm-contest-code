#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

int n, m;
char s[M + 5];
char t[M + 5];

void work() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	int j = 1, ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(s[i] != t[j]) j = 1;
		if(s[i] == t[j]) ++j;
		if(j > m) {
			++ans;
			j = 1;
		}
	}
	printf("%d\n", ans);
}

int main() {
	while(1)
	work();
	return 0;
}

