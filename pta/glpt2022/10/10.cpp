#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)24*60*60;

int d[M + 5];
struct node {
	int l, r;
	bool operator<(const node& b) const {
		return l < b.l;
	}
} s[M + 5];

void work() {
	int n; scanf("%d", &n);
	int h[2], m[2], ss[2];
	for(int i = 1; i <= n; ++i) {
		scanf("%d:%d:%d - %d:%d:%d", &h[0], &m[0], &ss[0], &h[1], &m[1], &ss[1]);
		int t0 = h[0] * 60 * 60 + m[0] * 60 + ss[0];
		int t1 = h[1] * 60 * 60 + m[1] * 60 + ss[1];
		if(t0 > t1) swap(t0, t1);
		s[i].l = t0, s[i].r = t1;
	}
	sort(s + 1, s + n + 1);
	if(s[1].l != 0) printf("00:00:00 - %02d:%02d:%02d\n", s[1].l / 3600, s[1].l / 60 % 60, s[1].l % 60);
	for(int i = 2; i <= n; ++i) if(s[i - 1].r != s[i].l) {
		printf("%02d:%02d:%02d - %02d:%02d:%02d\n", 
				s[i - 1].r / 3600, s[i - 1].r / 60 % 60, s[i - 1].r % 60, 
				s[i].l / 3600, s[i].l / 60 % 60, s[i].l % 60);
	}
	if(s[n].r != M - 1)
		printf("%02d:%02d:%02d - 23:59:59\n", 
				s[n].r / 3600, s[n].r / 60 % 60, s[n].r % 60);
}

int main() {
	work();
	return 0;
}
