#include <bits/stdc++.h>
using namespace std;

void work()
{
	int n, s; scanf("%d %d", &n, &s);
	vector<int> v(n);
	for(int &x: v) scanf("%d", &x);
	sort(v.begin(), v.end());
	if (v[0] > 1) {
		int t = v[0] * (v[0] - 1) / 2;
		if (s >= t) s -= t;
		else return puts("NO"), void();
	}
	for (size_t i = 1; i < v.size(); ++i) {
		if (v[i] == v[i - 1]) return puts("NO"), void();
		int t = (v[i] - 1 - v[i - 1]) * (v[i - 1] + v[i]) / 2;
		if (s >= t) s -= t;
		else return puts("NO"), void();
	}
	for (int i = v.back() + 1; s >= i; ++i) s -= i;
	puts(s ? "NO" : "YES");
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
