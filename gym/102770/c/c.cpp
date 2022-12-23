#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e3;

int n, m;
char s[M + 5][M + 5], t[M + 5];
bool vis[M + 5][M + 5];

struct trie {
	int tot;
	int nx[4 * M * M + 5][26];
	int f[4 * M * M + 5];
	
	void clear() {
		tot = 0;
		memset(nx[0], 0, sizeof nx[0]);
		f[0] = 0;
	}

	int newnode() {
		++tot;
		memset(nx[tot], 0, sizeof nx[tot]);
		f[tot] = 0;
		return tot;
	}

	void insert(int w) {
		int u = 0, v; int len = strlen(t);
		for(int i = 0; i < len; ++i) {
			v = t[i] - 'a';
			if(nx[u][v] == 0) nx[u][v] = newnode();
			u = nx[u][v];
		}
		f[u] += w;
	}

	int queryr(int p, int l, int r) {
		int u = 0, v;
		for(int i = l; i <= r; ++i) {
			v = s[p][i] - 'a';
			if(nx[u][v] == 0) return 0;
			u = nx[u][v];
		}
		return f[u];
	}
	int queryc(int p, int l, int r) {
		int u = 0, v;
		for(int i = l; i <= r; ++i) {
			v = s[i][p] - 'a';
			if(nx[u][v] == 0) return 0;
			u = nx[u][v];
		}
		return f[u];
	}
} tr;

void work() {
	scanf("%d %d", &n, &m);
	tr.clear();
	for(int i = 0; i < n; ++i) scanf("%s", s[i]);
	for(int i = 0, w; i < m; ++i) {
		scanf("%s %d", t, &w);
		tr.insert(w);
	}
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		if(ans == -1) break;
		for(int l = 0, r = -1; l < n; l = r + 1) {
			if(ans == -1) break;
			if(s[i][l] == '#') {
				++r;
				continue;
			}
			while(r + 1 < n && s[i][r + 1] != '#') ++r;
			if(!(l == r && vis[i][l])) {
				int cur = tr.queryr(i, l, r);
				if(cur == 0) ans = -1;
				else ans += cur;
			}
			++r;
		}
		for(int l = 0, r = -1; l < n; l = r + 1) {
			if(ans == -1) break;
			if(s[l][i] == '#') {
				++r;
				continue;
			}
			while(r + 1 < n && s[r + 1][i] != '#') ++r;
			if(!(l == r && vis[l][i])) {
				int cur = tr.queryc(i, l, r);
				if(cur == 0) ans = -1;
				else ans += cur;
			}
			++r;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
