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

int n, m;
char s[M + 5][M + 5];
int dis[M + 5][M + 5];

struct qnode {
	int x, y;
	qnode(int _x = 0, int _y = 0): x(_x), y(_y){}
} pre[M + 5][M + 5];
deque<qnode> q;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int toInt(char ch) {
	if(ch == 'R') return 0;
	if(ch == 'L') return 1;
	if(ch == 'D') return 2;
	if(ch == 'U') return 3;
	assert(0);
}

void bfs() {
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			dis[i][j] = inf;
			pre[i][j].x = pre[i][j].y = -1;
		}
	}
	q.push_back(qnode(1, 1));
	dis[1][1] = 0;
	qnode u, v;
	while(!q.empty()) {
		u = q.front(); q.pop_front();
		int dir = toInt(s[u.x][u.y]);
		for(int i = 0; i < 4; ++i) {
			v.x = u.x + dx[i], v.y = u.y + dy[i];
			if(v.x < 1 || v.x > n || v.y < 1 || v.y > m) continue;
			int w = !(i == dir);
			if(dis[v.x][v.y] > dis[u.x][u.y] + w) {
				dis[v.x][v.y] = dis[u.x][u.y] + w;
				if(w == 0) q.push_front(v);
				else q.push_back(v);
				pre[v.x][v.y].x = u.x, pre[v.x][v.y].y = u.y;
			}
		}
	}
}

void work() {
	scan(n), scan(m);
	for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	bfs();
	int ans = dis[n][m];
	print(ans, '\n');
	int x = n, y = m;
	while(x != 1 || y != 1) {
		int xx = pre[x][y].x, yy = pre[x][y].y;
		int dir = toInt(s[xx][yy]);
		if(xx + dx[dir] == x && yy + dy[dir] == y) ;
		else if(xx + 1 == x) printf("%d %d D\n", xx, yy);
		else if(xx - 1 == x) printf("%d %d U\n", xx, yy);
		else if(yy + 1 == y) printf("%d %d R\n", xx, yy);
		else if(yy - 1 == y) printf("%d %d L\n", xx, yy);
		x = xx, y = yy;
	}
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

