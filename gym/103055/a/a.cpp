#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void work() {
	ll a = 0, b = 0;
	for(int i = 0, x; i < 5; ++i) scanf("%d", &x), a += x;
	for(int i = 0, x; i < 5; ++i) scanf("%d", &x), b += x;
	puts(a >= b ? "Blue" : "Red");
}

int main() {
	work();
	return 0;
}
