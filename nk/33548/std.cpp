#define TLE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N=1e6+5;;
char dat[N<<1];//中间用其它字符隔开之后处理出来的串 大小开两倍
char s[N];//s原串
int p[N<<1];//以第i个位置为中心 的 最大回文串半径
int cnt;
const int mod=19930726;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline void qr(){
    dat[0]='~',dat[cnt=1]='|';
    int len=strlen(s+1);
    for(int i=1;i<=len;i++){
        dat[++cnt]=s[i],dat[++cnt]='|';
    } 
}
int f[N<<1];
inline void manacher(){
    qr();
    for(int t=1,r=0,mid=0;t<=cnt;++t){
        // if(dat[t]!='|') {
        //     p[t]=0;
        //     if(p[t]+t>r) r=p[t]+t-1,mid=t;
        //     continue;
        // }
	    if(t<=r) p[t]=min(p[(mid<<1)-t],r-t+1);
        // if(p[t]==0) p[t]=1;
        // cout<<t<<" "<<p[t]<<'\n';
        // cout<<((dat[t-p[t]]-'0')^1)<<" "<<(dat[t+p[t]]-'0')<<'\n';
	    while(dat[t-p[t]]==dat[t+p[t]]&&t+p[t]<=cnt) ++p[t];
	    if(p[t]+t>r) r=p[t]+t-1,mid=t;
    }
    // cout<<cnt<<endl;
    // for(int i=0;i<=cnt;i++) cout<<dat[i]; //输出新生成的回文串
    // cout<<'\n';
    
    // for(int i=1;i<=cnt;i++) cout<<p[i]<<" "; //新生成的字符串 输出以每一个字符为中心的最大回文半径

    // ********统计回文串个数********
    // int num=0;
    // for(int i=1;i<=cnt;i++) num+=p[i]/2;
    // cout<<num<<'\n';

    //***********统计最长回文串长度 以及 最长回文串半径**************
    // int len1=0,len2=0;//len1表示最长回文串长度 len2表示最长回文串半径
    // for(int i=1;i<=cnt;i++){
    //     if(dat[i]=='|') len1=max(len1,p[i]/2*2);
    //     else len1=max(len1,p[i]/2*2-1);
    //     len2=max(len2,p[i]/2);
    // }
}
signed main(){
    TLE;
    int n,k;
    cin>>n>>k;
    cin>>s+1;
    manacher();
    int ans=1;
    // vector<int >q;
    for(int i=1;i<=cnt;i++) if(dat[i]!='|') f[p[i]/2*2-1]++;
    // if(q.size()<k) return cout<<-1<<'\n',0;
    // sort(q.begin(),q.end(),[](const int &x,int &y){
    //     return x>y;
    // });
    for(int i=n;i>=1;i--){
        if(i%2==0) continue;
        if(k>=f[i]) ans=ans*powmod(i,f[i])%mod,k-=f[i];
        else ans=ans*powmod(i,k)%mod,k=0;
        if(i>=3) f[i-2]+=f[i];
        if(k==0) break;
        // ans%=mod;
    }
    if(k) return cout<<-1<<'\n',0;
    cout<<ans<<'\n';
    return 0;
}

