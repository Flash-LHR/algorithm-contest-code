#include <bits/stdc++.h>
using namespace std;

void work() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i) scanf("%d", &v[i].first);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &v[i].second);
		v[i].second += v[i].first;
	}
	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
			return a.second < b.second;
			});
	int cnt = 1, r = v[0].second;
	for(int i = 1; i < (int)v.size(); ++i) {
		if(v[i].first >= r) ++cnt, r = v[i].second;
	}
	printf("%d\n", cnt);
}

int main() {
	work();
	return 0;
}
