#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;
const int N = 30;

struct trie {
	int cnt;
	int nx[M * (N + 1) + 5][2];

	trie() {
		cnt = 1;
		memset(nx, 0, sizeof nx);
	}

	void insert(int a) {
		int u = 1;
		for(int i = N, v; ~i; --i) {
			v = (a>>i&1);
			if(nx[u][v] == 0) nx[u][v] = ++cnt;
			u = nx[u][v];
		}
	}

	int query(int a) {
		int u = 1, ans = 0;
		for(int i = N, v; ~i; --i) {
			v = (a>>i&1);
			if(nx[u][!v]) u = nx[u][!v], ans |= (1<<i);
			else u = nx[u][v];
		}
		return ans;
	}
} tr;

void work() {
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i = 1, a; i <= n; ++i) {
		scanf("%d", &a);
		tr.insert(a);
		ans = max(ans, tr.query(a));
	}
	printf("%d\n", ans);
}

int main() {
	work();
	return 0;
}
