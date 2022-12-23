#include <bits/stdc++.h>
using namespace std;
const int maxn=100000+50;
int n,m,ans,T;
int main()
{
    cin>>T;
    for (int oo=1; oo<=T; ++oo)
    {
        cin>>n>>m;
        ans=0;
        while (n!=1)
        {
            n=(n+m)/(m+1);
            ++ans;
        }
        cout<<ans<<endl;
    }
    return 0;
}

