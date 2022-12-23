//Work by: Chelsea
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define inf 0x3f3f3f3f
#define mod 998244353
#define sd(n) scanf("%d",&n)
#define sdd(n,m) scanf("%d %d",&n,&m)
#define m_p(a,b) make_pair(a, b)
#define mem(a,b) memset((a),(b),sizeof(a))
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef pair <int,int> pii;

#define MAX 300000 + 50
int n, m, k, op;
int x, y, z;
ll a, b, c;
string s, t;
int tr[MAX];

void work(){
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> tr[i];
    int l = 1, r = 1;
    vector<pii>v;
    int maxn = 0;
    for(int i = 2; i <= n; ++i){
        if(tr[i] >= tr[i - 1]){
            r = i;
        }
        else{
            v.push_back(m_p(l, r));
            l = r = i;
        }
        maxn = max(maxn, tr[r] - tr[l]);
    }
    v.push_back(m_p(l, r));
    for(auto [l, r] : v){
        if(tr[r] - tr[l] == maxn)cout << l << ' ' << r << ' ';
    }
    cout << endl;
}


int main(){
    io;
    int tt;cin>>tt;
    for(int _t = 1; _t <= tt; ++_t){
    //printf("Case #%d: ", _t);
    work();
    }
    return 0;
}


