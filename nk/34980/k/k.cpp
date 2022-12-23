#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;
const int inf = 0x3f3f3f3f;

int n = 2 * 3 * 17 * 19, f[M + 5];
int m = 5 * 7 * 11 * 13, g[M + 5];

void init(int n, int f[], vector<int> v) {
	for(int i = 0; i <= M; ++i) f[i] = inf;
	f[0] = 0;
	for(const int &x: v) {
		for(int i = x; i <= M; ++i) f[i] = min(f[i], f[i - x] + 1);
	}
	//for(int i = 2 * n; i < 10 * n; ++i) assert(f[i] + f[n] == f[i + n]);
}

void init() {
	vector<int> a, b;
	a.push_back(2), a.push_back(3), a.push_back(17), a.push_back(19);
	b.push_back(5), b.push_back(7), b.push_back(11), b.push_back(13);
	init(n, f, a);
	init(m, g, b);
}

void work() {
	int x; scanf("%d", &x);
	if(x <= M) {
		int a = f[x], b = g[x];
		if(a == b && a == inf) printf("-1\n");
		else if(a == b) printf("both\n");
		else if(a < b) printf("A\n");
		else printf("B\n");
	} else {
		ll a = f[x % n + n] + (ll)(x / n - 1) * f[n],
		   b = g[x % m + m] + (ll)(x / m - 1) * f[m];
		if(a == b && a == inf) printf("-1\n");
		else if(a == b) printf("both\n");
		else if(a < b) printf("A\n");
		else printf("B\n");
	}
}

int main() {
	init();
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
