#include <bits/stdc++.h>
using namespace std;

void work() {
	int n; scanf("%d", &n);
	if(n < 4) return printf("-1\n"), void();
	if(n % 4 == 0) {
		printf("(4+1)*3+2");
		for(int i = 5; i <= n; i += 4) printf("-%d+%d+%d-%d", i, i + 1, i + 2, i + 3);
		printf("\n");
	} else if(n % 4 == 1) {
		printf("(3*4+5)*(2-1)");
		for(int i = 6; i <= n; i += 4) printf("-%d+%d+%d-%d", i, i + 1, i + 2, i + 3);
		printf("\n");
	} else if(n % 4 == 2) {
		printf("1-2+3+4+5+6");
		for(int i = 7; i <= n; i += 4) printf("-%d+%d+%d-%d", i, i + 1, i + 2, i + 3);
		printf("\n");
	} else if(n % 4 == 3) {
		printf("(5*7-3*6)*(4-1-2)");
		for(int i = 8; i <= n; i += 4) printf("-%d+%d+%d-%d", i, i + 1, i + 2, i + 3);
		printf("\n");
	}
}

int main() {
	work();
	return 0;
}
