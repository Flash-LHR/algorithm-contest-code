#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
string s;
int n,x,s1,s2;
int f = 0;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(cin>>n && n)
    {
        if(f) cout<<endl;
        f = 1;
        s1 = s2 = 0;
        for(int i = 1;i <= n; ++i)
        {
            cin>>s>>x;
            if(s[0] == 'D')
                cout<<"DROP 2 "<<x<<endl,s2 += x;
            else
            {
                if(s1) 
                {
                    cout<<"TAKE 1 "<<min(x,s1)<<endl;
                    if(s1 >= x) 
                    {
                        s1 -= x;
         
                        continue;
                    }
                    else x -= s1,s1 = 0;
                }
                if(x)
                {
                    cout<<"MOVE 2->1 "<<s2<<endl;
                    s1 += s2; s2 = 0;
                    cout<<"TAKE 1 "<<x<<endl;
                    s1 -= x;
                }
            }
        }
    }
    return 0;
}
