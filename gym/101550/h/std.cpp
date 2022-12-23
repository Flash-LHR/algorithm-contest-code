#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int maxn = 5e5 + 100;
vector<int> G[maxn];
map<int, int> M;
long long m, N, Max, ans;
int vis[maxn], v[maxn];
void dfs(int x){
    if(vis[x]) return;
    vis[x] = 1;
    m += G[x].size(); N++; Max = max(Max, (long long)v[x]);
    ans += (G[x].size()-1)*v[x];
    for(auto to : G[x]) dfs(to);
}
int n, x, y, tot;
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &x, &y);
        if(!M[x]){
            M[x] = ++tot;
            v[tot] = x;
        }
        if(!M[y]){
            M[y] = ++tot;
            v[tot] = y;
        }
        G[M[x]].push_back(M[y]);
        G[M[y]].push_back(M[x]);
    }
    memset(vis, 0,   sizeof(vis));
    for(int i = 1; i <= tot; i++){
        if(!vis[i]) {
            N = 0;
            m = 0;
            Max = 0;
            dfs(i);
            if(m/2 == N-1) ans += Max;
        }
    }
    cout<<ans<<endl;
    return 0;
}
