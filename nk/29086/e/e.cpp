#include <bits/stdc++.h>
using namespace std;

const int M = (int)6e3;
const int N = (int)1e4;
const int mod = 10007;

short quick(short a, short b, short p) {
	short s = 1;
	while(b) {
		if(b & 1) s = (int)s * a % p;
		a = (int)a * a % p;
		b >>= 1;
	}
	return s % p;
}

struct ACAM {
	short tot;
	short nx[M + 5][26];
	short fail[M + 5];
	bool ending[M + 5];
	short q[M + 5];
	vector<short> g[M + 5];
	short h[M + 5][26];
	short f[N + 5][M + 5];

	void clear() {
		tot = 0;
		ending[tot] = 0;
		memset(h[tot], 0, sizeof h[tot]);
		memset(nx[tot], 0, sizeof nx[tot]);
		fail[tot] = 0;
	}

	short newnode() {
		++tot;
		ending[tot] = 0;
		memset(h[tot], 0, sizeof h[tot]);
		memset(nx[tot], 0, sizeof nx[tot]);
		fail[tot] = 0;
		return tot;
	}

	void insert(char *s) {
		short u = 0;
		for(short i = 0, v; s[i]; ++i) {
			v = s[i] - 'A';
			if(nx[u][v] == 0) nx[u][v] = newnode();
			u = nx[u][v];
		}
		ending[u] = 1;
	}

	void dfs(int u) {
		for(const short &v: g[u]) {
			if(ending[u]) ending[v] = 1;
			dfs(v);
		}
	}

	void build() {
		short l = 1, r = 0;
		for(short i = 0; i < 26; ++i) if(nx[0][i]) {
			fail[nx[0][i]] = 0;
			h[0][i] = nx[0][i];
			q[++r] = nx[0][i];
		}
		while(l <= r) {
			short u = q[l++];
			for(short i = 0, v; i < 26; ++i) if(nx[u][i]) {
				v = nx[u][i];
				fail[v] = fail[u];
				while(fail[v] && nx[fail[v]][i] == 0) fail[v] = fail[fail[v]];
				if(nx[fail[v]][i]) fail[v] = nx[fail[v]][i];
				h[u][i] = v;
				q[++r] = v;
			} else h[u][i] = h[fail[u]][i];
		}
		for(short i = 0; i <= tot; ++i) g[i].clear();
		for(short i = 1; i <= tot; ++i) g[fail[i]].push_back(i);
		dfs(0);
	}

	short query(short m) {
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		for(short i = 0; i < m; ++i) {
			for(short j = 0; j <= tot; ++j) if(f[i][j]) {
				for(short k = 0; k < 26; ++k) if(!ending[h[j][k]]) {
					(f[i + 1][h[j][k]] += f[i][j]) %= mod;
				}
			}
		}
		return (quick(26, m, mod) - accumulate(f[m], f[m] + tot + 1, 0) % mod + mod) % mod;
	}
} acam;

char s[N + 5];

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

