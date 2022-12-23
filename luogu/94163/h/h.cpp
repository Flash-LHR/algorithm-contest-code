#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)5e5;
const int inf = 0x3f3f3f3f;

struct segTree
{
	int v[(M + 1) * 4 + 5][3];

	int lc(int k) {return k<<1;}
	int rc(int k) {return k<<1|1;}

	void push_up(int k) {
		for (int i = 0; i < 3; ++i)
			v[k][i] = max(v[lc(k)][i], v[rc(k)][i]);
	}

	void build(int k, int l, int r) {
		if (l == r) return v[k][0] = v[k][1] = v[k][2] = -inf, void();
		int mid = (l + r) >> 1;
		build(lc(k), l, mid);
		build(rc(k), mid + 1, r);
		push_up(k);
	}

	void update(int k, int l, int r, int a, int b, int c) {
		if (l == r) return v[k][b] = max(v[k][b], c), void();
		int mid = (l + r) >> 1;
		if (a <= mid) update(lc(k), l, mid, a, b, c);
		else update(rc(k), mid + 1, r, a, b, c);
		push_up(k);
	}

	int query(int k, int l, int r, int a, int b, int c) {
		if (a > b) return -inf;
		if (l >= a && r <= b) return v[k][c];
		int mid = (l + r) >> 1, mx = -inf;
		if (a <= mid) mx = max(mx, query(lc(k), l, mid, a, b, c));
		if (mid < b)  mx = max(mx, query(rc(k), mid + 1, r, a, b, c));
		return mx;
	}
} tr;

int n, m, h;
ll s[M + 5], sb[M + 5];
int f[M + 5];

int tofind(ll x)
{
	return lower_bound(sb + 1, sb + m + 1, x) - sb;
}

void work()
{
	scanf("%d %d", &n, &h); m = n + 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &s[i]);
		s[i] += s[i - 1];
		sb[i] = s[i];
	}
	sb[m] = 0;
	sort(sb + 1, sb + m + 1);
	m = unique(sb + 1, sb + m + 1) - (sb + 1);
	tr.build(1, 1, m);
	f[0] = 0;
	tr.update(1, 1, m, tofind(0), 0, f[0] + 1);
	tr.update(1, 1, m, tofind(0), 1, f[0]);
	tr.update(1, 1, m, tofind(0), 2, f[0] - 1);
	for (int i = 1; i <= n; ++i) {
		f[i] = -inf;
		f[i] = max(f[i], tr.query(1, 1, m, tofind(s[i]) + 1, m, 0) - i - 1);
		f[i] = max(f[i], tr.query(1, 1, m, tofind(s[i]), tofind(s[i]), 1));
		f[i] = max(f[i], tr.query(1, 1, m, 1, tofind(s[i]) - 1, 2) + i + 1);

		tr.update(1, 1, m, tofind(s[i]), 0, f[i] + i + 1);
		tr.update(1, 1, m, tofind(s[i]), 1, f[i]);
		tr.update(1, 1, m, tofind(s[i]), 2, f[i] - i - 1);

		//printf("f[%d]=%d\n", i, f[i]);
	}
	printf("%d %d\n", f[n], f[n] >= h);
}

int main()
{
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}
