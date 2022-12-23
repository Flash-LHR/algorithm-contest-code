#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;
const int inf = 0x3f3f3f3f;

int n, m, w, a[M + 5], b[M + 5];

struct segTree
{
	int s[M * 4 + 5];
	int lc(int k) {return k<<1;}
	int rc(int k) {return k<<1|1;}
	void push_up(int k) {s[k] = s[lc(k)] + s[rc(k)];}
	void update(int k, int l, int r, int a) {
		if (l == r) return ++s[k], void();
		int mid = (l + r) >> 1;
		if (a <= mid) update(lc(k), l, mid, a);
		else update(rc(k), mid + 1, r, a);
		push_up(k);
	}
	int query(int k, int l, int r, int a) {
		if (l == r) return l;
		int mid = (l + r) >> 1;
		if (s[rc(k)] >= a) return query(rc(k), mid + 1, r, a);
		else return query(lc(k), l, mid, a - s[rc(k)]);
	}
} tr;

int main()
{
	scanf("%d %d", &n, &w); m = n;
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + m + 1);
	m = unique(b + 1, b + m + 1) - (b + 1);
	for (int i = 1, k; i <= n; ++i) {
		k = max(1, i * w / 100);
		tr.update(1, 1, m, lower_bound(b + 1, b + m + 1, a[i]) - b);
		printf("%d%c", b[tr.query(1, 1, m, k)],  " \n"[i == n]);
	}
	return 0;
}
