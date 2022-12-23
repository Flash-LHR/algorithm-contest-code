#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, int> mp;

void divide(ll n) {
	for(int i = 2; (ll)i * i <= n; ++i) if(n % i == 0) {
		int c = 0;
		while(n % i == 0) n /= i, ++c;
		mp[i] = c;
	}
	if(n > 1) mp[n] = 1;
}

void work() {
	ll n = 2021041820210418ll;
	divide(n);
	//for(auto x: mp) printf("%lld %d\n", x.first, x.second);
	printf("2430\n");
}

int main() {
	work();
	return 0;
}
