#include <bits/stdc++.h>
using namespace std;

int cal(int a, int b)
{
	int c = 0;
	while (a % b == 0) ++c, a /= b;
	return c;
}

void work()
{
	int a, b; scanf("%d %d", &a, &b);
	int a2 = cal(a, 2), a5 = cal(a, 5);
	int c = 1;
	while (c * 2 <= b && a2 < a5) c *= 2, ++a2;
	while (c * 5 <= b && a2 > a5) c *= 5, ++a5;
	while (c * 10ll <= b) c *= 10;
	printf("%lld\n", (long long)b / c * a * c);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
