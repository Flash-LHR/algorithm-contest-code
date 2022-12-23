#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

char s[M + 5], t[M + 5];

void work()
{
	scanf("%s%s", s + 1, t + 1);
	int n = strlen(s + 1), m = strlen(t + 1);
	int i = 1, j = 1;
	while (i <= n) {
		while (j <= m && s[i] != t[j]) ++j;
		if (j == m + 1) return printf("IMPOSSIBLE\n"), void();
		++i, ++j;
	}
	printf("%d\n", m - n);
}

int main()
{
	int T; scanf("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		printf("Case #%d: ", ca);
		work();
	}
	return 0;
}
