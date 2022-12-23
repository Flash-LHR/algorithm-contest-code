#include <bits/stdc++.h>
using namespace std;

const int M = (int)2e5;
const int N = 18;

struct qnode {
	int op, k;
} a[M + 5];

char s[M * 2 + 5];
int nx[M * 2 + 5];
vector<int> g[M * 2 + 5];
int f[M * 2 + 5][N + 1];
int st[M * 2 + 5], en[M * 2 + 5], dfnCnt;

void dfs(int u) {
	st[u] = ++dfnCnt;
	for(const int &v: g[u]) {
		f[v][0] = u;
		for(int j = 1; j <= N && f[v][j - 1]; ++j) f[v][j] = f[f[v][j - 1]][j - 1];
		dfs(v);
	}
	en[u] = dfnCnt;
}

struct TA {
	int n, a[M * 2 + 5];
	void init(int _n) {n = _n; memset(a, 0, sizeof(int) * (n + 1));}
	int lowbit(int n) {return n&-n;}
	void add(int p, int x) {while(p <= n) a[p] += x, p += lowbit(p);}
	int ask(int p) {int s = 0; while(p) s += a[p], p -= lowbit(p); return s;}
	int ask(int l, int r) {return ask(r) - ask(l - 1);}
} tr;

void work() {
	int n, q, m; scanf("%d %d", &n, &q); m = n;
	scanf("%s", s + 1);
	for(int i = 1; i <= q; ++i) {
		scanf("%d", &a[i].op);
		if(a[i].op == 1) getchar(), s[++m] = getchar(), a[i].k = m;
		else scanf("%d", &a[i].k);
	}
	for(int i = 2, j = 0; i <= m; ++i) {
		while(j && s[i] != s[j + 1]) j = nx[j];
		if(s[i] == s[j + 1]) ++j;
		nx[i] = j;
	}
	for(int i = 1; i <= m; ++i) g[nx[i] + 1].push_back(i + 1);
	dfs(1); tr.init(m + 1);
	for(int i = 1; i <= n; ++i) tr.add(st[i + 1], 1);
	for(int i = 1; i <= q; ++i) {
		if(a[i].op == 1) tr.add(st[a[i].k + 1], 1), ++n;
		else {
			int u = n + 1;
			if(tr.ask(st[u], en[u]) >= a[i].k) {
				printf("%d\n", u);
				continue;
			}
			for(int j = N; j >= 0; --j) if(f[u][j] && tr.ask(st[f[u][j]], en[f[u][j]]) < a[i].k) u = f[u][j];
			if(u == 1 || nx[u - 1] == 0) {
				printf("-1\n");
				continue;
			}
			u = nx[u - 1] + 1;
			printf("%d\n", u - 1);
		}
	}
	
}

int main() {
	work();
	return 0;
}
