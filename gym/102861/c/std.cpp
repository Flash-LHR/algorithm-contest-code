#include<bits/stdc++.h>
#define rep(i,x,n) for(int i=x;i<=n;i++)
#define per(i,n,x) for(int i=n;i>=x;i--)
#define sz(a) int(a.size())
#define pii pair<int,int>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define se second
#define fi first
using namespace std;
const double eps=1e-8;
const int mod=1e9+7;
const int N=1e5+10;
const int inf=1e9;
const ull base=131;
map<ull,int>h1,h2;
map<ull,bool>v1,v2;
int n,m,len;
vector<ull>p,ha;
string s[N],t[N];
int a[N],b[N];
ull get(int l,int r)
{
    return (ull)ha[r]-ha[l-1]*p[r-l+1];
}
void ins(string s)
{
    len=s.size();
    p.resize(len+1);ha.resize(len+1);
    p[0]=1,ha[0]=0;
    for(int i=1;i<=len;i++)
    {
        p[i]=p[i-1]*base;
        ha[i]=ha[i-1]*base+(ull)s[i-1];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n) cin>>s[i];
    sort(s+1,s+n+1,[](string x,string y){return sz(x)<sz(y);});
    rep(i,1,m) cin>>t[i];
    sort(t+1,t+m+1,[](string x,string y){return sz(x)<sz(y);});
    rep(i,1,n){
    	ins(s[i]);
	    h1[ha[len]]=i;
	    for(int j=1;j<len;j++) if(h1.count(ha[j])){
	    	 v1[get(j+1,len)]=1;
	    }
	}
	rep(i,1,m){
		ins(t[i]);
	    h2[ha[len]]=i;
	    for(int j=1;j<len;j++) if(h2.count(get(j+1,len))){
	    	 v2[ha[j]]=1;
	    }
	}
    cout << "h1:\n";
    for(auto x: h1) cout << x.first << " " << x.second << "\n";
    cout << "h2:\n";
    for(auto x: h2) cout << x.first << " " << x.second << "\n";
    cout << "v1:\n";
    for(auto x: v1) cout << x.first << "\n";
    cout << "v2:\n";
    for(auto x: v2) cout << x.first << "\n";
    rep(i,1,n){
    	ins(s[i]);
	    for(int j=1;j<len;j++) if(h1.count(ha[j])&&v2.count(get(j+1,len))){
	    	 a[i]=a[h1[ha[j]]]=1;
	    }
    }
    rep(i,1,m){
    	ins(t[i]);
	    for(int j=1;j<len;j++) if(h2.count(get(j+1,len))&&v1.count(ha[j])){
	    	 b[i]=b[h2[get(j+1,len)]]=1;
	    }
    }
    int A=0,B=0;
    rep(i,1,n) A+=(a[i]==0);
    rep(i,1,m) B+=(b[i]==0);
    cout<<A<<' '<<B<<endl;
    return 0;
}
