#include <bits/stdc++.h>
using namespace std;

typedef double db;

const int M = (int)1e3;

int n, m;
char s[M + 5];
int sum[M + 5][M + 5];
bool vis[M + 5][M + 5];

int f(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}

bool kulong(int i, int j) {
	return f(i, j + 1, i, j + 2) == 0 &&
		   f(i + 1, j, i + 2, j + 3) == 0 &&
		   f(i + 3, j + 1, i + 3, j + 2) == 0;
}

int calc() {
	int ans = 0;
	for(int i = 1; i + 17 - 1 <= n; ++i) for(int j = 1; j + 10 - 1 <= m; ++j) if(!vis[i][j]) {
		if(kulong(i + 3, j + 3) && kulong(i + 10, j + 3) && f(i, j, i + 16, j + 9) == 146) {
			++ans;
			for(int k = i; k <= i + 16; ++k) for(int l = j; l <= j + 9; ++l) vis[k][l] = 1;
		}
	}
	for(int i = 1; i + 10 - 1 <= n; ++i) for(int j = 1; j + 17 - 1 <= m; ++j) if(!vis[i][j]) {
		if(kulong(i + 3, j + 3) && kulong(i + 3, j + 10) && f(i, j, i + 9, j + 16) == 146) {
			++ans;
			for(int k = i; k <= i + 9; ++k) for(int l = j; l <= j + 16; ++l) vis[k][l] = 1;
		}
	}
	return ans;
}

int cals() {
	int ans = 0;
	for(int i = 1; i + 3 <= n; ++i) for(int j = 1; j + 3 <= m; ++j) if(!vis[i][j] && kulong(i, j)) {
		if(!(i - 3 >= 1 && j - 3 >= 1 && i + 6 <= n && j + 6 <= m)) continue;
		if(f(i - 3, j - 3, i + 6, j + 6) != 88) continue;
		if(i - 7 >= 1 && f(i - 7, j - 3, i - 4, j - 1) == 12) ++ans;
		else if(i + 10 <= n && f(i + 7, j - 3, i + 10, j - 1) == 12) ++ans;
		else if(i - 7 >= 1 && f(i - 7, j + 4, i - 4, j + 6) == 12) ++ans;
		else if(i + 10 <= n && f(i + 7, j + 4, i + 10, j + 6) == 12) ++ans;
		else if(j + 10 <= m && f(i + 4, j + 7, i + 6, j + 10) == 12) ++ans;
		else if(j - 7 >= 1 && f(i + 4, j - 7, i + 6, j - 4) == 12) ++ans;
		else if(j + 10 <= m && f(i - 3, j + 7, i - 1, j + 10) == 12) ++ans;
		else if(j - 7 >= 1 && f(i - 3, j - 7, i - 1, j - 4) == 12) ++ans;
	}
	return ans;
}

void work() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) {
		scanf("%s", s + 1);
		for(int j = 1; j <= m; ++j)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[j] == '#');
	}
	int c = calc();
	int s = cals();
	printf("%d %d\n", c, s);
}

int main() {
	int T = 1; //scanf("%d", &T);
	while(T--) work();
	return 0;
}

