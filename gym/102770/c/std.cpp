#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5+5;
const ll inf=1e15;
char p[1005][1005];
int d;
struct node{
   node* chil[30];
   ll val;
   node(){
        for(int i = 0;i < 30;i ++)
            chil[i] = NULL;
    }
};
node* root=new node();
void insert(char st[],ll val){
	int len=strlen(st);
	node* rt=root;
	for(int i=0;i<len;i++){
		if(rt->chil[st[i]-'a']==NULL){
			node* tm=new node();
			rt->chil[st[i]-'a']=tm;
			rt=tm;
		}
		else rt=rt->chil[st[i]-'a'];
	}
	rt->val=val;
}
ll getval(char st[]){
	node* rt=root;
	for(int i=0;i<strlen(st);i++){
		if(rt->chil[st[i]-'a']==NULL){
			return 0;
		}
		rt=rt->chil[st[i]-'a'];
	}
	return rt->val;
}
int main(){
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		root=new node();
		ll ans=0,f=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		    scanf("%s",p[i]);
		char str[10005];
		for(int i=1,x;i<=m;i++){
			scanf("%s%d",str,&x);
			insert(str,x);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				d=0;
				while(p[i][j]!='#'&&j<n)str[d]=p[i][j],d++,j++;
				if(d==0)continue;
				str[d]='\0';
				ll val=getval(str);
				if(val==0)f=1;
				else ans+=val;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				d=0;
				while(p[j][i]!='#'&&j<n)str[d]=p[j][i],d++,j++;
				if(d==0)continue;
				str[d]='\0';
				ll val=getval(str);
				if(val==0)f=1;
				else ans+=val;
			}
		}
		if(f)printf("-1\n");
		else printf("%lld\n",ans);
	}
}


