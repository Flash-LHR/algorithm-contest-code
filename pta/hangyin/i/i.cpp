#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;

const int M = (int)3e5;
const db eps = 1e-7;

ll n, k;

bool check(db q) {
	__int128 x = 1;
	for(int i = 1; i <= k; ++i) {
		x = (__int128)(x * q + 0.5);
		if(x >= n) return 1;
	}
	return 0;
}

void work() {
	scanf("%lld %lld", &n, &k);
	if(n == 1) {
		printf("0.5\n");
		return;
	}
	db l = 1.5, r = 1e18, mid;
	for(int i = 0; i < 100; ++i) {
		mid = (l + r) / 2.0;
		if(check(mid)) r = mid;
		else l = mid;
	}
	printf("%.12f\n", r);
}

int main() {
	work();
	return 0;
}
