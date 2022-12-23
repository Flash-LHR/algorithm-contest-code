#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e6;

struct TA {
	int n, a[M + 5];
	int lowbit(int n) {return n&-n;}
	void init(int _n) {n = _n; memset(a, 0, sizeof(int) * (n + 1));}
	void add(int p, int x) {while(p <= n) a[p] += x, p += lowbit(p);}
	int ask(int p) {int s = 0; while(p) s += a[p], p -= lowbit(p); return s;}
	int ask(int l, int r) {return ask(r) - ask(l - 1);}
} tr;

int n, a[M + 5];

void work() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0; ll sum = 0;
	tr.init(n);
	for(int i = 1, p; i <= n; ++i) {
		tr.add(i, 1); sum += a[i];
		p = lower_bound(a + 1, a + n + 1, sum / i + 1) - a;
		if(p <= n) ans = max(ans, tr.ask(p, n));
	}
	printf("%d\n", ans);
}

int main() {
	work();
	return 0;
}
