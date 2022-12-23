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

int n, m;

queue<pair<int, int>> q;
vector<vector<bool>> vis;
vector<pair<int, int>> step;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs() {
	vis = vector<vector<bool>>(n, vector<bool>(m, 0));
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) vis[i][j] = 0;
	while(!q.empty()) q.pop();
	step.clear();
	vector<int> ix, iy;
	if(n & 1) ix.push_back((n + 1) / 2 - 1); else ix.push_back(n / 2 - 1), ix.push_back(n / 2 + 1 - 1);
	if(m & 1) iy.push_back((m + 1) / 2 - 1); else iy.push_back(m / 2 - 1), iy.push_back(m / 2 + 1 - 1);
	for(auto x: ix) for(auto y: iy) {
		q.push(make_pair(x, y));
		vis[x][y] = 1;
		step.push_back(make_pair(x, y));
	}
	while(!q.empty()) {
		auto [ux, uy] = q.front(); q.pop();
		for(int i = 0; i < 4; ++i) {
			int vx = ux + dx[i], vy = uy + dy[i];
			if(vx >= 0 && vx < n && vy >= 0 && vy < m && !vis[vx][vy]) {
				vis[vx][vy] = 1;
				q.push(make_pair(vx, vy));
				step.push_back(make_pair(vx, vy));
			}
		}
	}
}

void work() {
	scan(n), scan(m);
	vector<int> v;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			v.push_back(max(i, n - i - 1) + max(j, m - j - 1));
		}
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n * m; ++i) print(v[i], i == n * m - 1 ? '\n' : ' ');
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

