#include <bits/stdc++.h>
using namespace std;

const int M = (int)3e4;

struct trie {
	int cnt;
	int nx[M + 5][26];
	bool vis[M + 5];

	trie() {
		cnt = 1;
		memset(nx, 0, sizeof nx);
		memset(vis, 0, sizeof vis);
	}

	void insert(const string &s) {
		int u = 1;
		for(const char &v: s) {
			if(nx[u][v - 'a'] == 0) nx[u][v - 'a'] = ++cnt;
			u = nx[u][v - 'a'];
		}
		vis[u] = 1;
	}

	bool query(const string &s) {
		int u = 1;
		for(size_t i = 0; i < s.size(); ++i) {
			u = nx[u][s[i] - 'a'];
			if(i != s.size() - 1 && vis[u]) return 0;
		}
		return 1;
	}
} tr;

int n;
string s[M + 5];

void work() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
		tr.insert(s[i]);
	}
	vector<int> id;
	for(int i = 0; i < n; ++i) if(tr.query(s[i])) id.push_back(i);
	cout << id.size() << "\n";
	for(const int &x: id) cout << s[x] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	work();
	return 0;
}
