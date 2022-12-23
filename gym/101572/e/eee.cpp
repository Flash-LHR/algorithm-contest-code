#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T& x)
{
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
    x *= f;
}

template <typename T>
void print(T x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch)
{
    print(x), putchar(ch);
}

typedef double db;
typedef long long ll;

const int M = (int)5e2;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, m;
int a[M + 5][M + 5];
vector<int> g[M * M + 5];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dis[M * M + 5];
bool vis[M * M + 5];

inline int id(int x, int y)
{
    return x * m + y;
}

struct qnode
{
    int dis, u;
    qnode(int _dis, int _u): dis(_dis), u(_u){}
    bool operator<(const qnode& b) const
    {
        return dis > b.dis;
    }
};
priority_queue<qnode> q;

void spfa(int s)
{
    dis[s] = a[s / m][s % m], vis[s] = 1;
    q.push(qnode(dis[s], s));
    while(!q.empty())
    {
        int u = q.top().u; q.pop();
        vis[u] = 0;
        for(const int& v: g[u])
        {
            if(dis[v] > max(dis[u], a[v / m][v % m]))
            {
                dis[v] = max(dis[u], a[v / m][v % m]);
                if(!vis[v])
                {
                    vis[v] = 1;
                    q.push(qnode(dis[v], v));
                }
            }
        }
    }
}

void work()
{
    read(n), read(m);
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) read(a[i][j]);
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(a[i][j] < 0)
    {
        for(int k = 0; k < 8; ++k)
        {
            int ii = i + dx[k], jj = j + dy[k];
            if(ii < 0 || ii >= n || jj < 0 || jj >= m || a[ii][jj] >= 0) continue;
            g[id(i, j)].push_back(id(ii, jj));
        }
    }
    int x, y; read(x), read(y);
    spfa(id(x - 1, y - 1));
    ll ans = 0;
    for(int i = 0; i < n * m; ++i) ans += dis[i];
    print(-ans, '\n');
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    int T; read(T);
//    for(int ca = 1; ca <= T; ++ca)
//    {
//        work();
//    }
    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


