#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const int N = (int)17;

template<typename T>
inline void scan(T &x) {
	x = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	if(f == -1) x = -x;
}

template<typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

template<typename T>
void print(T x, char ch) {
	print(x), putchar(ch);
}

int n, a[M + 5];
int m, b[M + 5];

struct zxTree {
	int tot;
	int rt[M + 5];
	int lc[M * N + M + 5], rc[M * N + M + 5]; //repair
	ll sum[M * N + M + 5];
	int cnt[M * N + M + 5];

	void clear() {
		tot = 0;
		lc[0] = rc[0] = 0;
	}

	void insert(int x, int y, int l, int r, int a, int b, int c) {
		if(l == r) return;
		int mid = (l + r) >> 1;
		if(a <= mid) {
			lc[y] = ++tot; sum[lc[y]] = sum[lc[x]] + b, cnt[lc[y]] = cnt[lc[x]] + c;
			rc[y] = rc[x]; sum[rc[y]] = sum[rc[x]], cnt[rc[y]] = cnt[rc[x]];
			insert(lc[x], lc[y], l, mid, a, b, c);
		} else {
			rc[y] = ++tot; sum[rc[y]] = sum[rc[x]] + b, cnt[rc[y]] = cnt[rc[x]] + c;
			lc[y] = lc[x]; sum[lc[y]] = sum[lc[x]], cnt[lc[y]] = cnt[lc[x]];
			insert(rc[x], rc[y], mid + 1, r, a, b, c);
		}
	}

	ll query(int x, int y, int l, int r, int a) {
		if(l == r) return (sum[y] - sum[x]) / (cnt[y] - cnt[x]) * a;
		int mid = (l + r) >> 1;
		ll ans = 0;
		if(cnt[rc[y]] - cnt[rc[x]] <= a) {
			ans += sum[rc[y]] - sum[rc[x]];
			if(cnt[rc[y]] - cnt[rc[x]] < a)
				ans += query(lc[x], lc[y], l, mid, a - cnt[rc[y]] + cnt[rc[x]]);
		} else {
			ans += query(rc[x], rc[y], mid + 1, r, a);
		}
		return ans;
	}

	void nmsl() {
		printf("----------------\n");
		for(int i = 1; i <= tot; ++i) {
			printf("%d: lc=%d rc=%d sum=%lld cnt=%d\n", i, lc[i], rc[i], sum[i], cnt[i]);
		}
		printf("----------------\n");
	}
} tr;

ll sxfNMSL(int n) {
	return (ll)n * (n + 1) * (2 * n + 1) / 6;
}

void work() {
	tr.clear();
	scan(n); m = n;
	for(int i = 1; i <= n; ++i) scan(a[i]), b[i] = a[i];
	sort(b + 1, b + m + 1), m = unique(b + 1, b + m + 1) - (b + 1);
	for(int i = 1; i <= n; ++i) {
		tr.rt[i] = ++tr.tot;
		tr.insert(tr.rt[i - 1], tr.rt[i], 1, m, lower_bound(b + 1, b + m + 1, a[i]) - b, a[i], 1);
	}
	int q; scan(q);
	for(int i = 1, l, r, k; i <= q; ++i) {
		scan(l), scan(r), scan(k);
		if(n == 1) {
			print(a[1] + 1, '\n');
			continue;
		}
		ll ans = tr.query(tr.rt[l - 1], tr.rt[r], 1, m, k);
		ans += sxfNMSL(r - l + 1);
		print(ans, '\n');
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}

