#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int M = (int)1e5;

char s[M + 5];

ull input()
{
	scanf("%s", s);
	size_t n = strlen(s);
	ull a = 0;
	for (size_t i = 0; i < n; ++i) a = a * 10 + (s[i] - '0');
	return a;
}

int main()
{
	ull a = input();
	ull b = input();
	ull c = a + b;
	printf("%llu\n", c);
	return 0;
}
