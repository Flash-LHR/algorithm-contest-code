#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

int n;
char s[M + 5];
int p[M + 5];

void dfs(int l, int r) {
	if(l > r) return;
	if(s[l] == '-' || s[l] == ')') {
		printf("%d ", l);
		dfs(l + 1, r);
	} else {
		dfs(l + 1, p[l]);
		printf("%d ", l);
		dfs(p[l] + 1, r);
	}
}

void work() {
	scanf("%d%s", &n, s + 1);
	stack<int> st;
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '(') st.push(i);
		else if(s[i] == ')') {
			p[st.top()] = i;
			st.pop();
		}
	}
	dfs(1, n);
	printf("\n");
}

int main() {
	work();
	return 0;
}
