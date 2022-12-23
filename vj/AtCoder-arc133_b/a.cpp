#include <bits/stdc++.h>
using namespace std;

const int M = (int)2e5;
const int N = M * 13;
const int inf = 0x3f3f3f3f;

struct TA {
	int n, a[N + 5];
	void init(int _n) {n = _n; memset(a, -inf, sizeof(int) * (n + 1));}
	int lowbit(int n) {return n&-n;}
	void add(int p, int x) {while(p <= n) a[p] = max(a[p], x), p += lowbit(p);}
	int ask(int p) {int s = -inf; while(p) s = max(s, a[p]), p -= lowbit(p); return s;}
} tr;

int p[M + 5], q[M + 5];
int pos[M + 5];
int f[N + 5];

void work() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &p[i]);
	for(int i = 1; i <= n; ++i) scanf("%d", &q[i]), pos[q[i]] = i;
	tr.init(n * 13);
	for(int i = 1; i <= n; ++i) {
		vector<pair<int, int>> v;
		for(int j = p[i]; j <= n; j += p[i]) v.push_back({pos[j], max(0, tr.ask(pos[j] - 1)) + 1});
		for(const auto &p: v) tr.add(p.first, p.second);
	}
	printf("%d\n", tr.ask(n * 13));
}

int main() {
	work();
	return 0;
}
