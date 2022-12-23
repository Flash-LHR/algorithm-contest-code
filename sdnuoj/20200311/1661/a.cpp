#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

int n, q;
ll a[M + 5];

void work() {
	scanf("%d %d", &n, &q);
	for(int i = 1, l, r, c; i <= q; ++i) {
		scanf("%d %d %d", &l, &r, &c);
		a[l] += c, a[r + 1] -= c;
		/*
		   前缀和后相当于：
			a[l..n] += c, a[r+1..n] -= c
				-> a[l,r] += c
		  */
	}
	for(int i = 1; i <= n; ++i) a[i] += a[i - 1];
	for(int i = 1; i <= n; ++i) printf("%lld%c", a[i], " \n"[i == n]);
}

int main() {
	work();
	return 0;
}
