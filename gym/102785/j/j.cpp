#include <bits/stdc++.h>
using namespace std;

#define seg(x) x.begin(), x.end()
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
#define endl '\n'
#define ep emplace
#define eb emplace_back
#define F first
#define S second

using nd = pair<char, int>;
int ck[1010][1010];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string reg; string p;
    cin >> reg >> p;
    string sq;
    vector<nd> a;
    rep (i, sz(reg)) {
        if (i + 1 != i_ and (reg[i + 1] == '+' or reg[i + 1] == '*'))
            a.eb(reg[i], reg[i + 1] == '+'), ++i;
        else 
            a.eb(reg[i], 2);
    }
    memset(ck, -1, sizeof ck);

    function<bool(int, int)> dfs = [&] (int u, int idx) {
        if (ck[u][idx] != -1) return ck[u][idx];
        if (idx == sz(p))
            while (u < sz(a) and a[u].S == 0) ++u;
        if (idx == sz(p) and u == sz(a)) return ck[u][idx] = true;
        if (idx >= sz(p) or u >= sz(a)) return ck[u][idx] = false;
        if (a[u].F != p[idx]) {
            if (a[u].S != 0) return ck[u][idx] = false;
            return ck[u][idx] = dfs(u + 1, idx);
        }
        int bidx = idx;
        if (a[u].S == 2) return ck[u][idx] = dfs(u + 1, idx + 1);
        else if (a[u].S == 1) {
            do {
                ++idx;
                if (dfs(u + 1, idx)) {
                    fep (i, bidx, idx)
                        ck[u][i] = true;
                    return ck[u][bidx] = true;
                }
            } while (idx < sz(p) and a[u].F == p[idx]);
        } else {
            if (dfs(u + 1, idx)) return ck[u][bidx] = true;
            do {
                ++idx;
                if (dfs(u + 1, idx)) {
                    fep (i, bidx, idx)
                        ck[u][i] = true;
                    return ck[u][bidx] = true;
                }
            } while (idx < sz(p) and a[u].F == p[idx]);
        }
        fep (i, bidx, idx) ck[u][i] = false;
        return ck[u][bidx] = false;
    };

    if (dfs(0, 0)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

