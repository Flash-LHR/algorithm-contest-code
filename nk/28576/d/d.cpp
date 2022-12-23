#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)5e4;

char s[M + 5];
map<int, int> cnt[2];

struct HT {
	int base, mod;
	int p[M + 5], h[M + 5];

	HT(int _base, int _mod): base(_base), mod(_mod) {}

	void init(const char *s) {
		p[0] = 1;
		for(int i = 1; s[i]; ++i) {
			p[i] = (ll)p[i - 1] * base % mod;
			h[i] = ((ll)h[i - 1] * base + s[i] - 'A' + 1) % mod;
		}
	}

	int getH(int l, int r) {
		return (h[r] - (ll)h[l - 1] * p[r - l + 1] % mod + mod) % mod;
	}
} ht[2] = {HT(131, (int)1e9 + 7), HT(131, (int)1e9 + 7)};

void gao(map<int, int> &cnt) {
	ht[0].init(s);
	int n = strlen(s + 1);
	reverse(s + 1, s + n + 1);
	ht[1].init(s);
	map<int, int> pos;
	set<pair<int, int>> st;
	for(int i = 1, l, r, mid; i <= n; ++i) {
		l = 0, r = min(i - 1, n - i);
		while(l < r) {
			mid = (l + r + 1) >> 1;
			if(ht[0].getH(i - mid, i - 1) == ht[1].getH(n - i - mid + 1, n - i)) l = mid;
			else r = mid - 1;
		}
		int hp = ht[0].getH(i - r, i + r);
		pos[hp] = i, st.insert({-(2 * r + 1), hp}), ++cnt[hp];

		if(i == n) break;
		l = 0, r = min(i, n - i);
		while(l < r) {
			mid = (l + r + 1) >> 1;
			if(ht[0].getH(i - mid + 1, i) == ht[1].getH(n - i - mid + 1, n - i)) l = mid;
			else r = mid - 1;
		}
		if(r) {
			int hp = ht[0].getH(i - r + 1, i + r);
			pos[hp] = i, st.insert({-2 * r, hp}), ++cnt[hp];
		}
	}
	while(!st.empty()) {
		auto [m, hp] = *st.begin(); st.erase(st.begin());
		m = -m;
		if(m <= 2) break;
		int centre = pos[hp];
		int new_hp, old_hp;
		if(m & 1) {
			new_hp = ht[0].getH(centre - m / 2 + 1, centre + m / 2 - 1);
			old_hp = ht[0].getH(centre - m / 2, centre + m / 2);
		} else {
			new_hp = ht[0].getH(centre - m / 2 + 2, centre + m / 2 - 1);
			old_hp = ht[0].getH(centre - m / 2 + 1, centre + m / 2);
		}
		cnt[new_hp] += cnt[old_hp];
		st.insert({-(m - 2), new_hp});
		pos[new_hp] = centre;
	}
}

void work() {
	scanf("%s", s + 1); gao(cnt[0]);
	scanf("%s", s + 1); gao(cnt[1]);
	ll ans = 0;
	for(const auto &x: cnt[0]) if(cnt[1].count(x.first)) ans += (ll)x.second * cnt[1][x.first];
	printf("%lld\n", ans);
}

int main() {
	work();
	return 0;
}
