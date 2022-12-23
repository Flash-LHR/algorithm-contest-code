#include <bits/stdc++.h>
using namespace std;

const int M = (int)3e4;

struct Trie {
	int tot;
	int nx[M + 5][2], go[M + 5][2];
	int q[M + 5], fail[M + 5], in[M + 5];
	bool ending[M + 5], vis[M + 5];

	void clear() {
		tot = 0;
		ending[tot] = 0;
		in[tot] = 0;
		vis[tot] = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
	}

	int newnode() {
		++tot;
		ending[tot] = 0;
		in[tot] = 0;
		vis[tot] = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
		return tot;
	}

	void insert(char *s) {
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
		for(int i = 0; i < 2; ++i) if(nx[0][i]) {
			go[0][i] = nx[0][i];
			fail[nx[0][i]] = 0;
			q[++r] = nx[0][i];
		} else go[0][i] = 0;
		while(l <= r) {
			int u = q[l++];
			for(int i = 0; i < 2; ++i) if(nx[u][i]) {
				go[u][i] = nx[u][i];
				fail[nx[u][i]] = go[fail[u]][i];
				q[++r] = nx[u][i];
			} else go[u][i] = go[fail[u]][i];
		}
		for(int i = 1; i <= tot; ++i) ending[q[i]] |= ending[fail[q[i]]];
	}

	bool query() {
		int cnt1 = 0, cnt2 = 0, l = 1, r = 0;
		q[++r] = 0, vis[0] = 1;
		while(l <= r) {
			int u = q[l++];
			++cnt1;
			for(int i = 0; i < 2; ++i) if(!ending[go[u][i]] && !vis[go[u][i]]) {
				vis[go[u][i]] = 1;
				q[++r] = go[u][i];
			}
		}
		for(int i = 0; i <= tot; ++i) if(vis[i]) {
			if(vis[go[i][0]]) ++in[go[i][0]];
			if(vis[go[i][1]]) ++in[go[i][1]];
		}
		if(in[0]) return 1;
		l = 1, r = 0;
		q[++r] = 0;
		while(l <= r) {
			int u = q[l++];
			++cnt2;
			for(int i = 0; i < 2; ++i) if(vis[go[u][i]]) {
				if(--in[go[u][i]] == 0) q[++r] = go[u][i];
			}
		}
		return cnt1 != cnt2;
	}
} trie;

char s[M + 5];

void work() {
	int n; scanf("%d", &n);
	trie.clear();
	for(int i = 0; i < n; ++i) {
		scanf("%s", s);
		trie.insert(s);
	}
	trie.build();
	puts(trie.query() ? "TAK" : "NIE");
}

int main() {
	work();
	return 0;
}
