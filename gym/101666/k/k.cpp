#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = long double;
using ll = long long;
using str = string;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
#define mkp make_pair
#define F first
#define S second
#define seg(x) x.begin(), x.end()
#define ep emplace_back
constexpr db pi = acos(-1.0), eps = 1e-9;
constexpr int Ma = 1e5 + 100, inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
template <typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template <typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

vector<int> g[Ma];
vector<int> ans;
bool vis[Ma];

int dfs(int u) {
    int cnt = 1;
    ans.ep(u);
    vis[u] = true;
    rap (i, g[u]) if (!vis[i]) cnt += dfs(i);
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int n; cin >> n;
    rep (i, n) {
        str s; cin >> s;
        rep (j, n) if (s[j] == '1')
            g[i].ep(j);
    }
    if (dfs(0) == n) {
        reverse(seg(ans));
        rep (i, sz(ans)) cout << ans[i] << " \n"[i == sz(ans) - 1];
    } else cout << "impossible" << endl;
}
