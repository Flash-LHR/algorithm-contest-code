#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e7;

int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int cnt[M + 5];
int sxf[M + 5];

bool leap(int n) {
	return n % 400 == 0 || (n % 4 == 0 && n % 100 != 0);
}

char buf[1024];

bool ok(int y, int m, int d) {
	sprintf(buf, "%04d%02d%02d", y, m, d);
	for(int i = 0; i < 6; ++i) {
		if(buf[i] == '2' && buf[i + 1] == '0' && buf[i + 2] == '2') return 1;
	}
	return 0;
}

void init() {
	int cur = 0;
	for(int i = 2000; i <= 9999; ++i) {
		if(leap(i)) {
			for(int j = 1; j <= 12; ++j) {
				for(int k = 1; k <= b[j]; ++k) {
					++cur;
					cnt[cur] = cnt[cur - 1];
					if(ok(i, j, k)) ++cnt[cur];
					if(j == 12 && k == b[j]) sxf[i] = cur;
				}
			}
		} else {
			for(int j = 1; j <= 12; ++j) {
				for(int k = 1; k <= a[j]; ++k) {
					++cur;
					cnt[cur] = cnt[cur - 1];
					if(ok(i, j, k)) ++cnt[cur];
					if(j == 12 && k == a[j]) sxf[i] = cur;
				}
			}
		}
	}
}

int cal(int y, int m, int d) {
	int ans = 0;
	ans += sxf[y - 1];
	if(leap(y)) {
		for(int i = 1; i < m; ++i) ans += b[i];
	} else {
		for(int i = 1; i < m; ++i) ans += a[i];
	}
	ans += d;
	return ans;
}

void work() {
	int y[2], m[2], d[2];
	for(int i = 0; i < 2; ++i) scanf("%d %d %d", &y[i], &m[i], &d[i]);
	printf("%d\n", cnt[cal(y[1], m[1], d[1])] - cnt[cal(y[0], m[0], d[0]) - 1]);
}

int main() {
	init();
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
