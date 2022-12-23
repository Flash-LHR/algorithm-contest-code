#include <bits/stdc++.h>
using namespace std;

const int M = (int)3e6;
const int N = (int)1e5;

struct ACAM {
	int tot;
	int nx[M + 5][26];
	int fail[M + 5];
	int q[M + 5];
	int pos[N * 2 + 5];

	void clear() {
		tot = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
		fail[tot] = 0;
	}

	int newnode() {
		++tot;
		memset(nx[tot], 0, sizeof nx[tot]);
		fail[tot] = 0;
		return tot;
	}

	void insert(const string &s, int id) {
		int u = 0;
		for(int i = 0, v; i < (int)s.size(); ++i) {
			v = s[i] - 'a';
			if(nx[u][v] == 0) nx[u][v] = newnode();
			u = nx[u][v];
		}
		pos[id] = u;
	}

	struct TA {
		int n, a[M + 5];
		void init(int _n) {n = _n; memset(a, 0, sizeof(int) * (n + 1));}
		int lowbit(int n) {return n&-n;}
		void add(int p, int x) {while(p <= n) a[p] += x, p += lowbit(p);}
		int ask(int p) {int s = 0; while(p) s += a[p], p -= lowbit(p); return s;}
		int ask(int l, int r) {return ask(r) - ask(l - 1);}
	} tr;
	
	vector<int> g[M + 5];
	int st[M + 5], en[M + 5], dfn;

	void dfs(int u) {
		st[u] = ++dfn;
		for(const int &v: g[u]) dfs(v);
		en[u] = dfn;
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
		dfn = 0; dfs(0);
		tr.init(tot + 1);
	}

	void update(int id) {
		tr.add(st[pos[id]], 1);
		tr.add(en[pos[id]] + 1, -1);
	}

	int query(const string &s) {
		int u = 0, ans = 0;
		for(int i = 0, v; i < (int)s.size(); ++i) {
			v = s[i] - 'a';
			while(u && nx[u][v] == 0) u = fail[u];
			if(nx[u][v]) {
				u = nx[u][v];
				ans += tr.ask(st[u]);
			}
		}
		return ans;
	}
} acam;

int n, m;
string s;
struct qnode {
	int op;
	string s;
} q[N + 5];

void work() {
	acam.clear();
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		acam.insert(s, i);
	}
	for(int i = 0; i < m; ++i) {
		cin >> q[i].op >> q[i].s;
		if(q[i].op == 1) acam.insert(q[i].s, n + i);
	}
	acam.build();
	for(int i = 0; i < n; ++i) acam.update(i);
	for(int i = 0; i < m; ++i) {
		if(q[i].op == 1) acam.update(n + i);
		else cout << acam.query(q[i].s) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) work();
	return 0;
}
