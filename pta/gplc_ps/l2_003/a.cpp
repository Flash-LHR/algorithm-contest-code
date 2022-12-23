#include <bits/stdc++.h>
using namespace std;

typedef double db;

void work() {
	int n; double d, ans = 0.0; scanf("%d %lf", &n, &d);
	vector<pair<db, db>> v(n);
	for(const auto &x: v) scanf("%lf", &x.first);
	for(const auto &x: v) scanf("%lf", &x.second);
	sort(v.begin(), v.end(), [&](const auto& a, const auto &b) {
			return a.second * b.first > b.second * a.first;
			});
	for(const auto &x: v) {
		if(x.first >= d) ans += d * x.second / x.first, d = 0.0;
		else ans += x.second, d -= x.first;
	}
	printf("%.2f\n", ans);
}

int main() {
	work();
	return 0;
}
