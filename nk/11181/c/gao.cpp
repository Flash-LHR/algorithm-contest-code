#include<iostream>
#include<vector>
#define ls  (u << 1)
#define rs  (u << 1|1)
#define md  (L + R >> 1)
using namespace std;
const int N=1e7+5,M=1e6+5;
int n,m,res,l,r,tr[N<<2];
char s[N],op;
inline int read()
{
    int w=0,flg=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-'){flg=-1;}ch=getchar();}
    while(ch<='9'&&ch>='0'){w=w*10+ch-'0',ch=getchar();}
    return w*flg;
}
inline int Max(int a,int b) {return a>b?a:b; }
inline void pushdown(int u,int L,int R){ 
    if(tr[u]) tr[u<<1]=tr[u<<1|1]=tr[u],tr[u]=0;
}
void modify(int u,int L,int R,int l,int r,int x){
    if(tr[u]) return ;
    if(L==l&&R==r){
        tr[u] = x;
        return ;
    }
    if(r <= md) modify(ls, L, md, l, r, x);
    else if(l > md) modify(rs, md + 1, R, l, r, x);
    else {
        modify(ls, L, md, l, md, x);
        modify(rs, md + 1, R, md + 1, r, x);
    }
}
void hhh(int u,int L,int R,int ppp){
    ppp=max(ppp,tr[u]);
    if(L==R){
        res+=Max(s[L],ppp);
        return ;
    }
    int mid=L+R>>1;
    hhh(u<<1,L,mid,ppp),hhh(u<<1|1,mid+1,R,ppp);
}
typedef pair<int,int> PII;
vector<PII> p[130];
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;++i) s[i]=getchar();
    for(int i=1;i<=m;++i){
        l=read(),r=read(),op=getchar();
        p[op].push_back({l,r});
    }
    for(int i=126;i>=33;--i)
        for(auto it:p[i])
            modify(1,1,n,it.first,it.second,i);
    hhh(1,1,n,0);
    cout<<res<<endl;
    return 0;
}
