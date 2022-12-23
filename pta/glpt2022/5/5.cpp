#include <bits/stdc++.h>
using namespace std;

void work() {
	vector<int> v(6); int n;
	for(int i = 0; i < 6; ++i) scanf("%d", &v[i]);
	scanf("%d", &n);
	for(int i = 0; i < 6; ++i) {
		vector<int> vis(7, 0);
		vis[v[i]] = 1;
		for(int j = 1; j <= n; ++j) {
			for(int k = 6; k >= 1; --k) {
				if(!vis[k]) {
					vis[k] = 1;
					v[i] = k;
					break;
				}
			}
		}
		printf("%d%c", v[i], " \n"[i == 5]);
	}
}	

int main() {
	work();
	return 0;
}
