#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)30;

ll f[M + 5];

void init() {
	f[0] = 1;
	f[1] = 3;
	for(int i = 2; i <= M; ++i) {
		f[i] = f[i - 1] + (1<<(i-1)) * (i - 1 + 1);
	}
	for(int i = M; i >= 2; --i) f[i] = f[i - 1];
	f[0] = 1, f[1] = 2;
}

void work() {
	int k; scanf("%d", &k);
	for(int i = M; i >= 0; --i) if(f[i] <= k) {printf("%d\n", i); break;}
}

int main() {
	init();
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
