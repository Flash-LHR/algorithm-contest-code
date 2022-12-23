#include <bits/stdc++.h>
using namespace std;

int n = 20, m = 21;
set<set<pair<int, int>>> st2;

void work() {
	for(int i = 0; i < n; ++i) //枚举第一个点p1
	for(int j = 0; j < m; ++j)
	for(int k = 0; k < n; ++k) //枚举第二个点p2
	for(int l = 0; l < m; ++l) if(i != k || j != l) {
		set<pair<int, int>> st;//维护p1p2确定直线上的所有点
		for(int o = 0; o < n; ++o) //枚举点p
		for(int p = 0; p < m; ++p) {
			if((o - i) * (l - j) == (k - i) * (p - j)) { //向量法断点p是否在p1p2确定的直线上
				st.insert(make_pair(o, p));
			}
		}
		st2.insert(st);
	}
	cout << st2.size() << "\n";
}

int main() {
	work();
	return 0;
}
