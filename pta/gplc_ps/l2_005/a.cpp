#include <bits/stdc++.h>
using namespace std;

const int M = (int)5e1;

int n, m, k;
vector<int> v[M + 5];

int cal1(int a, int b) {
	int ans = 0;
	for(int l = 0, r = -1, i = -1; l < (int)v[a].size(); l = r + 1) {
		while(r + 1 < (int)v[a].size() && v[a][l] == v[a][r + 1]) ++r;
		while(i + 1 < (int)v[b].size() && v[b][i + 1] < v[a][l]) ++i;
		if(i + 1 < (int)v[b].size() && v[b][i + 1] == v[a][l]) ++ans;
	}
	return ans;
}

int cal2(int a, int b) {
	int pa = 0, pb = 0, ans = 0, last = -1;
	while(pa < (int)v[a].size() && pb < (int)v[b].size()) {	
		if(v[a][pa] <= v[b][pb]) {
			if(v[a][pa] != last) ++ans, last = v[a][pa];
			++pa;
		} else {
			if(v[b][pb] != last) ++ans, last = v[b][pb];
			++pb;
		}
	}
	while(pa < (int)v[a].size()) {
		if(v[a][pa] != last) ++ans, last = v[a][pa];
		++pa;
	}
	while(pb < (int)v[b].size()) {
		if(v[b][pb] != last) ++ans, last = v[b][pb];
		++pb;
	}
	return ans;
}

void work() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &m);
		v[i].resize(m);
		for(int j = 0; j < m; ++j) scanf("%d", &v[i][j]);
		sort(v[i].begin(), v[i].end());
	}
	scanf("%d", &k);
	for(int _ = 0, a, b; _ < k; ++_) {
		scanf("%d %d", &a, &b);
		printf("%.2f%%\n", 100.0 * cal1(a, b) / cal2(a, b));
	}
}

int main() {
	work();
	return 0;
}
