#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

void work()
{
	int l, r, x, a, b; scanf("%d %d %d %d %d", &l, &r, &x, &a, &b);
	if (a == b) return printf("0\n"), void();
	if ((int)abs(a - b) >= x) return printf("1\n"), void();
	int lc = inf, rc = inf;
	if (a - l >= x) lc = 1;
	else if (r - a >= x && r - l >= x) lc = 2;
	if (r - a >= x) rc = 1;
	else if (a - l >= x && r - l >= x) rc = 2;
	int ans = inf;
	if (b - l >= x) ans = min(ans, lc + 1);
	if (r - b >= x) ans = min(ans, rc + 1);
	printf("%d\n", ans == inf ? -1 : ans);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
