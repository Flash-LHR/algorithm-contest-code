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

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, k;
char s[25];
queue<int> q;
int vis[1<<20];

void work()
{
    read(n), read(k);
    memset(vis, -1, sizeof vis);
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        int state = 0;
        for(int j = 0; j < k; ++j) state = (state<<1) + (s[j] == '1');
        q.push(state), vis[state] = 0;
    }
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = 0; i < k; ++i)
        {
            int v = (u^(1<<i));
            if(vis[v] == -1)
            {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }
    int u = -1;
    for(int i = 0; i < (1<<k); ++i) if(u == -1 || vis[u] < vis[i]) u = i;
    for(int j = k - 1; j >= 0; --j) putchar((u>>j&1) + '0');
    putchar('\n');
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


