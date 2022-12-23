#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,LL> pii;
const int N = 1e6 + 5;
const int M = 1e7 + 5;
#define rep(at,am,as) for(int at = am;at <= as;++at)
const LL Mod = 1e9 + 7;
#define INF 1e9
#define dbg(ax) cout << "now this num is " << ax << endl;
inline long long ADD(long long x,long long y) {
    if(x + y < 0) return ((x + y) % Mod + Mod) % Mod;
    return (x + y) % Mod;
}
inline long long MUL(long long x,long long y) {
    if(x * y < 0) return ((x * y) % Mod + Mod) % Mod;
    return x * y % Mod;
}
inline long long DEC(long long x,long long y) {
    if(x - y < 0) return (x - y + Mod) % Mod;
    return (x - y) % Mod;
}

int n,m,a[N],f[N][25],dep[N],lg[N],head[N],cnt = 0;
LL dp[N][2];//0 - low - up,1 - up - low
struct Node{int to,next;}e[N<<1];
void add(int u,int v)
{
    e[++cnt].to = v,e[cnt].next = head[u],head[u] = cnt;
}
vector<int> G[N];
void init() {
	for(int i = 1;i < N;++i) lg[i] = lg[i-1]+(1<<lg[i-1] == i);
}
void dfs(int u,int fa) {
    dp[u][0] = dp[fa][0],dp[u][1] = dp[fa][1];
    if(fa != 0 && a[u] > a[fa]) dp[u][0] += a[u] - a[fa];
    if(fa != 0 && a[u] < a[fa]) dp[u][1] += a[fa] - a[u];
	dep[u] = dep[fa] + 1;
	f[u][0] = fa;
	for(int i = 1;i <= lg[dep[u]];++i) f[u][i] = f[f[u][i-1]][i-1];
	for(int i = head[u];i;i = e[i].next) if(e[i].to != fa) dfs(e[i].to,u);
}
int LCA(int x,int y) {
    if(dep[x] < dep[y]) swap(x,y);
    while(dep[x] > dep[y]) {
        x = f[x][lg[dep[x]-dep[y]]-1];
    }
    if(x == y) return x;
    for(int i = lg[dep[x]];i >= 0;--i) {
        if(f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
    }
    return f[x][0];
}
LL query(int x,int y,int lca) {
    return dp[x][1] - dp[lca][1] + dp[y][0] - dp[lca][0];
}
void solve() {
    scanf("%d %d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n - 1) {
        int x,y;scanf("%d %d",&x,&y);
        add(x,y);
        add(y,x);
    } 
    dfs(1,0);
    while(m--) {
        int x,y;scanf("%d %d",&x,&y);
        int lca = LCA(x,y);
        //dbg(lca);
        printf("%lld\n",a[x] + query(x,y,lca));
    }

}   
int main() {
    init();
    // int _;
    // for(scanf("%d",&_);_;_--) {
        solve();
    //}
    //system("pause");
    return 0;
}

/*
6 10
2 3 1 1 4 6
1 2
1 3
2 4
2 5
3 6

1 6

*/
