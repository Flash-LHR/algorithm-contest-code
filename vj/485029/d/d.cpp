#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e2;
const int N = (int)1e4;

stack<pair<int, int>> st;
//<栈顶元素，连续个数>

void work() {
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i = 1, a; i <= n; ++i) {
		scanf("%d", &a);
		if(st.empty()) {
			st.push(make_pair(a, 1));
			++ans;
		} else {
			pair<int, int> p = st.top();
			if(p.first == a) {
				st.pop();
				p.second++;
				if(p.second == a) ans -= a - 1;
				else st.push(p), ++ans;
			} else {
				st.push(make_pair(a, 1));
				++ans;
			}
		}
		printf("%d\n", ans);
	}
}

int main() {
	work();
	return 0;
}
