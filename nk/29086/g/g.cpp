#include <bits/stdc++.h>
using namespace std;

const int M = (int)1500;
const int mod = (int)1e9 + 7;

char s[M + 5];
char num[M + 5];

struct Trie {
	int tot;
	int nx[M + 5][10], go[M + 5][10];
	int q[M + 5], fail[M + 5];
	bool ending[M + 5];
	int f[M + 5][M + 5];

	void clear() {
		tot = 0;
		ending[tot] = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
	}

	int newnode() {
		++tot;
		ending[tot] = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
		return tot;
	}

	void insert() {
		int u = 0;
		for(int i = 0, v; s[i]; ++i) {
			v = s[i] - '0';
			if(nx[u][v] == 0) nx[u][v] = newnode();
			u = nx[u][v];
		}
		ending[u] = 1;
	}

	void build() {
		int l = 1, r = 0;
		fail[0] = 0;
		for(int i = 0; i < 10; ++i) if(nx[0][i]) {
			go[0][i] = nx[0][i];
			fail[nx[0][i]] = 0;
			q[++r] = nx[0][i];
		}
		while(l <= r) {
			int u = q[l++];
			for(int i = 0; i < 10; ++i) if(nx[u][i]) {
				go[u][i] = nx[u][i];
				fail[nx[u][i]] = go[fail[u]][i];
				ending[nx[u][i]] |= ending[fail[nx[u][i]]];
				q[++r] = nx[u][i];
			} else go[u][i] = go[fail[u]][i];
		}
	}

	int dfs(int pos, int cur, bool lim, bool lea) {
		if(pos == -1) return !lea;
		if(!lim && !lea && ~f[pos][cur]) return f[pos][cur];
		int res = 0, up = (lim ? num[pos] - '0' : 9);
		for(int i = 0; i <= up; ++i) {
			if(lea && i == 0) (res += dfs(pos - 1, cur, lim && i == up, lea && i == 0)) %= mod;
			else if(!ending[go[cur][i]]) (res += dfs(pos - 1, go[cur][i], lim && i == up, lea && i == 0)) %= mod;
		}
		if(!lim && !lea) f[pos][cur] = res;
		return res;
	}

	int query() {
		int n = strlen(num);
		reverse(num, num + n);
		for(int i = 0; i < n; ++i) for(int j = 0; j <= tot; ++j) f[i][j] = -1;
		return dfs(n - 1, 0, 1, 1);
	}
} trie;

void work() {
	int m; scanf("%s%d", num, &m);
	trie.clear();
	for(int i = 0; i < m; ++i) {
		scanf("%s", s);
		trie.insert();
	}
	trie.build();
	printf("%d\n", trie.query());
}

int main() {
	work();
	return 0;
}
