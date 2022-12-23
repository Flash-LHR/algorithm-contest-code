#include <bits/stdc++.h>
using namespace std;

constexpr int Ma = 1e6 + 100, inf = 0x3f3f3f3f;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define F first
#define S second
#define endl '\n'
#define sz(x) (int)x.size()
using ll = long long;
using db = double;
constexpr db eps = 1e-9;
#define ep emplace_back
template<typename T>
bool cmin(T &a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T &a, const T& b) {return a >= b || (a = b, false);}

vector<int> g[Ma];
int in[Ma];
bool vis[Ma];
vector<pair<int, int>> ans;
int cp[Ma], cur;

int dfs(int u, int fa, bool rt=false) {
    vector<int> pc;
    int me{0};
    rap (i, g[u]) if (i != fa) {
        int siz = dfs(i, u);
        if (rt) pc.ep(siz);
        else me += siz;
    }
    if (rt) {
        int now = 0;
        vector<int> go[2];
        for (int i = 0; i < sz(pc); i++) {
            if (pc[i] & 1) {
                for (int j = 0; j < pc[i]; j += 2)
                    ;
            } else {
                ;
            }
        }
    }
    if (me == 0) cp[cur++] = u, me = 1;
    return me;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    rep (i, n - 1) {
        int u, v; cin >> u >> v;
        g[u].ep(v); g[v].ep(u);
        in[u]++, in[v]++;
    }
    if (n == 2) {
        cout << "1\n0 1" << endl;
    } else {
        int aim{-1};
        for (int i = 0; i < n; i++) if (in[i] > 1) aim = i;
        dfs(aim, aim, true);
        vector<int> res;
        for (int i = 0; i < n; i++) if (in[i] == 1 and !vis[i]) {
            res.ep(i);
            if (res.size() == 2) ans.ep(res[0], res[1]), res.clear();
        }
        if (res.size() == 1) {
            for (int i = 0; i < n; i++) if (in[i] == 1 and i != res[0]) {
                ans.emplace_back(res[0], i);
                break;
            }
        }
        cout << ans.size() << endl;
        rap (i, ans) cout << i.F << ' ' << i.S << endl;
    }
}

