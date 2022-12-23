#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;
const int inf = 0x3f3f3f3f;

int n, m;
int p[M + 5], q[M + 5];
int tp,  st[M + 5];
vector<int> v[2];

void work() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i) scanf("%d %d", &p[i], &q[i]);
	for(int l = 1, r = 0; l <= m; l = r + 1) {
		int pos = (p[l] ? inf : -inf);
		while(r + 1 <= n && p[l] == p[r + 1]) {
			++r;
			pos = (p[r] ? min(pos, q[r]) : max(pos, q[r]));
		}
		if(!tp && p[r]) continue;
		while(tp >= 2 && (p[r] ? st[tp - 1] >= pos : st[tp - 1] <= pos)) tp -= 2;
		st[++tp] = pos;
	}
	int l = 1, r = n, cur = n;
	for(int i = 1; i <= tp && l <= r; ++i) {
		if(i & 1) while(l <= r && r > st[i]) v[1].push_back(cur--), --r;
		else 	  while(l <= r && l < st[i]) v[0].push_back(cur--), ++l;
	}
	if(l <= r) while(l <= r) v[!(tp&1)].push_back(cur--), ++l;
	sort(v[0].begin(), v[0].end()), reverse(v[0].begin(), v[0].end()), reverse(v[1].begin(), v[1].end());
	int flag = 0;
	for(int i = 0; i < (int)v[0].size(); ++i) {
		if(flag) printf(" ");
		printf("%d", v[0][i]);
		flag = 1;
	}
	for(int i = 0; i < (int)v[1].size(); ++i) {
		if(flag) printf(" ");
		printf("%d", v[1][i]);
		flag = 1;
	}
	printf("\n");
}

int main() {
	work();
	return 0;
}
