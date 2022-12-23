#include <bits/stdc++.h>
#define debug(x) //cerr<<#x<<"="<<x<<endl
#define ll long long
#define int long long
using namespace std;

const int N = 5e5+10;
struct edge{
  int to,val;
}E[N<<2];
vector<int> G[N];

ll ans;
int ecnt = 1;
int dfn[N], low[N], tot;
int siz[N];
bool br[N<<2];

void dfs(int u, int fa){
  dfn[u] = low[u] = ++ tot;
  siz[u] = 0;
  for(int p : G[u]){
    int v = E[p].to;
    if(!dfn[v]){
      dfs(v,u);
      siz[u] += siz[v]+1;
      low[u] = min(low[u], low[v]);
      if(low[v] > dfn[u]){
        if((siz[v]&1)){
          br[p] = br[p^1] = true; // bridge can be deleted
        }
      }
    }
    else if(v!=fa){
      if(dfn[v]>dfn[u]){
        siz[u]+=1;
      }
      low[u] = min(low[u], dfn[v]);
    }
  }
  
  debug(u);
  debug(siz[u]);
}


signed main(){
  int n,m;
  scanf("%lld%lld",&n,&m);
  ans = 0;
  for(int i=1, x, y, w; i<=m; i++){
    scanf("%lld%lld%lld",&x,&y,&w);
    E[++ecnt] = edge{y,w};
    G[x].push_back(ecnt);
    E[++ecnt] = edge{x,w};
    G[y].push_back(ecnt);
    ans += w;
  }

  if(m&1){
    dfs(1,0);
    int res = INT_MAX;
    for(int i=2;i<=ecnt;i++){
      if(br[i]==0){
        res = min(res, E[i].val);
      }
    }
    ans -= res;
  }
  printf("%lld\n",ans);
}
