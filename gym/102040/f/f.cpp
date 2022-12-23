#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define endl '\n'
#define ep emplace_back
#define F first
#define S second
const int Ma = 1e4 + 100;
using ll = long long;
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

vector<int> g[Ma];
int fa[Ma], dep[Ma], siz[Ma], son[Ma];
int top[Ma], dfn[Ma], rnk[Ma], cnt;

void dfs(int u) {
    son[u] = -1;
    siz[u] = 1;
    rap (i, g[u]) if (!dep[i]) {
        dep[i] = dep[u] + 1;
        fa[i] = u;
        dfs(i);
        siz[u] += siz[i];
        if (son[u] == -1 or siz[i] > siz[son[u]]) son[u] = i;
    }
}

void dfs(int u, int f) {
    top[u] = f;
    dfn[u] = ++cnt;
    rnk[cnt] = u;
    if (!~son[u]) return ;
    dfs(son[u], f);
    for (const auto& i : g[u])
        if (i != son[u] and i != fa[u]) dfs(i, i);
}

struct SegTree {
    int mx[Ma * 4], siz[Ma * 4], lazy[Ma * 4];
#define lc (o<<1) 
#define rc (o<<1|1)
#define mi mid((l+r)>>1)
    void build(int o, int l, int r) {
        lazy[o] = 0;
        if (l == r) return mx[o] = 0, siz[o] = 1, void();
        int mi;
        build(lc, l, mid); build(rc, mid + 1, r);
        pull(o);
    }
    void pull(int o) {
        mx[o] = max(mx[lc], mx[rc]);
        siz[o] = 0;
        if (mx[o] == mx[lc]) siz[o] += siz[lc];
        if (mx[o] == mx[rc]) siz[o] += siz[rc];
    }
    void modify(int o, int l, int r, int L, int R, int val) {
        if (r < L or R < l) return ;
        if (L <= l and r <= R) {
            mx[o] += val; lazy[o] += val;
            return ;
        }
        push(o);
        int mi;
        modify(lc, l, mid, L, R, val); modify(rc, mid + 1, r, L, R, val);
        pull(o);
    }
    void push(int o) {
        if (lazy[o]) {
            lazy[lc] += lazy[o];
            lazy[rc] += lazy[o];
            mx[lc] += lazy[o];
            mx[rc] += lazy[o];
            lazy[o] = 0;
        }
    }
} sg;

int n;

void modify(int u, int v, int val) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) {
            sg.modify(1, 1, n, dfn[top[u]], dfn[u], val);
            u = fa[top[u]];
        } else {
            sg.modify(1, 1, n, dfn[top[v]], dfn[v], val);
            v = fa[top[v]];
        }
    }
    if (dep[u] < dep[v]) swap(u, v);
    sg.modify(1, 1, n, dfn[v], dfn[u], val);
}

void solve() {
    cin >> n;
    rep (i, n) g[i].clear();
    rep (i, n - 1) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].ep(v), g[v].ep(u);
    }
    memset(dep, 0, sizeof dep);
    dep[0] = 1;
    cnt = 0;
    dfs(0); dfs(0, 0);
    sg.build(1, 1, n);
    int q; cin >> q;
    while (q--) {
        int k; cin >> k;
        vector<pair<int, int>> qs(k);
        rap (i, qs) cin >> i.F >> i.S, --i.F, --i.S;
        rap (i, qs) modify(i.F, i.S, 1);
        if (sg.mx[1] == k) cout << sg.siz[1] << endl;
        else cout << "0" << endl;
        rap (i, qs) modify(i.F, i.S, -1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    rep (qq, t) {
        cout << "Case " << qq + 1 << ":\n";
        solve();
    }
}
