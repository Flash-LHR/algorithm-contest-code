#include <bits/stdc++.h>
using namespace std;
const int maxn=300000+50;
int n,m,T;
long long ans,ans1,ans2,a[maxn],b[maxn];
long long work()
{
        ans1=abs(a[1]-b[1]);
        ans2=abs(a[n]-b[n]);
        long long t1=ans1,t2=ans1,t3=ans2,t4=ans2;
        for (int i=1; i<=n; ++i)
            t1=min(t1,abs(a[1]-b[i])),
            t2=min(t2,abs(b[1]-a[i])),
            t3=min(t3,abs(a[n]-b[i])),
            t4=min(t4,abs(b[n]-a[i]));
        ans1=min(ans1,t1+t2);
        ans2=min(ans2,t3+t4);
        return ans1+ans2;
}
int main()
{
    scanf("%d",&T);
    for (int oo=1; oo<=T; ++oo)
    {
        scanf("%d",&n);
        for (int i=1; i<=n; ++i)
            scanf("%lld",&a[i]);
        for (int i=1; i<=n; ++i)
            scanf("%lld",&b[i]);
        ans=work();
        for (int i=1; i<=n/2; ++i)
            swap(b[i],b[n-i+1]);
        ans=min(ans,work());
        printf("%lld\n",ans);
    }
    return 0;
}

