#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

int n, k, x;
int s[M + 5];
int t[M + 5];
int p[M + 5];
int id[M + 5];

bool check(int s) {
	if((ll)s * p[0] >= x) return 1;
	int dis = x;
	for(int i = 1; i <= k; ++i) {
		if((ll)s * (p[i] - t[i]) >= dis) return 1;
	}
	return 0;
}

void work() {
	scanf("%d %d %d %d", &n, &k, &x, &p[0]);
	for(int i = 1; i <= n; ++i) scanf("%d", &s[i]), id[i] = i;
	for(int i = 1; i <= k; ++i) scanf("%d", &t[i]);
	for(int i = 1; i <= k; ++i) scanf("%d", &p[i]);
	sort(id + 1, id + n + 1, [&](int a, int b) {
			return s[a] > s[b];
			});
	int l = 0, r = n, mid;
	while(l < r) {
		mid = (l + r + 1) >> 1;
		if(check(s[id[mid]])) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", r);
}

int main() {
	work();
	return 0;
}
