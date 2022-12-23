#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const int inf = 0x3f3f3f3f;

int a[M + 5];
ll s[M + 5];
int f[M + 5];

int sign(ll n)
{
	if (n < 0) return -1;
	if (n > 0) return 1;
	return 0;
}

void work()
{
	int n, h; scanf("%d %d", &n, &h);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		f[i] = -inf;
		for (int j = 0; j < i; ++j)
			f[i] = max(f[i], f[j] + (i - j) * sign(s[i] - s[j]));
		//printf("f[%d]=%d\n", i, f[i]);
	}
	printf("%d %d\n", f[n], f[n] >= h);
}

int main()
{
	int T; scanf("%d", &T);
	while (T--) work();

	return 0;
}
