#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)3e3;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

pair<int, int> a[7];
int b[7], c[7];

bool check(int sta) {
	bool vis[4] = {0};
	memcpy(c, b, sizeof b);
	for(int i = 0; i < 3; ++i) if(sta>>i&1) {
		vis[i + 1] = 1;
		for(int j = 1; j <= 6; ++j) if(a[j].first == i + 1 || a[j].second == i + 1) c[j] = 3;
	}

	int cnt = __builtin_popcount(sta);
	bool update = true;
	while(update) {
		update = false;
		for(int i = 1; i <= 3; ++i) if(!vis[i]) {
			int pre = 3, ok = 1;
			for(int j = 1; j <= 6; ++j) if(a[j].first == i || a[j].second == i) {
				if(c[j] == 3) continue;
				if(pre == 3) {
					if(c[j] == 1 && (a[j].first > i || a[j].second > i)) pre = -1;
					else if(c[j] == 1 && (a[j].first < i || a[j].second < i)) pre = 1;
					else if(c[j] == 0 && (a[j].first < i || a[j].second < i)) pre = -1;
					else if(c[j] == 0 && (a[j].first > i || a[j].second > i)) pre = 1;
					else {
						assert(0);
					}
				} else {
					if(c[j] == 1 && (a[j].first > i || a[j].second > i)) {
						if(pre != -1) ok = 0;
					}
					if(c[j] == 1 && (a[j].first < i || a[j].second < i)) {
						if(pre != 1) ok = 0;
					}
					if(c[j] == 0 && (a[j].first < i || a[j].second < i)) {
						if(pre != -1) ok = 0;
					}
					if(c[j] == 0 && (a[j].first > i || a[j].second > i)) {
						if(pre != 1) ok = 0;
					}
				}
			}
			if(ok) {
				++cnt;
				vis[i] = 1;
				for(int j = 1; j <= 6; ++j) if(a[j].first == i || a[j].second == i) c[j] = 3;
				update = true;
				break;
			}
		}
	}
	assert(cnt <= 3);
	return cnt == 3;
}

void work() {
	a[1] = make_pair(1, 2);
	a[2] = make_pair(1, 3);
	a[3] = make_pair(2, 3);
	a[4] = make_pair(1, 2);
	a[5] = make_pair(1, 3);
	a[6] = make_pair(2, 3);
	char s[100];
	for(int i = 1; i <= 6; ++i) {
		scanf("%s", s);
		if(s[0] == 't') b[i] = 1;
		else b[i] = 0;
	}
	int ans = 0;
	for(int i = 0; i < (1<<3); ++i) {
		if(check(i)) ++ans;
	}
	printf("%d\n", ans);
}

int main() {
	int T = 1; //scanf("%d", &T);
	while(T--) work();
	return 0;
}
