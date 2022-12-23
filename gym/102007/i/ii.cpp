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

struct DIJ
{
    const static int M = (int)1e5;
    const static int N = (int)2e5;
    const static int O = (int)10;
    const ll inf = 0x3f3f3f3f3f3f3f3f;

    int n, cnt, head[M + 5];
    struct enode
    {
        int v, w, nx;
    } Edge[N * 2 + 5];

    ll dis[O + 1][M + 5];
    bool vis[M + 5];

    void init(int n)
    {
        cnt = 0, this->n = n;
        for(int i = 1; i <= n; ++i)
        {
            head[i] = -1;
        }
    }

    void add(int u, int v, int w)
    {
        Edge[cnt].v = v;
        Edge[cnt].w = w;
        Edge[cnt].nx = head[u];
        head[u] = cnt++;
    }

    struct qnode
    {
        ll dis; int u;
        qnode(ll _dis, int _u): dis(_dis), u(_u){}
        bool operator<(const qnode& b) const
        {
            return dis > b.dis;
        }
    };

    priority_queue<qnode> q;

    void dijkstra(int s, int id)
    {
        for(int i = 1; i <= n; ++i) dis[id][i] = inf, vis[i] = 0;
        dis[id][s] = 0;
        q.push(qnode(dis[id][s], s));
        while(!q.empty())
        {
            int u = q.top().u; q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(int i = head[u]; ~i; i = Edge[i].nx)
            {
                int v = Edge[i].v;
                if(dis[id][v] > dis[id][u] + Edge[i].w)
                {
                    dis[id][v] = dis[id][u] + Edge[i].w;
                    q.push(qnode(dis[id][v], v));
                }
            }
        }
    }
} g;

struct DINIC
{
    const static int M = (int)1024 + 100;
    const static int N = (int)10240 + 100;
    const ll inf = 0x3f3f3f3f3f3f3f3f;

    int n, m, S, T, cnt;
    int head[M + 5];

    struct node
    {
        int v, nx; ll w;
    }Edge[N * 2 + 5];

    int d[M + 5];
    int cur[M + 5];
    int q[M + 5], l, r;

    void init()
    {
        cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            head[i] = -1;
        }
    }

    void add(int u, int v, ll w)
    {
        Edge[cnt].v = v;
        Edge[cnt].w = w;
        Edge[cnt].nx = head[u];
        head[u] = cnt++;
    }

    bool bfs()
    {
        l = 1, r = 0;
        for(int i = 1; i <= n; ++i) d[i] = -1;
        q[++r] = S, d[S] = 0, cur[S] = head[S];
        while(l <= r)
        {
            int u = q[l++];
            if(u == T) return 1;
            for(int i = head[u]; ~i; i = Edge[i].nx)
            {
                int v = Edge[i].v;
                if(d[v] == -1 && Edge[i].w)
                {
                    d[v] = d[u] + 1;
                    cur[v] = head[v];
                    q[++r] = v;
                }
            }
        }
        return 0;
    }

    ll dfs(int u, ll limit)
    {
        if(u == T) return limit;
        ll flow = 0;
        for(int i = cur[u]; ~i && flow < limit; i = Edge[i].nx)
        {
            cur[u] = i;
            int v = Edge[i].v;
            if(d[v] == d[u] + 1 && Edge[i].w)
            {
                ll t = dfs(v, min(Edge[i].w, limit - flow));
                if(!t) d[v] = -1;
                Edge[i].w -= t, Edge[i^1].w += t, flow += t;
            }
        }
        return flow;
    }

    ll Dinic()
    {
        ll r = 0, flow;
        while(bfs()) while(flow = dfs(S, inf)) r += flow;
        return r;
    }
} din;

const int M = (int)1e5;
const int N = (int)1e1;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, m, s;
int p[M + 5]; ll sump;
int c[N + 5];
ll sp[1<<N];

bool check(ll mid)
{
    memset(sp, 0, sizeof(sp));
    for(int i = 1; i <= n; ++i)
    {
        int state = 0;
        for(int j = 1; j <= s; ++j)
        {
            if(g.dis[j][i] <= mid) state |= (1<<j-1);
        }
        sp[state] += p[i];
    }
    din.n = (1<<s) + s + 2, din.S = din.n - 1, din.T = din.n, din.init();
    for(int i = 0; i < (1<<s); ++i) din.add(din.S, i + 1, sp[i]), din.add(i + 1, din.S, 0);
    for(int i = 1; i <= s; ++i) din.add((1<<s) + i, din.T, c[i]), din.add(din.T, (1<<s) + i, 0);
    for(int i = 0; i < (1<<s); ++i)
    {
        for(int j = 1; j <= s; ++j) if((i>>(j-1)&1)) din.add(i + 1, (1<<s) + j, c[j]), din.add((1<<s) + j, i + 1, 0);
    }
    return din.Dinic() == sump;
}

vector<ll> dv;

void work()
{
    read(n), read(m), read(s);
    g.init(n); sump = 0;
    for(int i = 1; i <= n; ++i) read(p[i]), sump += p[i];
    for(int i = 1, u, v, w; i <= m; ++i)
    {
        read(u), read(v), read(w);
        g.add(u, v, w), g.add(v, u, w);
    }
    for(int i = 1, pos; i <= s; ++i)
    {
        read(pos), read(c[i]);
        g.dijkstra(pos, i);
    }
    for(int i = 1; i <= s; ++i) for(int j = 1; j <= n; ++j) dv.push_back(g.dis[i][j]);
    sort(dv.begin(), dv.end()); dv.erase(unique(dv.begin(), dv.end()), dv.end());
    int l = 0, r = dv.size() - 1, mid;
    while(l < r)
    {
        mid = (l + r) >> 1;
        if(check(dv[mid])) r = mid;
        else l = mid + 1;
    }
    print(dv[r], '\n');
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


