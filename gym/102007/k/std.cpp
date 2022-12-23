#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 100005
int root;
struct Edge{
    int to, next;
}edge[maxn*2];
int cnt, head[maxn];
int vis[maxn], leaf[maxn],cur = 0;
void add_edge(int u, int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(int now, int fa){
    int i, j, k;
    if(vis[now]==1) leaf[++cur] = now;
    for(i = head[now]; i != -1; i = edge[i].next){
        int v = edge[i].to;
        if(v==fa){
            continue;
        }
        dfs(v, now);
    }
}

int main(){
    int i, j, k, n, m;
    scanf("%d %d",&n, &root);
    memset(head, -1, sizeof(head));
    for(i = 1; i < n; i++){
        scanf("%d%d",&j, &k);
        add_edge(j,k); 
        add_edge(k,j);
        vis[j]++;
        vis[k]++;
    }
    dfs(root, -1);
    printf("%d\n",(cur+1)/2);
    /*for(i = 1; i <= cur/2; i++){
        printf("%d %d\n",leaf[i],leaf[i+cur/2]);
    }
    if(cur%2) printf("%d %d\n",leaf[cur], leaf[i]);*/
}

