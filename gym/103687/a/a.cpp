#include <bits/stdc++.h>
using namespace std;

void work() {
	int a, b; scanf("%d%d", &a, &b);
	if(a == b) printf("0\n");
	else if(a < b) {
		if((b - a)&1) printf("1\n");
		else if(((b-a)/2)&1) printf("2\n");
		else printf("3\n");
	} else {
		if((a - b)&1) printf("2\n");
		else printf("1\n");
	}
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
