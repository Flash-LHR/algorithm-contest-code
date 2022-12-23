#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int n, a[100005], b[200005], c[200005], ans;
map< pair < int, int >, int > mm;
const long long p1 = 1e9 + 7, p2 = 998244353;
long long hs1, hs2, hs1c, hs2c, hs1a, hs2a;
long long oo = 1e9, oon1, oon2;
inline int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % p;
		a = 1ll * a * a % p, b >>= 1;
	}
	return res;
}
int main() {
	scanf("%d", &n);
	ans = 2 * n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		hs1a = (hs1a * oo + a[i]) % p1;
		hs2a = (hs2a * oo + a[i]) % p2;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", b + i);
		hs1 = (hs1 * oo + b[i]) % p1;
		hs2 = (hs2 * oo + b[i]) % p2;
	}
	mm[{hs1, hs2}] = 1;
	oon1 = qpow(oo, n - 1, p1), oon2 = qpow(oo, n - 1, p2);
	for (int i = 1; i < n; i++) {
		hs1 = ((hs1 - 1ll * b[i] * oon1 % p1 + p1) % p1 * oo + b[i]) % p1;
		hs2 = ((hs2 - 1ll * b[i] * oon2 % p2 + p2) % p2 * oo + b[i]) % p2;
		if (!mm[{hs1, hs2}]) mm[{hs1, hs2}] = i + 1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
		c[n + i] = c[i];
		hs1c = (hs1c * oo + c[i]) % p1;
		hs2c = (hs2c * oo + c[i]) % p2;
	}
	for (int i = 1; i <= n; i++) {
		// hs1c - hs1a hs2c - hs2a
		if (mm[{(hs1c - hs1a + p1) % p1, (hs2c - hs2a + p2) % p2}]) {
			ans = min(ans, i - 1 + mm[{(hs1c - hs1a + p1) % p1, (hs2c - hs2a + p2) % p2}] - 1);
		}
		hs1a = ((hs1a - 1ll * a[i] * oon1 % p1 + p1) % p1 * oo + a[i]) % p1;
		hs2a = ((hs2a - 1ll * a[i] * oon2 % p2 + p2) % p2 * oo + a[i]) % p2;
	}
	if (ans == 2 * n) ans = -1;
	printf("%d\n", ans);
	return 0;
}

