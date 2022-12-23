#include <bits/stdc++.h>
using namespace std;

void work() {
	int n; scanf("%d", &n);
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i) scanf("%d", &b[i]);
	for(int i = 0; i < n; ++i) {
		if(a[i] * 3 < b[i]) {
			printf("%d\n", i + 1);
			return;
		}
	}
	printf("-1\n");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
