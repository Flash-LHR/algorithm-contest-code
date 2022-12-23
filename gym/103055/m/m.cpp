#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#if 0
void work() {
	int mx = -100;
	for(int i = 1; i <= 20; ++i) {
		int sum = 0;
		for(int j = 1; j <= 20; ++j) {
			int a = 0, b = 0;
			a -= i, b += i;
			a += j, b -= j;
			if(i > j) a += 10, b -= 10;
			if(i < j) a -= 10, b += 10;
			sum += a;
		}
		mx = max(mx, sum);
	}
	printf("mx=%d\n", mx);
}
#else

void work() {
	printf("0.0000\n");
}
#endif

int main() {
	work();
	return 0;
}
