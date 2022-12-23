#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e2;
const int N = (int)1e4;

void work() {
	int n; scanf("%d", &n);
	if(n % 3 == 1) printf("1");
	for(int i = 0; i < n / 3; ++i) printf("21");
	if(n % 3 == 2) printf("2");
	printf("\n");	
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}

