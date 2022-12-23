#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

int n;
char s[M + 5], t[M + 5];

struct HT {
	int mod, base;
	int p[M + 5], h[M + 5];

	HT(int _mod, int _base): mod(_mod), base(_base){}
	void init(char *s) {
		p[0] = 1;
		for(int i = 1; s[i]; ++i) {
			p[i] = (ll)p[i - 1] * base % mod;
			h[i] = ((ll)h[i - 1] * base + s[i] - 'A' + 1) % mod;
		}
	}

	int getH(int l, int r) {
		return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
	}
} ht[4] = {HT((int)1e9 + 7, 131), HT((int)1e9 + 7, 131), 
           HT((int)1e9 + 7, 131), HT((int)1e9 + 7, 131)};

int cal1(int a, int b) {
	int mx = 0;
	 for(int i = 1; i <= n; ++i) {
		 int l = 0, r = min(i - 1, n - i), mid;
		 while(l < r) {
			 mid = (l + r + 1) >> 1;
			 if(ht[a].getH(i - mid, i - 1) == ht[b].getH(n - i - mid + 1, n - i)) l = mid;
			 else r = mid - 1;
		 }
		 mx = max(mx, 2 * r + 1);
		 if(i == n) continue;
		 l = 0, r = min(i, n - i);
		 while(l < r) {
			mid = (l + r + 1) >> 1;
			if(ht[a].getH(i - mid + 1, i) == ht[b].getH(n - i - mid + 1, n - i)) l = mid;
			else r = mid - 1;
		 }
		 mx = max(mx, 2 * r);
	 }
	 return mx;
}

int cal2() {
	for(int i = 1; i <= n; ++i) {
		int l = 0, r = min(i - 1, n - i + 2), mid;
		while(l < r) {
			mid = (l + r + 1) >> 1;
			if(ht[0].getH(j - mid, j - 1) == ) l = mid;
			else r = mid - 1;
		}
	}
}

void work() {
	scanf("%d%s%s", &n, s + 1, t + 1);
	ht[0].init(s), ht[1].init(t);
	reverse(s + 1, s + n + 1), reverse(t + 1, t + n + 1);
	ht[2].init(s), ht[3].init(t);
	int mx = max(cal1(0, 2), cal1(1, 3));
	mx = max(mx, cal2());
}

int main() {
	work();
	return 0;
}
