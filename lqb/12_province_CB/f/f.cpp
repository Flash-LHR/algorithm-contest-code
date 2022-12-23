#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void work() {
	ll n; scanf("%lld", &n);
	n /= 1000;
	n %= 24 * 60 * 60;
	printf("%02lld:%02lld:%02lld\n", n / 60 / 60, n / 60 % 60, n % 60);
}

int main() {
	work();
	return 0;
}
