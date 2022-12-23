#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e6;
const int mod = 998244353;

int n;
string s[M + 5];
int nx[M * 2 + 5];

void work() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> s[i];
	int mi = 0; for(int i = 0; i < n; ++i) if(s[i].size() < s[mi].size()) mi = i;
	for(int i = 0; i < n; ++i) if(s[i].size() == s[mi].size()) {
		for(size_t j = 0; j < s[mi].size(); ++j) if(s[i][j] != s[mi][j]) {
			for(int k = 0; k < n; ++k) cout << "0\n";
			return;
		}
	}
	nx[0] = -1;
	for(int i = 1, j = -1; i < (int)s[mi].size(); ++i) {
		while(~j && s[mi][j + 1] != s[mi][i]) j = nx[j];
		if(s[mi][j + 1] == s[mi][i]) ++j;
		nx[i] = j;
	}
	int ans = 1;
	for(int i = 0; i < n; ++i) if(s[mi].size() < s[i].size()) {	
		int cnt = 0;
		for(int j = 0, k = -1; j < (int)s[i].size(); ++j) {
			while(~k && s[i][j] != s[mi][k + 1]) k = nx[k];
			if(s[i][j] == s[mi][k + 1]) ++k;
			if(k == (int)s[mi].size() - 1) {
				++cnt;
				k = nx[k];
			}
		}
		ans = (ll)ans * cnt % mod;
	}
	for(int i = 0; i < n; ++i) cout << (s[i].size() == s[mi].size() ? ans : 0) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	work();
	return 0;
}
