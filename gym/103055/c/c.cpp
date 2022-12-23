#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e5;

int x[8], y[8], z[8];
int dis[8];

int getDis(int a, int b) {
	int dx = x[a] - x[b];
	int dy = y[a] - y[b];
	int dz = z[a] - z[b];
	return dx * dx + dy * dy + dz * dz;
}

void work() {
	for(int i = 0; i < 8; ++i) scanf("%d %d %d", &x[i], &y[i], &z[i]);
	for(int i = 0; i < 8; ++i) dis[i] = getDis(0, i);
	sort(dis, dis + 8);
	if(dis[1] == 0) return printf("NO\n"), void();
	for(int i = 1; i <= 3; ++i) if(dis[i] != dis[1]) return printf("NO\n"), void();
	for(int i = 4; i <= 6; ++i) if(dis[i] != 2 * dis[1]) return printf("NO\n"), void();
	if(dis[7] != 3 * dis[1]) return printf("NO\n"), void();

	int sx = accumulate(x, x + 8, 0),
		sy = accumulate(y, y + 8, 0), 
		sz = accumulate(z, z + 8, 0);
	for(int i = 0; i < 8; ++i) {
		int dx = sx - 8 * x[i], 
			dy = sy - 8 * y[i], 
			dz = sz - 8 * z[i];
		dis[i] = dx * dx + dy * dy + dz * dz;
	}
	sort(dis, dis + 8);
	if(dis[0] != dis[7]) return printf("NO\n"), void();
	printf("YES\n");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
