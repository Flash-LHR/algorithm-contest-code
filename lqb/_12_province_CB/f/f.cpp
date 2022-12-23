#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(int t) {
	if(t < 10) printf("0");
	printf("%d", t);
}

void work() {
	ll t; scanf("%lld", &t);
	t /= 1000;
	t %= 24 * 60 * 60;
	print(t / 60 / 60);
	printf(":");
	print(t / 60 % 60);
	printf(":");
	print(t % 60);
	printf("\n");
}

int main() {
	work();
	return 0;
}
