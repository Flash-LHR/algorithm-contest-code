#include <bits/stdc++.h>
using namespace std;

string s;

string cal(int n) {
	string s = "";
	while(n) {
		s += n % 2 + '0';
		n >>= 1;
	}
	reverse(s.begin(), s.end());
	return s;
}

int work(int k) {
	int mx = 0;
	for(int l = 0, r = -1; l < k; l = r + 1) {
		while(r + 1 < k  && s[r + 1] == s[l]) ++r;
		if(s[r] == '1') mx = max(mx, r - l + 1);
	}
	return mx;
}

int main() {
	/*s = "0";
	for(int i = 1; i <= 10000; ++i) s += cal(i);
	for(int i = 1; i <= 1000; ++i) {
		if(i == 1 || work(i - 1) != work(i)) {
			printf("i=%d ans=%d ", i, work(i));
			cout << "s=" << s.substr(0, i) << "\n";
		}
	}*/
	for(int i = 1; i <= 5; ++i) {
		int s = 2;
		for(int j = 1; j < (1<<i); ++j) s += __lg(j) + 1;
		printf("%d: %d\n", i, s);
	}
	return 0;
}
