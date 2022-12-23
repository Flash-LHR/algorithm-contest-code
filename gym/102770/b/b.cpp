#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e6;

int n, c;

struct segTree {
	int mx[M * 4 + 5];

	int lc(int k) {return k<<1;}
	int rc(int k) {return k<<1|1;}

	void push_up(int k) {
		mx[k] = max(mx[lc(k)], mx[rc(k)]);
	}

	void build(int k, int l, int r) {
		if(l == r) return mx[k] = c, void();
		int mid = (l + r) >> 1;
		build(lc(k), l, mid);
		build(rc(k), mid + 1, r);
		push_up(k);
	}

	void update(int k, int l, int r, int a) {
		if(l == r) return mx[k] -= a, void();
		int mid = (l + r) >> 1;
		if(mx[lc(k)] >= a) update(lc(k), l, mid, a);
		else update(rc(k), mid + 1, r, a);
		push_up(k);
	}

	int query(int k, int l, int r) {
		if(l == r) return mx[k] < c;
		int mid = (l + r) >> 1;
		return query(lc(k), l, mid) + query(rc(k), mid + 1, r);
	}
} tr;

void work() {
	scanf("%d %d", &n, &c);
	multiset<int> st;
	tr.build(1, 1, n);
	for(int i = 1, a; i <= n; ++i) {
		scanf("%d", &a);
		tr.update(1, 1, n, a);
		if(st.empty()) st.insert(c - a);
		else {
			auto it = st.lower_bound(a);
			if(it == st.end()) st.insert(c - a);
			else {
				int val = *it - a;
				st.erase(it);
				st.insert(val);
			}
		}
	}
	printf("%d %lu\n", tr.query(1, 1, n), st.size());
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
