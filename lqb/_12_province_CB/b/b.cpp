#include <bits/stdc++.h>
using namespace std;

int cnt[10];

int gao(int n) {
	while(n) {
		int u = n % 10;
		if(cnt[u] == 0) return 0;
		--cnt[u];
		n/= 10;
	}
	return 1;
}

void work() {
	for(int i = 0; i < 10; ++i) cnt[i] = 2021;
	for(int i = 1; ; ++i) {
		if(!gao(i)) {
			printf("%d\n", i - 1);
			break;
		}
	}
}

int main() {
	work();
	return 0;
}
