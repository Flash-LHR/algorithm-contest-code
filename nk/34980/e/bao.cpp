#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T>
inline void scan(T &n) {
	n = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) {n = n * 10 + ch - '0'; ch = getchar();}
	if(f == -1) n = -n;
}

const int M = (int)5e5;
const int mod = (int)998244353;

int n, x, a[M + 5];

void work() {
	scan(n), scan(x);
	for(int i = 1; i <= n; ++i) scan(a[i]);
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		ll s = 1;
		for(int j = i; j <= n; ++j) {
			s = s * a[j] % mod;
			if(s == x) ++ans;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	work();
	return 0;
}
