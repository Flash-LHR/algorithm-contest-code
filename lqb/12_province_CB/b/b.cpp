#include <bits/stdc++.h>
using namespace std;

int cnt[10];

bool check(int n) {
	//n=123 cnt[1,2,3] >= 1
	/**
		n=123
		u1=3
		u2=2
		u3=1
	 */
	while(n) {
		int u = n % 10;
		n /= 10;
		if(cnt[u]) --cnt[u];
		else return false;
	}
	return true;
}

void work() {
	for(int i = 0; i < 10; ++i) cnt[i] = 2021;
	for(int i = 1; ; ++i) {
		if(!check(i)) {
			printf("%d\n", i - 1);
			break;
		}
	}
}

int main() {
	work();
	return 0;
}
