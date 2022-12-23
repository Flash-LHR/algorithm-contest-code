#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
#define io ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
#define itt set<node>::iterator
#define pii pair<int,int>

const int inf = 0x3f3f3f3f;
const int maxn = 5e5 + 5;
int t, n, x, h;
int sum[maxn];
int dp[maxn];
vector<int> vt;
struct node
{
    int l, r;
    int dp, dp1, dp2;

    int mid()
    {
        return (l + r) >> 1;
    }

    void print()
    {
        cout << l << ' ' << r << ' ' << dp << ' ' << dp1 << ' ' << dp2 << '\n';
    }
} tree[maxn<<2];

void pushup(node &p, node &le, node &ri)
{
    p.l = le.l;
    p.r = ri.r;
    p.dp = max(le.dp, ri.dp);
    p.dp1 = max(le.dp1, ri.dp1);
    p.dp2 = max(le.dp2, ri.dp2);
}

void pushup(int p)
{
    pushup(tree[p], tree[p<<1], tree[p<<1|1]);
}

void build(int p, int l, int r)
{
    tree[p].l = l;
    tree[p].r = r;

    if(l == r)
    {
        tree[p].dp = tree[p].dp1 = tree[p].dp2 = -inf;
        return ;
    }

    int mid = tree[p].mid();
    build(p<<1, l, mid);
    build(p<<1|1, mid + 1, r);
    pushup(p);
}

void updata(int p, int pos, int dp, int id)
{
    if(tree[p].l == tree[p].r)
    {
        tree[p].dp = max(tree[p].dp, dp);
        tree[p].dp1 = max(tree[p].dp1, dp - id);
        tree[p].dp2 = max(tree[p].dp2, dp + id);
        return ;
    }

    int mid = tree[p].mid();
    if(pos <= mid) updata(p<<1, pos, dp, id);
    else updata(p<<1|1, pos, dp, id);
    pushup(p);
}

node query(int p, int l, int r)
{
    if(l > r) return {-inf, -inf, -inf, -inf};
    if(l <= tree[p].l && tree[p].r <= r) return tree[p];

    int mid = tree[p].mid();
    if(mid >= r) return query(p<<1, l, r);
    else if(mid < l) return query(p<<1|1, l, r);
    else
    {
        node le = query(p<<1, l, r);
        node ri = query(p<<1|1, l, r);
        node res;
        pushup(res, le, ri);
        return res;
    }
}

void work()
{
    vt.clear();
    cin >> n >> h;
    for(int i = 1; i <= n; ++i)
    {
        cin >> x;
        sum[i] = sum[i - 1] + x;
        vt.push_back(sum[i]);
        dp[i] = 0;
    }
    vt.push_back(0);

    sort(vt.begin(), vt.end());
    vt.erase(unique(vt.begin(), vt.end()), vt.end());

    build(1, 1, vt.size());

    node pp;
    int mx1, mx2, mx3, pos;
    pos = lower_bound(vt.begin(), vt.end(), 0) - vt.begin() + 1;
    updata(1, pos, 0, 0);
    for(int i = 1; i <= n; ++i)
    {
        pos = lower_bound(vt.begin(), vt.end(), sum[i]) - vt.begin() + 1;
        mx1 = query(1, 1, pos - 1).dp1;
        mx2 = query(1, pos, pos).dp;
        mx3 = query(1, pos + 1, vt.size()).dp2;
        dp[i] = max(mx1 + i, max(mx2, mx3 - i));
        updata(1, pos, dp[i], i);
    }

    cout << dp[n] << ' ' << (dp[n] >= h) << '\n';
}

signed main()
{
    io;
    cin >> t;
    while(t--) work();
    return 0;
}
