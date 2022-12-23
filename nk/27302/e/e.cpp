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
const int M = (int)1e3;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m, tt;

struct node {
	int x, y;
	node(int _x = 0, int _y = 0): x(_x), y(_y){}
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

queue<node> q;
bool ban[M + 5][M + 5];
bool vis[M + 5][M + 5];
int dis[M + 5][M + 5];
node s[M + 5], t[M + 5];

int bfs(node s, node t) {
	while(!q.empty()) q.pop();
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) vis[i][j] = ban[i][j];
	vis[s.x][s.y] = 1, dis[s.x][s.y] = 0; q.push(s);
	while(!q.empty()) {
		node u = q.front(); q.pop();
		if(u.x == t.x && u.y == t.y) return dis[u.x][u.y];
		for(int i = 0; i < 4; ++i) {
			node v(u.x + dx[i], u.y + dy[i]);
			if(v.x >= 0 && v.x < n && v.y >= 0 && v.y < n && !vis[v.x][v.y]) {
				vis[v.x][v.y] = 1;
				dis[v.x][v.y] = dis[u.x][u.y] + 1;
				q.push(v);
			}
		}
	}
	return -1;
}



void work() {
	scan(n), scan(m);
	for(int i = 0, x, y; i < m; ++i) {
		scan(x), scan(y);
		ban[x][y] = 1;
	}
	scan(tt);
	for(int i = 0; i < tt; ++i) {
		scan(s[i].x), scan(s[i].y), scan(t[i].x), scan(t[i].y);
		ban[s[i].x][s[i].y] = ban[t[i].x][t[i].y] = 1;
	}
	for(int i = 0; i < tt; ++i) {
		ban[s[i].x][s[i].y] = ban[t[i].x][t[i].y] = 0;
		print(bfs(s[i], t[i]), '\n');
		ban[s[i].x][s[i].y] = ban[t[i].x][t[i].y] = 1;
	}
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; //scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

