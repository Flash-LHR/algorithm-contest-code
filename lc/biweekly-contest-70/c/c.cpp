#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T& x) {
	x = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
	x *= f;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch) {
	print(x), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const db eps = 1e-6;
const int M = (int)1e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;


class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
		int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        vector<vector<int>> ans;
		int n = (int)grid.size(), m = (int)grid[0].size();
		vector<vector<bool>> vis(n, vector<bool>(m, false));
		vector<vector<int>> dis(n, vector<int>(m, 0));
		queue<vector<int>> q;
		q.push(start), vis[start[0]][start[1]] = 1, dis[start[0]][start[1]] = 0;
		while(!q.empty()) {
			vector<int> u = q.front(); q.pop();
			if(pricing[0] <= grid[u[0]][u[1]] && grid[u[0]][u[1]] <= pricing[1]) ans.push_back(u);
			for(int i = 0; i < 4; ++i) {
				vector<int> v{u[0] + dx[i], u[1] + dy[i]};
				if(0 <= v[0] && v[0] < n && 0 <= v[1] && v[1] < m && !vis[v[0]][v[1]] && grid[v[0]][v[1]] != 0) {
					vis[v[0]][v[1]] = 1;
					dis[v[0]][v[1]] = dis[u[0]][u[1]] + 1;
					q.push(v);
				}
			}
		}
		sort(ans.begin(), ans.end(), [&](const vector<int>& a, const vector<int>& b) {
			if(dis[a[0]][a[1]] != dis[b[0]][b[1]]) return dis[a[0]][a[1]] < dis[b[0]][b[1]];
			if(grid[a[0]][a[1]] != grid[b[0]][b[1]]) return grid[a[0]][a[1]] < grid[b[0]][b[1]];
			if(a[0] != b[0]) return a[0] < b[0];
			return a[1] < b[1];
				});
		if((int)ans.size() > k) ans.erase(ans.begin() + k, ans.end());
		return ans;
    }
};

/*int main() {
	vector<vector<int>> grid{{1,2,0,1}, {1,3,0,1}, {0,2,5,1}};
	vector<int> pricing{2, 5};
	vector<int> start{0, 0};
	int k = 3;
	
	vector<vector<int>> grid{{1,2,0,1}, {1,3,3,1}, {0,2,5,1}};
	vector<int> pricing{2, 3};
	vector<int> start{2, 3};
	int k = 2;

	vector<vector<int>> grid{{1,1,1}, {0,0,1}, {2,3,4}};
	vector<int> pricing{2, 3};
	vector<int> start{0, 0};
	int k = 3;
	Solution A;
	vector<vector<int>> ans = A.highestRankedKItems(grid, pricing, start, k);
	for(auto x: ans) {
		for(auto y: x) cout << y << " ";
		cout << "\n";
	}
	return 0;
} */
