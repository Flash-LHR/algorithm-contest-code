#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

int n, m;
set<int> g[M + 5];
stack<int> st;
int cur, ans;

void dfs(int u) {
	if(cur > n) return;
	st.push(u);
	while(cur <= n) {
		while(!g[u].empty() && *g[u].begin() < cur) g[u].erase(g[u].begin());
		if(g[u].empty()) {
			while(!st.empty()) {
				while(!g[st.top()].empty() && *g[st.top()].begin() < cur) g[st.top()].erase(g[st.top()].begin());
				if(g[st.top()].size() == 0) st.pop();
				else break;
			}
			if(st.empty()) {
				++ans;
				dfs(cur++);
			} else {
				if(g[st.top()].count(cur)) {
					break;
				}
				else {
					++ans;
					dfs(cur++);
				}
			}
		} else if(*g[u].begin() == cur) {
			g[u].erase(g[u].begin());
			dfs(cur++);
		}
		else {
			++ans;
			dfs(cur++);
		}
	}
	if(!st.empty() && st.top() == u) st.pop();
}

void work() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; ++i) g[i].clear();
	for(int i = 1, u, v; i <= m; ++i) {
		scanf("%d %d", &u, &v);
		if(u > v) swap(u, v);
		if(u < v) g[u].insert(v);
	}
	cur = 2, ans = 0;
	dfs(1);
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
