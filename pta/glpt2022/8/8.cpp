#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void work() {
	int n, k, s; scanf("%d %d %d", &n, &k, &s);
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}
	sort(v.begin(), v.end());
	multiset<int> st; int ans = 0;
	for(const auto &p: v) if(p.first >= 175) {
		if(st.empty()) st.insert(p.first), ++ans;
		else {
			if(p.second >= s) {
				auto it = st.upper_bound(p.first);
				if(it == st.begin()) {
					if(st.size() < k) st.insert(p.first), ++ans;
				} else {
					--it;
					st.erase(it);
					st.insert(p.first), ++ans;
				}
			} else {
				auto it = st.lower_bound(p.first);
				if(it == st.begin()) {
					if(st.size() < k) st.insert(p.first), ++ans;
				} else {
					--it;
					st.erase(it);
					st.insert(p.first), ++ans;
				}
			}
		}
	}
	printf("%d\n", ans);
}

int main() {
	work();
	return 0;
}
