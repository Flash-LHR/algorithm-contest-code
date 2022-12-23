#include <bits/stdc++.h>
using namespace std;

const int M = (int)3e5;
const int inf = 0x3f3f3f3f;

struct ACAM {
	int tot;
	int nx[M + 5][26];
	int fail[M + 5];
	int q[M + 5];
	bool ending[M + 5];
	int dep[M + 5];
	int pre[M + 5];

	void clear() {
		tot = 0;
		ending[tot] = 0;
		dep[tot] = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
		fail[tot] = 0;
	}

	int newnode() {
		++tot;
		ending[tot] = 0;
		dep[tot] = 0;
		memset(nx[tot], 0, sizeof nx[tot]);
		fail[tot] = 0;
		return tot;
	}

	void insert(char *s) {
		int u = 0;
		for(int i = 0, v; s[i]; ++i) {
			v = s[i] - 'a';
			if(nx[u][v] == 0) nx[u][v] = newnode(), dep[nx[u][v]] = dep[u] + 1;
			u = nx[u][v];
		}
		ending[u] = 1;
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
		for(int i = 1; i <= tot; ++i) {
			if(ending[q[i]]) pre[q[i]] = q[i];
			else pre[q[i]] = pre[fail[q[i]]];
		}
	}

	struct segTree {
		int mi[M * 4 + 5];

		int lc(int k) {return k<<1;}
		int rc(int k) {return k<<1|1;}

		void push_up(int k) {
			mi[k] = min(mi[lc(k)], mi[rc(k)]);
		}

		void build(int k, int l, int r) {
			if(l == r) return mi[k] = inf, void();
			int mid = (l + r) >> 1;
			build(lc(k), l, mid);
			build(rc(k), mid + 1, r);
			push_up(k);
		}

		void update(int k, int l, int r, int a, int b) {
			if(l == r) return mi[k] = b, void();
			int mid = (l + r) >> 1;
			if(a <= mid) update(lc(k), l, mid, a, b);
			else update(rc(k), mid + 1, r, a, b);
			push_up(k);
		}

		int query(int k, int l, int r, int a, int b) {
			if(a <= l && r <= b) return mi[k];
			int mid = (l + r) >> 1, ans = inf;
			if(a <= mid) ans = min(ans, query(lc(k), l, mid, a, b));
			if(mid < b)  ans = min(ans, query(rc(k), mid + 1, r, a, b));
			return ans;
		}
	} tr;

	void query(char *s) {
		int n = strlen(s);
		tr.build(1, 1, n + 1);
		tr.update(1, 1, n + 1, 1, 0);
		int u = 0;
		for(int i = 0, v; s[i]; ++i) {
			v = s[i] - 'a';
			while(u && nx[u][v] == 0) u = fail[u];
			if(nx[u][v]) u = nx[u][v];
			int uu = pre[u];
			if(uu) {
				tr.update(1, 1, n + 1, 
						i + 2, tr.query(1, 1, n + 1, i + 2 - dep[uu], i + 1) + 1);
			}
		}
		int ans = tr.query(1, 1, n + 1, n + 1, n + 1);
		printf("%d\n", ans == inf ? -1 : ans);
	}
} acam;

char s[M + 5], t[M + 5];

void work() {
	int n; scanf("%d", &n);
	scanf("%s", t);
	acam.clear();
	for(int i = 0; i < n; ++i) {
		scanf("%s", s);
		acam.insert(s);
	}
	acam.build();
	acam.query(t);
}

int main() {
	work();
	return 0;
}
