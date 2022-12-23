#include <bits/stdc++.h>
using namespace std;
const int maxn=1000000+50;
int n,m,e=1;
long long tot;
struct nodee
{
    int c,t;
};
deque<nodee> q;
string ch;
struct node
{
    int l,r;
    char c;
}b[maxn/10];
bool cmp(node x,node y)
{
    return x.l<y.l;
}
int main()
{
    scanf("%d%d",&n,&m);
    cin>>ch;
    for (int i=0; i<n; ++i)
        tot+=ch[i];
    for (int i=1; i<=m; ++i)
        scanf("%d%d ",&b[i].l,&b[i].r),
        b[i].c=getchar();
    sort(b+1,b+m+1,cmp);
    b[m+1].l=n+1;
    for (int i=b[1].l; i<=n; ++i)
    {
        while (i==b[e].l)
        {
            while (!q.empty() && q.back().c<=b[e].c) q.pop_back();
            q.push_back({(int)b[e].c,b[e].r}); ++e;
        }
        while (!q.empty() && q.front().t<i) q.pop_front();
        if (!q.empty()) tot+=max(0,q.front().c-ch[i-1]);
    }
    printf("%lld\n",tot);
    return 0;
}//1617
