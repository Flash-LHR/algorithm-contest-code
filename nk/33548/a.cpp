#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e6;
const int mod = (int)19930726;

struct Manacher {
	int n;
	char ch[M * 2 + 5];
	int len[M * 2 + 5];
	int cnt[M + 5];

	void init(int m, char *s) {
		for(int i = 1; i <= m; ++i)
			ch[i * 2 - 1] = '#', 
			ch[i * 2] = s[i];
		ch[0] = '$', ch[2 * m + 1] = '#', ch[2 * m + 2] = '\0';
		n = 2 * m + 1;
	}

	void build() {
		len[1] = 1; ++cnt[len[1] - 1];
		for(int i = 2, p = 1, r = 1; i <= n; ++i) {
			if(i <= r) len[i] = min(len[2 * p - i], r - i + 1);
			else len[i] = 1;
			while(ch[i - len[i]] == ch[i + len[i]]) ++len[i];
			if(i + len[i] - 1 > r) p = i, r = i + len[i] - 1;
			++cnt[len[i] - 1];
		}
	}

	int quick(int a, int b, int p = mod) {
		int s = 1;
		while(b) {
			if(b & 1) s = (ll)s * a % p;
			a = (ll)a * a % p;
			b >>= 1;
		}
		return s % p;
	}

	int solve(ll k) {
		int ans = 1, be = n / 2;
		if(!(be&1)) --be;
		for(int i = be; i >= 1; i -= 2) {
			if(cnt[i] < k) {
				k -= cnt[i];
				if(i > 2) cnt[i - 2] += cnt[i];
				ans = (ll)ans * quick(i, cnt[i]) % mod;
			} else {
				ans = (ll)ans * quick(i, k) % mod;
				return ans;
			}
		}
		return -1;
	}
} man;

int n; ll k;
char s[M + 5];

void work() {
	scanf("%d%lld%s", &n, &k, s + 1);
	man.init(n, s);
	man.build();
	printf("%d\n", man.solve(k));
}

int main() {
	work();
	return 0;
}
