#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

int n, m;
int a[M + 5];
int h[M + 5];
int t[M + 5];
ll cnt[4];

bool check(ll mid) {
	memset(cnt, 0, sizeof cnt);
	for(int i = 1; i <= m; ++i) t[i] = h[i];
	if(mid <= n) for(ll i = 1; i <= mid; ++i) ++cnt[a[i]];
	else {
		for(ll i = 1; i <= n; ++i) ++cnt[a[i]];
		for(ll i = 1; i <= 3; ++i) cnt[i] *= mid / n;
		for(ll i = mid / n * n + 1; i <= mid; ++i) ++cnt[a[(i - 1) % n + 1]];
	}
	for(int i = 1; i <= m && cnt[3] >= 1; ++i) if(t[i] >= 3 && (t[i]&1)) --cnt[3], t[i] -= 3;
	for(int i = 1; i <= m && cnt[3] >= 2; ++i) {
		ll mi = min(cnt[3] / 2, t[i] / 6ll);
		cnt[3] -= 2 * mi, t[i] -= 6 * mi;
	}
	if(cnt[3]) {
		multiset<int> st;
		for(int i = 1; i <= m; ++i) if(t[i] > 0) st.insert(-t[i]);
		while(cnt[3] && !st.empty()) {
			int u = -*st.begin(); st.erase(st.begin());
			--cnt[3];
			if(u > 3) st.insert(-(u - 3));
		}
		int p = 0; while(!st.empty()) t[++p] = -*st.begin(), st.erase(st.begin());
		for(int i = p + 1; i <= m; ++i) t[i] = 0;
	}
	//printf("t: "); for(int i = 1; i <= m; ++i) printf("%d%c", t[i], " \n"[i == m]);
	//printf("cnt: "); for(int i = 1; i <= 3; ++i) printf("%lld%c", cnt[i], " \n"[i == 3]);
	for(int i = 1; i <= m; ++i) if(t[i] > 0) {
		if(cnt[1] && (t[i]&1)) --cnt[1], --t[i];
		int mi = min(cnt[2], (t[i] + 1) / 2ll);
		cnt[2] -= mi, t[i] -= 2 * mi;
		if(t[i] > 0) {
			if(cnt[1] >= t[i]) cnt[1] -= t[i], t[i] = 0;
			else return 0;
		}
	}
	return 1;
}

void work() {
	scanf("%d", &n); for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	scanf("%d", &m); for(int i = 1; i <= m; ++i) scanf("%d", &h[i]);
	ll l = 1, r = (ll)1e14, mid;
	while(l < r) {
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", r);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
