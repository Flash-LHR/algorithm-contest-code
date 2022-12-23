#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e3;

int n, m, q;
ll a[M + 5][M + 5];

void work() {
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 1, xa, ya, xb, yb, c; i <= q; ++i) {
		scanf("%d %d %d %d %d", &xa, &ya, &xb, &yb, &c);
		/*
		   前缀和后相当于：
			(xa,ya)到(n,m) +c
			(xa,yb+1)到(n,m) -c
			(xb+1,ya)到(n,m) -c
			(xb+1,yb+1)到(n,m) +c
			即：(xa,ya)到(xb,yb)+c
		*/
		a[xa][ya] += c;
		a[xa][yb + 1] -= c;
		a[xb + 1][ya] -= c;
		a[xb + 1][yb + 1] += c;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			printf("%lld%c", a[i][j], j == m ? '\n' : ' ');
		}
	}
}

int main() {
	work();
	return 0;
}
