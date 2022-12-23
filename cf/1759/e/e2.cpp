#include <bits/stdc++.h>
using namespace std;

void work()
{
	int n, h; scanf("%d %d", &n, &h);
	vector<int> v(n);
	for(int &x: v) scanf("%d", &x);
	sort(v.begin(), v.end());
	int p[3] = {2, 2, 3};
	int mx = 0;
	do {
		long long cur = h;
		for (size_t i = 0, j = 0; i < v.size(); ++i) {
			while (j < 3 && cur <= v[i]) cur *= p[j++];
			if (cur > v[i]) mx = max(mx, (int)i + 1), cur += v[i] / 2;
		}
	} while (next_permutation(p, p + 3));
	printf("%d\n", mx);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
