#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)6e3;
const int mod = 10007;

int quick(int a, int b, int p) {
	int s = 1;
	while(b) {
		if(b & 1) s = (ll)s * a % p;
		a = (ll)a * a % p;
		b >>= 1;
	}
	return s % p;
}

struct ACAM {
	int tot;
	int nx[M + 5][26];
	int fail[M + 5];
	bool ending[M + 5];
	int q[M + 5];
	vector<int> g[M + 5];
	int h[M + 5][26];
	int f[105][M + 5];

	void clear() {
		tot = 0;
		ending[tot] = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
		fail[tot] = 0;
	}

	int newnode() {
		++tot;
		ending[tot] = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
		fail[tot] = 0;
		return tot;
	}

	void insert(char *s) {
		int u = 0;
		for(int i = 0, v; s[i]; ++i) {
			v = s[i] - 'A';
			if(nx[u][v] == 0) nx[u][v] = newnode();
			u = nx[u][v];
		}
		ending[u] = 1;
	}

	void dfs(int u) {
		for(const int &v: g[u]) {
			if(ending[u]) ending[v] = 1;
			dfs(v);
		}
	}

	void build() {
		int l = 1, r = 0;
		for(int i = 0; i < 26; ++i) if(nx[0][i]) {
			fail[nx[0][i]] = 0;
			q[++r] = nx[0][i];
		}
		while(l <= r) {
			int u = q[l++];
			for(int i = 0, v; i < 26; ++i) if(nx[u][i]) {
				v = nx[u][i];
				fail[v] = fail[u];
				while(fail[v] && nx[fail[v]][i] == 0) fail[v] = fail[fail[v]];
				if(nx[fail[v]][i]) fail[v] = nx[fail[v]][i];
				q[++r] = v;
			}
		}
		for(int i = 0; i <= tot; ++i) g[i].clear();
		for(int i = 1; i <= tot; ++i) g[fail[i]].push_back(i);
		dfs(0);
	}

	int query(int m) {
		for(int i = 0; i <= tot; ++i) {
			for(int j = 0; j < 26; ++j) {
				int k = i;
				while(k && nx[k][j] == 0) k = fail[k];
				if(nx[k][j]) k = nx[k][j];
				h[i][j] = k;
			}
		}
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j <= tot; ++j) if(f[i][j]) {
				for(int k = 0; k < 26; ++k) if(!ending[h[j][k]]) {
					(f[i + 1][h[j][k]] += f[i][j]) %= mod;
				}
			}
		}
		return (quick(26, m, mod) - accumulate(f[m], f[m] + tot + 1, 0) % mod + mod) % mod;
	}
} acam;

char s[M + 5];

void work() {
	int n, m; scanf("%d %d", &n, &m);
	acam.clear();
	for(int i = 0; i < n; ++i) {
		scanf("%s", s);
		acam.insert(s);
	}
	acam.build();
	printf("%d\n", acam.query(m));
}

int main() {
	work();
	return 0;
}
