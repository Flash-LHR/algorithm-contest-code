#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void work() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	queue<int> q;
	for(int i = 0, x; i < n; ++i) scanf("%d", &x), q.push(x);
	stack<int> box; vector<int> cur;
	while(!q.empty() || !box.empty()) {
		if(cur.empty()) {
			if(!box.empty()) cur.push_back(box.top()), box.pop();
			else cur.push_back(q.front()), q.pop();
		} else if(!box.empty() && box.top() <= cur.back()) {
			cur.push_back(box.top()), box.pop();
		} else if(!q.empty()) {
			while(!q.empty() && q.front() > cur.back() && box.size() < m) {
				box.push(q.front()); q.pop();
			}
			if(!q.empty() && q.front() <= cur.back()) {
				cur.push_back(q.front()); q.pop();
			} else {
				for(size_t i = 0; i < cur.size(); ++i)
					printf("%d%c", cur[i], " \n"[i == cur.size() - 1]);
				cur.clear();
			}
		} else {
			for(size_t i = 0; i < cur.size(); ++i)
				printf("%d%c", cur[i], " \n"[i == cur.size() - 1]);
			cur.clear();
		}
		if(cur.size() == k) {
			for(size_t i = 0; i < cur.size(); ++i)
				printf("%d%c", cur[i], " \n"[i == cur.size() - 1]);
			cur.clear();
		}
	}
	for(size_t i = 0; i < cur.size(); ++i)
		printf("%d%c", cur[i], " \n"[i == cur.size() - 1]);

}

int main() {
	work();
	return 0;
}
