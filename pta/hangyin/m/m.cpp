#include <bits/stdc++.h>
using namespace std;

typedef double db;

const int M = (int)1e5;

void work() {
	db r1, r2, d;
	scanf("%lf %lf %lf", &r1, &r2, &d);
	double x = r2 * r2 * r2 - r1 * r1 * r1 + (r1 - d) * (r1 - d) * (r1 - d);
	printf("%.12f\n", r2 - pow(x, 1.0 / 3));
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
