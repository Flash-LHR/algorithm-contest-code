#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
 
 
struct node{
	int x,y,dep;
	node(int x,int y,int dep):x(x),y(y),dep(dep){}
	bool operator<(const node &a)const{
		return dep>a.dep;
	}
};
 
 
int n,m;
long long sum;
int sx,sy;
int vis[550][550];
int a[550][550];
int d[8][2]={0,1,0,-1,1,0,-1,0,1,1,1,-1,-1,1,-1,-1};
 
 
int check(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m&&!vis[x][y]&&a[x][y]<0;
}
void bfs(){
	priority_queue<node>q;
	memset(vis,0,sizeof(vis));
	q.push(node(sx,sy,a[sx][sy]));
	sum=-a[sx][sy];
	vis[sx][sy]=1;
	while(!q.empty()){
		node now=q.top();
		q.pop();
		for(int i=0;i<8;i++){
			int x=now.x+d[i][0];
			int y=now.y+d[i][1];
			if(check(x,y)){
				vis[x][y]=1;
				sum-=max(now.dep,a[x][y]);
				q.push(node(x,y,max(now.dep,a[x][y])));
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d%d",&sx,&sy);
	bfs();
	printf("%lld\n",sum);
	return 0;
}
