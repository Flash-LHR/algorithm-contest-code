#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[10], len, sum;

bool check(int pre) {
	int mx = 0; for(int i = 0; i < 10; ++i) if(pre != i) mx = max(mx, a[i]);
	if(a[pre] <= mx) return sum - mx >= mx - 1;
	return sum - a[pre] >= a[pre];
}

void work() {
	for(int i = 0; i <= 9; ++i) scanf("%d", &a[i]);
	len = sum = accumulate(a, a + 10, 0);
	if(sum == 1) {
		for(int i = 0; i <= 9; ++i) if(a[i]) printf("%d\n", i);
		return;
	}
	if(sum == 0) {
		printf("-1\n");
		return;
	}
	vector<int> ans;
	for(int i = 0, pre = 0; i < len; ++i) {
		for(int j = 0; j < 10; ++j) if(a[j] && j != pre) {
			sum--;
			--a[j];
			if(check(j)) {
				ans.push_back(j);
				pre = j;
				break;
			}
			sum++;
			++a[j];
		}
	}
	if(sum) printf("-1");
	else {
		for(const int& v: ans) printf("%d", v);
	}
	printf("\n");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
