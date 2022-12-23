#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<set>
using namespace std;
const int inf = (1 << 30) - 1;
const long long int INF = 1e18;
 
 
 
char s[1005];
int num[1005];
bool vis[1005][1005], tag;
int n, len;
void DFS(int nx, int remain)
{
	if (tag)return;
	if (nx == len)
	{
		if (remain == 0)
		{
			for (int i = 0; i < len; i++)printf("%d", num[i]);
			printf("\n");
			tag = true;
		}
		return;
	}
	if (s[nx] >= '0'&&s[nx] <= '9')
	{
		num[nx] = s[nx] - '0';
		int nex = (remain * 10 + num[nx]) % n;
		vis[nx + 1][nex] = true;
		DFS(nx + 1, nex);
		if (tag)return;
	}
	else
	{
		for (int i = 0; i <= 9; i++)
		{
			if (nx == 0 && i == 0)continue;
			num[nx] = i;
			int nex = (remain * 10 + num[nx]) % n;
			if (!vis[nx + 1][nex])
			{
				vis[nx + 1][nex] = true;
				DFS(nx + 1, nex);
			}
			if (tag)return;
		}
	}
}
int main()
{
	while (scanf("%s %d", s, &n) != EOF) 
	{
		tag = false;
		len = strlen(s);
		memset(vis, false, sizeof(vis));
		DFS(0, 0);
		if (!tag)printf("*\n");
	}
	getchar(); 
	getchar();
}
