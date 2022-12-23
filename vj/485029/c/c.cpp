#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e2;
const int N = (int)1e4;

int n, x;
bitset<N+5> bt;

void work() {
	scanf("%d %d", &n, &x);
	bt = 1;
	for(int i = 1, a, b; i <= n; ++i) {
		scanf("%d %d", &a, &b);
		bt = (bt<<a)|(bt<<b);
	}
	puts(bt[x] ? "Yes" : "No");
}

int main() {
	work();
	return 0;
}
