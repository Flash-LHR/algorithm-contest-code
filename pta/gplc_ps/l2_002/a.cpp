#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

struct node {
	int val, nx;
	node(int _val = 0, int _nx = 0): val(_val), nx(_nx){}
} a[M + 5];

bool vis[M + 5];
vector<pair<int, node>> v[2];

void work() {
	int ad, n; scanf("%d %d", &ad, &n);
	for(int i = 1, p; i <= n; ++i) {
		scanf("%d", &p);
		scanf("%d %d", &a[p].val, &a[p].nx);
	}
	while(~ad) {
		int val = a[ad].val;
		if(val < 0) val = -val;;
		if(!vis[val]) {
			vis[val] = 1;
			if(!v[0].empty()) v[0][v[0].size() - 1].second.nx = ad;
			v[0].push_back({ad, node(a[ad].val, -1)});
		} else {
			if(!v[1].empty()) v[1][v[1].size() - 1].second.nx = ad;
			v[1].push_back({ad, node(a[ad].val, -1)});
		}
		ad = a[ad].nx;
	}
	for(const auto &x: v[0]) {
		printf("%05d %d ", x.first, x.second.val);
		if(~x.second.nx) printf("%05d\n", x.second.nx);
		else printf("-1\n");
	}
	for(const auto &x: v[1]) {
		printf("%05d %d ", x.first, x.second.val);
		if(~x.second.nx) printf("%05d\n", x.second.nx);
		else printf("-1\n");
	}
}

int main() {
	work();
	return 0;
}
