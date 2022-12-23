#include <bits/stdc++.h>
using namespace std;

const int M = (int)3e5;

int n, a[M + 5];

void work() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	int mx = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[1] != a[i]) mx = max(mx, i - 1);
		if(a[i] != a[n]) mx = max(mx, n - i);
	}
	printf("%d\n", mx);
}

int main() {
	work();
	return 0;
}
