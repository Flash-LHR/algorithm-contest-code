#include <bits/stdc++.h>
using namespace std;

const int M = (int)2e5;

char s[M + 5];

void print(int p, char ch)
{
	char tmp = s[p + 1];
	s[p + 1] = '\0';
	printf("%s%c", s + 1, ch);
	s[p + 1] = tmp;
	printf("%s\n", s + p + 1);
}

void work()
{
	scanf("%s", s + 1);
	int n = (int)strlen(s + 1), sum = 0;
	for (int i = 1; i <= n; ++i) (sum += s[i] - '0') %= 9;
	int rem = (9 - sum) % 9;
	if (rem) {
		for (int i = 1; i <= n; ++i)
			if (s[i] - '0' > rem)
				return print(i - 1, rem + '0');
		print(n, rem + '0');
	} else print(1, rem + '0');
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
