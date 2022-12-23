#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=505;
struct Node 
{
	int id,w;
	bool operator < (const Node &b) const { return w<b.w; }
}a[N];
int ew[N][N],f[N][N],pw[N];
signed main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].w;
		a[i].id=i; pw[i]=a[i].w;
	}
	sort(a+1,a+1+n);
	memset(f,0x3f,sizeof(f));
	memset(ew,0x3f,sizeof(ew));
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		ew[u][v]=ew[v][u]=min(ew[u][v],w); // 最小化边权
		f[u][v]=f[v][u]=min(f[u][v],ew[u][v]*max(pw[u],pw[v])); 
        // max(pw[u],pw[v])，初始状态下取两端点的大的那端
	}
    //Floyd
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(ew[i][j]>max(ew[i][a[k].id],ew[a[k].id][j]))  
				{ // 当出现最大边权小于当前的时，更新最大边权及f[i][j]
					ew[i][j]=max(ew[i][a[k].id],ew[a[k].id][j]);
					f[i][j]=f[j][i]=min(f[i][j],ew[i][j]*max({pw[i],pw[j],a[k].w}));
                    // 就是这里的a[k].w，一定要小的在前面，才不会影响过程当中的状态
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j) { cout<<"0 "; continue; }
			if(ew[i][j]>1e18) cout<<"-1"<<' ';
			else cout<<f[i][j]<<' ';
		}
		cout<<endl;
	}
}

