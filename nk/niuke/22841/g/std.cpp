#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define Case(T) int T;cin>>T;while (T--)
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e5 + 7;
const int N = 1e6 + 10;
const int M = 1e5 + 10;
int n, m;
vector<int>g[N];
struct node {
	int l, r, bl, id;
}p[N];
inline bool cmp(node a, node b) {
	return (a.bl) ^ (b.bl) ? a.l < b.l : (((a.bl) & 1) ? a.r<b.r : a.r>b.r);
}
int anss[N], num[N], mx,sum[N], c[N];
inline void add(int p) {
	for (auto it : g[c[p]]) {
		num[sum[it]]--;
		++sum[it];
		num[sum[it]]++;
		if (sum[it] > mx) {
			mx = sum[it];
		}
	}
}
inline void sub(int p) {
	for (auto it : g[c[p]]) {
		if (sum[it] ==  mx  && num[sum[it]]==1) {
			mx--;
		}
		num[sum[it]]--;
		--sum[it];
		num[sum[it]]++;
	}
}
int main() {
	Case(T) {
		scanf("%d%d", &n, &m);
		set<int>se;
		for (int i = 1;i <= n;++i) {
			scanf("%d", &c[i]);
			se.insert(c[i]);
			if (g[c[i]].size() || c[i]==1)continue;
			int temp = c[i];
			for (int j = 2;j * j <= c[i];j++) {
				if (temp % j == 0) {
					g[c[i]].push_back(j);
					temp /= j;
					while (temp % j == 0) {
						temp /= j;
					}
				}
			}
			if (temp != 1)g[c[i]].push_back(temp);
		}
		int block = n / sqrt(m * 2 / 3);
		block = max(block, 1);
		for (int i = 1;i <= m;++i) {
			p[i].id = i;
			scanf("%d%d", &p[i].l, &p[i].r);
			p[i].bl = (p[i].l - 1) / block / 2 + 1;
		}
		sort(p + 1, p + 1 + m, cmp);
		int l = 1, r = 0;
		for (int i = 1;i <= m;++i) {
			while (p[i].l < l) add(--l);
			while (p[i].r > r) add(++r);
			while (p[i].l > l) sub(l++);
			while (p[i].r < r) sub(r--);
			anss[p[i].id] = mx;
		}
		for (int i = 1;i <= m;++i) printf("%d\n", anss[i]);
		
		while (l <= r)  sub(l++);
		//for (auto it : se) sum[it] = 0;
		mx = 0;
	//	for (int i = 0;i <= n;i++)num[i] = 0;
	}
	return 0;
}
