#include <bits/stdc++.h>
using namespace std;

int n = 20, m = 21;
set<set<pair<int, int>>> st;

void work() {
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < m; ++j)
	for(int k = 0; k < n; ++k)
	for(int l = 0; l < m; ++l) if(i != k || j != l) {
		set<pair<int, int>> tmp;
		for(int o = 0; o < n; ++o)
		for(int p = 0; p < m; ++p) {
			if((k - i) * (p - j) == (o - i) * (l - j)) tmp.insert(make_pair(o, p));
		}
		st.insert(tmp);
	}
	printf("%d\n", (int)st.size());
}

int main() {
	work();
	return 0;
}

