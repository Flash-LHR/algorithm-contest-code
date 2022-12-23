#include <bits/stdc++.h>
using namespace std;

const int M = (int)2e5;
const int N = (int)17;

string s[M + 5];

struct Trie {
	int tot;
	int fail[M + 5], q[M + 5], pos[M + 5];
	int nx[M + 5][26], go[M + 5][26];

	void clear() {
		tot = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
	}

	int newnode() {
		++tot;
		memset(nx[tot], 0, sizeof nx[tot]);
		return tot;
	}

	void insert(int id) {
		int u = 0;
		for(int i = 0, v; i < (int)s[id].size(); ++i) {
			v = s[id][i] - 'a';
			if(nx[u][v] == 0) nx[u][v] = newnode();
			u = nx[u][v];
		}
		pos[id] = u;
	}

	void build() {
		int l = 1, r = 0;
		fail[0] = 0;
		for(int i = 0; i < 26; ++i) if(nx[0][i]) {
			go[0][i] = nx[0][i];
			fail[nx[0][i]] = 0;
			q[++r] = nx[0][i];
		} else go[0][i] = 0;
		while(l <= r) {
			int u = q[l++];
			for(int i = 0; i < 26; ++i) if(nx[u][i]) {
				go[u][i] = nx[u][i];
				fail[nx[u][i]] = go[fail[u]][i];
				q[++r] = nx[u][i];
			} else go[u][i] = go[fail[u]][i];
		}
	}

	vector<int> g[M + 5];
	int st[M + 5], en[M + 5], dfn;
	struct segTree {
		int tot;
		int rt[M + 5];
		int lc[2 * M * (N + 1) + M + 5], rc[2 * M * (N + 1) + M + 5];
		int sum[2 * M * (N + 1) + M + 5];

		void clear() {
			tot = 0;
			lc[tot] = 0, rc[tot] = 0;
		}

		void update(int x, int y, int l, int r, int a, int b) {
			if(l == r) return;
			int mid = (l + r) >> 1;
			if(a <= mid) {
				int lcx = lc[x];
				sum[++tot] = sum[lc[x]] + b;
				lc[y] = tot, rc[y] = rc[x];
				update(lcx, lc[y], l, mid, a, b);
			} else {
				int rcx = rc[x];
				sum[++tot] = sum[rc[x]] + b;
				lc[y] = lc[x], rc[y] = tot;
				update(rcx, rc[y], mid + 1, r, a, b);
			}
		}

		int query(int x, int y, int l, int r, int a, int b) {
			if(a <= l && r <= b) return sum[y] - sum[x];
			int mid = (l + r) >> 1, s = 0;
			if(a <= mid) s += query(lc[x], lc[y], l, mid, a, b);
			if(mid < b)  s += query(rc[x], rc[y], mid + 1, r, a, b);
			return s;
		}
	} tr;

	void dfs(int u) {
		st[u] = ++dfn;
		for(const int &v: g[u]) dfs(v);
		en[u] = dfn;
	}

	void gao(int n) {
		for(int i = 0; i <= tot; ++i) g[i].clear();
		for(int i = 1; i <= tot; ++i) g[fail[i]].push_back(i);
		dfn = 0; dfs(0);
		for(int i = 0; i < n; ++i) {
			tr.rt[i + 1] = ++tr.tot;
			for(int j = 0, u = 0; j < (int)s[i].size(); ++j) {
				u = go[u][s[i][j] - 'a'];
				if(j == 0) tr.update(tr.rt[i], tr.rt[i + 1], 1, tot + 1, st[u], 1);
				else tr.update(tr.rt[i + 1], tr.rt[i + 1], 1, tot + 1, st[u], 1);
			}
		}
	}

	int query(int l, int r, int k) {
		return tr.query(tr.rt[l - 1], tr.rt[r], 1, tot + 1, st[pos[k - 1]], en[pos[k - 1]]);
	}
} trie;

void work() {
	int n, q; cin >> n >> q;
	trie.clear();
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		trie.insert(i);
	}
	trie.build();
	trie.gao(n);
	for(int i = 0, l, r, k; i < q; ++i) {
		cin >> l >> r >> k;
		cout << trie.query(l, r, k) << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	work();
	return 0;
}
