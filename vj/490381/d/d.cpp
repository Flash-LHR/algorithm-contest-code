#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;

ll cal(vector<pair<int, int>> v0, vector<pair<int, int>> v1) {
	ll ans = 0;
	for(int i = 0; i < 3; ++i) {
		int mi = min(v0[i].second, v1[(v0[i].first + 1) % 3].second);
		ans += mi;
		v0[i].second -= mi, v1[(v0[i].first + 1) % 3].second -= mi;
	}
	for(int i = 0; i < 3; ++i) {
		int mi = min(v0[i].second, v1[(v0[i].first) % 3].second);
		v0[i].second -= mi, v1[(v0[i].first) % 3].second -= mi;
	}
	for(int i = 0; i < 3; ++i) {
		int mi = min(v0[i].second, v1[(v0[i].first + 2) % 3].second);
		ans -= mi;
		v0[i].second -= mi, v1[(v0[i].first + 2) % 3].second -= mi;
	}
	return ans;
}

void work() {
	vector<pair<int, int>> v[2];
	for(int i = 0, a; i < 3; ++i) {
		scanf("%d", &a);
		v[0].push_back({i, a});
	}
	for(int i = 0, a; i < 3; ++i) {
		scanf("%d", &a);
		v[1].push_back({i, a});
	}
	printf("%lld\n", cal(v[0], v[1]));
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
