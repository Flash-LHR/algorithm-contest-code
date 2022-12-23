#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef long long ll;

const int M = (int)1e5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n;
int a[M + 5];
ll f[M + 5];

void work() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), f[i] = linf;
	f[1] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n && (ll)(j - i) * (j - i) * (j - i) <= (ll)1e10; ++j) {
			ll w = (ll)(j - i) * (j - i) * (j - i) * a[j];
			if(f[j] > f[i] + w) f[j] = f[i] + w;
		}
	}
	printf("%lld\n", f[n]);
}

int main() {
	int T = 1; //scanf("%d", &T);
	while(T--) work();
	return 0;
}
