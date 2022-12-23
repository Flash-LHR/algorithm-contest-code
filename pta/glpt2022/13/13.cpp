#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = 26 * 27 * 27 + 26 * 27 + 26;
const int inf = 0x3f3f3f3f;

int n;
string di[M + 5];

struct graph {
	int in[M + 5];
	vector<int> g[M + 5];
	vector<int> ans;

	graph() {
		memset(in, 0, sizeof in);
	}

	void add(int u, int v) {
		++in[v];
		g[u].push_back(v);
	}

	void topo() {
		priority_queue<int, vector<int>, greater<int>> q;
		for(int i = 1; i <= M; ++i) if(!di[i].empty() && in[i] == 0) {
			q.push(i);
		}
		while(!q.empty()) {
			int u = q.top(); q.pop();
			ans.push_back(u);
			for(const int &v: g[u]) {
				if(--in[v] == 0) {
					q.push(v);
				}
			}
		}
	}
} g;

void work() {
	cin >> n;
	string s; vector<int> ss[2];
	for(int i = 0, u = 0; i < n; ++i) {
		cin >> s; ss[u].clear();
		for(int l = 0, r = -1; l < (int)s.size(); l = r + 1) {
			int xu = 0;
			while(r + 1 < (int)s.size() && s[r + 1] != '.')
				xu = xu * 27 + s[++r] - 'a' + 1;
			if(di[xu].empty()) di[xu] = s.substr(l, r - l + 1);
			ss[u].push_back(xu);
			++r;
		}
		if(i && ss[u^1].size() == ss[u].size()) {
			for(size_t j = 0; j < s.size(); ++j) {
				if(ss[u^1][j] != ss[u][j]) {
					g.add(ss[u^1][j], ss[u][j]);
					break;
				}
			}
		}
		u ^= 1;
	}
	g.topo();
	for(size_t i = 0; i < g.ans.size(); ++i)
		cout << di[g.ans[i]] << ".\n"[i == g.ans.size() - 1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	work();
	return 0;
}
