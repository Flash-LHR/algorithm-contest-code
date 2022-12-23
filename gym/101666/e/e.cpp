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

int n, b, r;
struct node
{
    int x, y;
} bp[M + 5], rp[M + 5];

db dis[M + 5][M + 5];
vector<int> g[M + 5];
bool vis[M + 5];
int ma[M + 5];

bool dfs(int u)
{
    for(const int& v: g[u])
    {
        if(!vis[v])
        {
            vis[v] = 1;
            if(!ma[v] || dfs(ma[v]))
            {
                ma[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

bool check(db mid)
{
    for(int i = 1; i <= b + r; ++i) g[i].clear();
    for(int i = 1; i <= b; ++i)
    {
        for(int j = 1; j <= r; ++j) if(dis[i][j] < mid) g[i].push_back(j + b), g[j + b].push_back(i);
    }
    int mx = 0;
    memset(ma, 0, sizeof ma);
    for(int i = 1; i <= b; ++i)
    {
        memset(vis, 0, sizeof vis);
        if(dfs(i)) ++mx;
    }
    return b + r - mx >= n;    
}

db getDis(int i, int j)
{
    db dx = bp[i].x - rp[j].x, dy = bp[i].y - rp[j].y;
    return sqrt(dx * dx + dy * dy);
}

void work()
{
    read(n), read(b), read(r);
    for(int i = 1; i <= b; ++i) read(bp[i].x), read(bp[i].y);
    for(int i = 1; i <= r; ++i) read(rp[i].x), read(rp[i].y);
    for(int i = 1; i <= b; ++i)
    {
        for(int j = 1; j <= r; ++j) dis[i][j] = getDis(i, j);
    }
    db l = 0.0, r = 1e6, mid;
    for(int i = 0; i < 100; ++i)
    {
        mid = (l + r) / 2.0;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.12f\n", r);
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


