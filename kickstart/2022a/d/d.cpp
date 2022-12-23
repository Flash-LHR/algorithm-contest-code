#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int num[20];
ll f[20][110][110][110];

ll dfs(int pos, int tar, int sum, int pro, bool lim, bool lead)
{
	if (pos == -1) return sum == tar && pro % sum == 0;
	if (!lim && !lead && ~f[pos][tar][sum][pro]) return f[pos][tar][sum][pro];
	int up = (lim ? num[pos] : 9); ll res = 0;
	for (int i = 0; i <= up; ++i) {
		if (lead && i == 0) res += dfs(pos - 1, tar, sum, pro, lim && i == up, lead && i == 0);
		else res += dfs(pos - 1, tar, sum + i, pro * i % tar, lim && i == up, lead && i == 0);
	}
	if (!lim && !lead) f[pos][tar][sum][pro] = res;
	return res;
}

ll cal(ll n)
{
	int pos = 0;
	while (n) {
		num[pos++] = n % 10;
		n /= 10;
	}
	ll ans = 0;
	for (int i = 1; i <= 108; ++i)
		ans += dfs(pos - 1, i, 0, 1, 1, 1);
	return ans;
}

void work()
{
	ll l, r; scanf("%lld %lld", &l, &r);
	printf("%lld\n", cal(r) - cal(l - 1));
}

int main()
{
	memset(f, -1, sizeof(f));
	int T; scanf("%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
		printf("Case #%d: ", ca);
		work();
	}
	return 0;
}
