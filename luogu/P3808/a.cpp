#include <bits/stdc++.h>
using namespace std;

const int M = (int)2e5;
const int N = (int)2e6;

struct ACAM {
	int cnt;
	int fail[M + 5];
	int nx[M + 5][26];
	int q[M + 5], f[M + 5];
	int pos[M + 5];

	ACAM() {
		f[0] = 0;
		cnt = fail[0] = 0;
		memset(nx[0], 0, sizeof nx[0]);
	}

	int newnode() {
		++cnt;
		f[cnt] = 0;
		fail[cnt] = 0;
		memset(nx[cnt], 0, sizeof nx[cnt]);
		return cnt;
	}

	void insert(char *s, int id) {
		int u = 0;
		for(size_t i = 0, v; s[i]; ++i) {
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

	void query(char *s, int n) {
		for(int i = 0, u = 0, v; s[i]; ++i) {
			v = s[i] - 'a';
			while(u && nx[u][v] == 0) u = fail[u];
			if(nx[u][v]) u = nx[u][v];
			++f[u];
		}
		for(int i = cnt; i; --i) f[fail[q[i]]] += f[q[i]];
		for(int i = 0; i < n; ++i) printf("%d\n", f[pos[i]]);
	}
} acam;

char s[N + 5];

void work() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%s", s);
		acam.insert(s, i);
	}
	acam.build();
	scanf("%s", s);
	acam.query(s, n);
}

int main() {
	work();
	return 0;
}

