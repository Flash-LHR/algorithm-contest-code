/*************************************************************************
    > File Name: b.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sun Nov 21 11:15:41 2021
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define state(x) (1<<(x))
#define endl '\n'
#define eb emplace_back
constexpr int Ma = 1e5 + 100, inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

int sign(int x) {
	return x < 0 ? -1 : 1;
}

void solve() {
	string aa, bb; cin >> aa >> bb;
	//cerr << aa << ' ' << bb << endl;
	int a[4], b[4];
	for (int i = 0; i < 4; i++) a[i] = aa[i] - '0', b[i] = bb[i] - '0';
	int ans{inf};
	for (int st = 0; st < (1 << 4); ++st) {
		int num[4], bnum[4];
		//cerr << bitset<4>(st) << endl;
		for (int i = 0; i < 4; i++) {
			if (st & state(i))
				num[i] = b[i] - a[i];
			else num[i] = a[i] - b[i];
			if (num[i] < 0) num[i] += 10;
			if (!(st & state(i))) num[i] = -num[i];
			//cerr << num[i] << ' ';
		}
		memcpy(bnum, num, sizeof num);
		//cerr << endl;
		for (int k1 = 0; k1 < 2; k1++) {
			if (k1 and bnum[1] != 0) break;
			for (int k2 = 0; k2 < 2; k2++) {
				if (k2 and bnum[2] != 0) break;
				memcpy(num, bnum, sizeof bnum);
				if (k1) num[1] = (st & state(1)) ? 10 : -10;
				if (k2) num[2] = (st & state(2)) ? 10 : -10;
				int tmp{0};
				for (int i = 3; i >= 0; i--) {
					for (int j = 0; j + i < 4; ++j) {
						int val = num[j];
						for (int k = j + 1; k <= j + i; ++k) {
							if (sign(num[k]) != sign(num[j])) {
								val = 0; break;
							} else if (sign(num[j]) == -1)
								val = max(val, num[k]);
							else val = min(val, num[k]);
						}
						for (int k = j; k <= j + i; ++k)
							num[k] -= val;
						tmp += abs(val);
					}
				}
				ans = min(ans, tmp);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n;
	while (n--) solve();

	return 0;
}

