#include <bits/stdc++.h>
using namespace std;

const int M = (int)2e5;
const int N = (int)2e6;

struct Trie {
	int tot;
	int nx[M + 5][26], tr[M + 5][26];
	int fail[M + 5], q[M + 5], pos[M + 5], f[M + 5];

	void clear() {
		tot = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
	}

	int newnode() {
		++tot;
		memset(nx[tot], 0, sizeof nx[tot]);
		return tot;
	}

	void insert(char *s, int id) {
		int u = 0;
		for(int i = 0, v; s[i]; ++i) {
			v = s[i] - 'a';
			if(nx[u][v] == 0) nx[u][v] = newnode();
			u = nx[u][v];
		}
		pos[id] = u;
		f[id] = 0;
	}

	void build() {
		int l = 1, r = 0;
		fail[0] = 0;
		for(int i = 0; i < 26; ++i) if(nx[0][i]) {
			tr[0][i] = nx[0][i];
			fail[nx[0][i]] = 0;
			q[++r] = nx[0][i];
		} else tr[0][i] = 0;
		while(l <= r) {
			int u = q[l++];
			for(int i = 0; i < 26; ++i) if(nx[u][i]) {
				tr[u][i] = nx[u][i];
				fail[nx[u][i]] = tr[fail[u]][i];
				q[++r] = nx[u][i];
			} else tr[u][i] = tr[fail[u]][i];
		}
	}

	void query(char *s, int n) {
		int u = 0;
		for(int i = 0; s[i]; ++i) {
			u = tr[u][s[i] - 'a'];
			++f[u];
		}
		for(int i = tot; i; --i) f[fail[q[i]]] += f[q[i]];
		for(int i = 0; i < n; ++i) printf("%d\n", f[pos[i]]);
	}
} trie;

char s[N + 5];

void work() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%s", s);
		trie.insert(s, i);
	}
	trie.build();
	scanf("%s", s);
	trie.query(s, n);
}

int main() {
	work();
	return 0;
}
