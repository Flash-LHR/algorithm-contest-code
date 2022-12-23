#include <bits/stdc++.h>
using namespace std;

const int M = (int)1.1e7;

struct Manacher {
	int N;
	char ch[M * 2 + 5];
	int len[M * 2 + 5];

	void init(char *s) {
		int n = strlen(s + 1);
		ch[0] = '$';
		for(int i = 1; i <= n; ++i)
			ch[i * 2 - 1] = '#', 
			ch[i * 2] = s[i];
		ch[2 * n + 1] = '#', ch[2 * n + 2] = '\0';
		N = 2 * n + 1;
	}

	void build() {
		for(int i = 1, p = 1, r = 1; i <= N; ++i) {
			if(i <= r) len[i] = min(len[2 * p - i], r - i + 1);
			else len[i] = 1;
			while(ch[i - len[i]] == ch[i + len[i]]) ++len[i];
			if(i + len[i] - 1 > r) p = i, r = i + len[i] - 1;
		}
	}

	int solve() {
		return *max_element(len + 1, len + N + 1) - 1;
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
