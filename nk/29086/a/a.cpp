#include <bits/stdc++.h>
using namespace std;

const int M = (int)2e5;

int n;
char s[M * 10 + 5];

struct ACAM {
	int tot;
	int nx[M + 5][26];
	int fail[M + 5];
	int pos[M + 5];
	int q[M + 5];
	int f[M + 5];

	void clear() {
		tot = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
		fail[tot] = 0;
		f[tot] = 0;
	}

	int newnode() {
		++tot;
		memset(nx[tot], 0, sizeof nx[tot]);
		fail[tot] = 0;
		f[tot] = 0;
		return tot;
	}

	void insert(int id) {
		int u = 0;
		for(int i = 0, v; s[i]; ++i) {
			v = s[i] - 'a';
			if(nx[u][v] == 0) nx[u][v] = newnode();
			u = nx[u][v];
		}
		pos[id] = u;
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
	}

	void query() {
		int u = 0;
		for(int i = 0, v; s[i]; ++i) {
			v = s[i] - 'a';
			while(u && nx[u][v] == 0) u = fail[u];
			if(nx[u][v]) u = nx[u][v];
			++f[u];
		}
		for(int i = tot; i >= 1; --i) f[fail[q[i]]] += f[q[i]];
		for(int i = 0; i < n; ++i) printf("%d\n", f[pos[i]]);
	}
} acam;

void work() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%s", s);
		acam.insert(i);
	}
	acam.build();
	scanf("%s", s);
	acam.query();
}

int main() {
	work();
	return 0;
}
