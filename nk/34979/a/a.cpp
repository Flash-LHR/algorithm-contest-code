#include <bits/stdc++.h>
using namespace std;

const int M = (int)1.1e7;

struct Manacher {
	int n;
	char s[M * 2 + 5];
	int len[M * 2 + 5];

	void init(char *t) {
		int m = strlen(t + 1);
		for(int i = 1; i <= m; ++i)
			s[i * 2 - 1] = '#', 
			s[i * 2] = t[i];
		s[0] = '$', s[2 * m + 1] = '#', s[2 * m + 2] = '\0';
		n = 2 * m + 1;
	}

	void build() {
		len[1] = 1;
		for(int i = 1, p = 1, r = 1; i <= n; ++i) {
			if(i <= r) len[i] = min(len[2 * p - i], r - i + 1);
			while(s[i - len[i]] == s[i + len[i]]) ++len[i];
			if(i + len[i] - 1 > r) p = i, r = i + len[i] - 1;
		}
	}

	int solve() {
		return *max_element(len + 1, len + n + 1) - 1;
	}
} man;

char s[M + 5];

void work() {
	scanf("%s", s + 1);
	man.init(s);
	man.build();
	printf("%d\n", man.solve());
}

int main() {
	work();
	return 0;
}
