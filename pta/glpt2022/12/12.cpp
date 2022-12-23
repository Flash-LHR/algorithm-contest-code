#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)5e2;
const int inf = 0x3f3f3f3f;

int n;
char sex[M + 5];
int dis[M + 5][M + 5];
int d[M + 5];

void work() {
	scanf("%d", &n);
	memset(dis, inf, sizeof dis);
	for(int i = 1; i <= n; ++i) {
		dis[i][i] = 0; getchar();
		scanf("%c", &sex[i]);
		int k; scanf("%d", &k);
		for(int j = 1, v, w; j <= k; ++j) {
			scanf("%d:%d", &v, &w);
			dis[i][v] = w;
		}
	}
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	vector<int> id[2];
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) if(sex[i] != sex[j]) {
			d[i] = max(d[i], dis[j][i]);
		}
		int p = (sex[i] == 'F' ? 0 : 1);
		if(id[p].empty()) id[p].push_back(i);
		else if(d[i] < d[id[p][0]]) {
			id[p].clear();
			id[p].push_back(i);
		} else if(d[i] == d[id[p][0]]) id[p].push_back(i);
	}
	for(int i = 0; i < 2; ++i) {
		for(size_t j = 0; j < id[i].size(); ++j)
			printf("%d%c", id[i][j], " \n"[j == id[i].size() - 1]);
	}
}

int main() {
	work();
	return 0;
}
