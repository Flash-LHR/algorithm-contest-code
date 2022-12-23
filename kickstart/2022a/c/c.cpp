#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

int n;
char s[M + 5];

bool is(int l, int r)
{
	int len = r - l + 1;
	for (int i = 0; i < len / 2; ++i)
		if (s[l + i] != s[r - i])
			return false;
	return true;
}

bool check(int u)
{
	if (u < 5) return true;
	if (is(u - 4, u)) return false;
	if (u > 5 && is(u - 5, u)) return false;
	return true;
}

bool dfs(int u)
{
	if (u == n + 1) return true;
	if (s[u] == '?') {
		s[u] = '0'; if (check(u) && dfs(u + 1)) return true;
		s[u] = '1'; if (check(u) && dfs(u + 1)) return true;
		s[u] = '?';
		return false;
	} else return check(u) && dfs(u + 1);
}

void work()
{
	scanf("%d %s", &n, s + 1);
	if (dfs(1)) printf("POSSIBLE\n");
	else printf("IMPOSSIBLE\n");
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
