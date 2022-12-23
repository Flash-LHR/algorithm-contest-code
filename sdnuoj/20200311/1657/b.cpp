#include<iostream>
using namespace std;
typedef long long ll;
ll a[100006],s[100006];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n,q,i,j;
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	s[0]=a[0];
	for(i=1;i<n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	for(j=1;j<=q;j++)
	{
		ll p;
		cin>>p;
		if(j==q)
		{
			cout<<s[p-1];
		}
		else
		{
			cout<<s[p-1]<<endl;
		}
	}
	return 0;
 } 
