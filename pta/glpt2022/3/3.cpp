#include <bits/stdc++.h>
using namespace std;

void work() {
	int a, b, y[2]; scanf("%d%d%d%d", &a, &b, &y[0], &y[1]);
	int id[2] = {0, 1};
	if(y[0] > y[1]) swap(id[0], id[1]);
	if(y[id[0]] >= a) {
		printf("%d-Y %d-Y\n", y[0], y[1]);
		printf("huan ying ru guan\n");
	} else if(y[id[1]] >= b) {
		printf("%d-Y %d-Y\n", y[0], y[1]);
		printf("qing %d zhao gu hao %d", id[1] + 1, id[0] + 1);
	} else if(y[id[1]] >= a) {
		if(id[0] == 0) printf("%d-N %d-Y\n", y[0], y[1]);
		else printf("%d-Y %d-N\n", y[0], y[1]);
		printf("%d: huan ying ru guan", id[1] + 1);
	} else {
		printf("%d-N %d-N\n", y[0], y[1]);
		printf("zhang da zai lai ba\n");
	}
}

int main() {
	work();
	return 0;
}
