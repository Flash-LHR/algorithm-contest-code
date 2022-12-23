#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int n,tot;
ll sumi[maxn];
int a[maxn],root[maxn];
vector<int> nums;

struct node{
	int l,r;
	int cnt;//这个区间内数的个数
	ll sum;//这个区间内数字之和
}tree[maxn<<5];

int geiId(int x)
{
	return lower_bound(nums.begin(),nums.end(),x,greater<int>())-nums.begin();
}

void PushUp(int rt)
{
	tree[rt].cnt=tree[tree[rt].l].cnt+tree[tree[rt].r].cnt;
	tree[rt].sum=tree[tree[rt].l].sum+tree[tree[rt].r].sum;
}
//初始化数据
void init()
{
	for(int i=0;i<=tot;i++){
		tree[i]={0,0,0,0};
	}
	nums.clear();
	for(int i=0;i<=n;i++) root[i]=0;
	tot=0;
}

int Build(int l,int r)
{
	int rt=++tot;
	tree[rt].l=l;
	tree[rt].r=r;
	if(l==r) return rt;
	int mid=(l+r)>>1;
	tree[rt].l=Build(l,mid);
	tree[rt].r=Build(mid+1,r);
	return rt;
}

int Update(int p,int l,int r,int x)
{
	int rt=++tot;
	tree[rt]=tree[p];
	if(l==r){
		tree[rt].cnt++;
		tree[rt].sum+=nums[x];
		return rt;
	}
	int mid=(l+r)>>1;
	if(x<=mid) tree[rt].l=Update(tree[p].l,l,mid,x);
	else tree[rt].r=Update(tree[p].r,mid+1,r,x);
	PushUp(rt);
	return rt;
}

ll Query(int rt,int p,int l,int r,int k)
{
	//为了防止有重复数字，一定要这么处理
	if(l==r){
		return (tree[rt].sum-tree[p].sum)/(tree[rt].cnt-tree[p].cnt)*k;
	}
	int cnt=tree[tree[rt].l].cnt-tree[tree[p].l].cnt;
	int mid=(l+r)>>1;
	if(k<=cnt) return Query(tree[rt].l,tree[p].l,l,mid,k);
	else return tree[tree[rt].l].sum-tree[tree[p].l].sum+Query(tree[rt].r,tree[p].r,mid+1,r,k-cnt);
}

int main()
{
	//预处理1方加到i方的值
	for(ll i=1;i<maxn;i++) sumi[i]=i*i+sumi[i-1];
	int t;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			nums.push_back(a[i]);
		}
		//离散化处理
		sort(nums.begin(),nums.end(),greater<int>());
		nums.erase(unique(nums.begin(),nums.end()),nums.end());

		root[0]=Build(0,nums.size()-1);
		for(int i=1;i<=n;i++){
			root[i]=Update(root[i-1],0,nums.size()-1,geiId(a[i]));
		}
		
		int q;
		scanf("%d",&q);
		while(q--){
			int l,r,k;
			scanf("%d %d %d",&l,&r,&k);
			int m=r-l+1;
			printf("%lld\n",sumi[m]+Query(root[r],root[l-1],0,nums.size()-1,k));
		}
	}
	return 0;
}


