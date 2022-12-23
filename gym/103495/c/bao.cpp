#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[10];
string ans, cur;

void dfs(int s, int pre) {
	if(s == 0) {
		if(ans == "") ans = cur;
		else ans = min(ans, cur);
		return;
	}
	for(int i = 0; i <= 9; ++i) if(i != pre && a[i]) {
		--a[i];
		cur.push_back(i + '0');
		dfs(s - 1, i);
		cur.pop_back();
		++a[i];
	}
}

void work() {
	for(int i = 0; i <= 9; ++i) scanf("%d", &a[i]);
	int s = accumulate(a, a + 10, 0);
	if(s == 1) {
		for(int i = 0; i <= 9; ++i) if(a[i]) printf("%d\n", i);
		return;
	}
	ans = "", cur = "";
	dfs(s, 0);
	if(ans == "") cout << -1 << "\n";
	else cout << ans << "\n";
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
