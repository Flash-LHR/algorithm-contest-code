#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T &n) {
	n = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) {n = n * 10 + ch - '0'; ch = getchar();}
	if(f == -1) n = -n;
}

typedef long long ll;

const int M = (int)1e6;

struct HT {
	int base, mod;
	int p[M + 5], h[M + 5];

	void init(char *s) {
		base = 131, mod = (int)1e9 + 7;
		p[0] = 1, h[0] = 0;
		for(int i = 1; s[i]; ++i) {
			p[i] = (ll)p[i - 1] * base % mod;
			h[i] = ((ll)h[i - 1] * base + s[i] - 'a' + 1) % mod;
		}
	}

	int getH(int l, int r) {
		return (h[r] - (ll)h[l - 1] * p[r - l + 1] % mod + mod) % mod;
	}
} ht[2];

char s[M + 5];

void work() {
	int n, q; scan(n), scan(q);
	scanf("%s", s + 1);
	ht[0].init(s);
	reverse(s + 1, s + n + 1);
	ht[1].init(s);
	for(int i = 1, l, r; i <= q; ++i) {
		scan(l), scan(r);
		if(ht[0].getH(l, r) == ht[1].getH(n - r + 1, n - l + 1)) printf("Budada\n");
		else if((r - l + 1) & 1) printf("Putata\n");
		else printf("Budada\n");
	}

}

int main() {
	work();
	return 0;
}
