#include <bits/stdc++.h>
using namespace std;

const int M =(int)2e5;

struct TA
{
    int n; int tree[M + 5];
    void init(int _n) {n = _n; for(int i = 0; i <= n; ++i) tree[i] = 0;}
    inline int lowbit(int n) {return n&-n;}
    void add(int a, int b) {for(int i = a; i <= n; i += lowbit(i)) tree[i] += b;}
    int ask(int r) {int s = 0; for(int i = r; i; i -= lowbit(i)) s += tree[i]; return s;}
    int ask(int l, int r) {return ask(r) - ask(l - 1);}
} tr;

int l[M + 5], r[M + 5], c[M + 5], id[M + 5];

void work()
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i) scanf("%d %d %d", &l[i], &r[i], &c[i]), id[i] = i;
	sort(id + 1, id + m + 1, [&](int a, int b) {return r[a] < r[b];});
	tr.init(n);
	set <int> st;
	for (int i = 1, j = 0, u; i <= m; ++i) {
		u = id[i];
		while (j + 1 <= r[u]) st.insert(-(++j));
		while (tr.ask(l[u], r[u]) < c[u]) {
			int d = -*(st.begin());
			st.erase(st.begin());
			tr.add(d, 1);
		}
	}
	for (int i = 1; i <= n; ++i) printf("%d%c", tr.ask(i, i),  " \n"[i == n]);
}

int main()
{
	work();
	return 0;
}
