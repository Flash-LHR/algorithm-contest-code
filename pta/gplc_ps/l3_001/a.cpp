#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e4;
const int N = (int)1e2;

int n, m;
int a[M + 5];
bitset<N + 5> f[M + 5];

void work() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);
	f[0] = 1; for(int i = 1; i <= n; ++i) f[i] = f[i-1]|(f[i-1]<<a[i]);
	if(!f[n][m]) return printf("No Solution\n"), void();
	vector<int> ans;
	for(int i = n; i >= 1; --i) {
		if(m >= a[i] && f[i - 1][m - a[i]]) m -= a[i], ans.push_back(a[i]);
	}
	for(int i = 0; i < (int)ans.size(); ++i) printf("%d%c", ans[i], " \n"[i == (int)ans.size() - 1]);
}

int main() {
	work();
	return 0;
}
