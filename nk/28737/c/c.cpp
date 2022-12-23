#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;
const int N = 20;

struct trie {
	int cnt;
	int nx[M * (N + 1) + 5][2];
	int id[M * (N + 1) + 5];

	trie() {
		cnt = 1;
		memset(nx, 0, sizeof nx);
	}

	void insert(int a, int b) {
		int u = 1;
		for(int i = N, v; i >= 0; --i) {
			v = (a>>i&1);
			if(nx[u][v] == 0) nx[u][v] = ++cnt;
			u = nx[u][v];
		}
		id[u] = b;
	}

	pair<int, int> query(int a) {
		int u = 1, ans = 0;
		for(int i = N, v; i >= 0; --i) {
			v = (a>>i&1);
			if(nx[u][!v]) u = nx[u][!v], ans |= (1<<i);
			else u = nx[u][v];
		}
		return {ans, id[u]};
	}
} tr;

void work() {
	int n; scanf("%d", &n);
	tr.insert(0, 0); int mx = -1, l, r;
	for(int i = 1, a, s = 0; i <= n; ++i) {
		scanf("%d", &a);
		pair<int, int> p = tr.query(s^=a);
		if(p.first > mx) mx = p.first, l = p.second, r = i;
		tr.insert(s, i);
	}
	printf("%d %d %d\n", mx, l + 1, r);
}

int main() {
	work();
	return 0;
}
