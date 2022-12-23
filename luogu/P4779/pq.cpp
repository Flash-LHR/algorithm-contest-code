#include <bits/stdc++.h>
using namespace std;

struct qnode {
	int a;
	qnode(int _a): a(_a) {}
	bool operator<(const qnode& b) const {
		return a > b.a;
	}
};
//x y
//x < y: x.a > y.a
//priority_queue<int, vector<int>, greater<int>> q;
priority_queue<qnode> q;

int main() {
	q.push(qnode(1));
	q.push(qnode(2));
	q.push(qnode(3));
	while(!q.empty()) {
		printf("%d\n", q.top().a);
		q.pop();
	}
	return 0;
}
