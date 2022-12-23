#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int sz = 1e5 + 7, mod = 1e9 + 7;

ll dp[sz][2];
vector<int> g[sz];

ll dfs(int u, int f) {
    ll& w = dp[u][f];
    if(w >= 0) return w;
    int z = g[u].size();
    vector<ll> val(z), suff(z), pref(z);
    ll now = 1;
    for(int i = 0; i < z; ++i)
    {
        val[i]  = dfs(g[u][i], 0);
        now = now * val[i] % mod;
        pref[i] = now;
    }
    now = 1;
    for(int i = z - 1; i >= 0; --i)
    {
        now = now  * val[i] % mod;
        suff[i] = now;
    }
    if(g[u].empty()) now = 1;
    else now  = pref.back();
    if(!f) w = now;
    else if(g[u].empty()) w = 1;
    else w = 0;
    for(int i = 0; i <z; ++i)
    {
        int v = g[u][i];
        ll x = dfs(v, 1);
        if(i) x = x * pref[i - 1] % mod;
        if(i + 1<z) x = x * suff[i + 1] % mod;
        w += x;
        if(w >= mod) w -= mod;
    }
    return w;
}

int main() {
    int n; cin >> n;
    for(int i = 2; i <= n; ++i) {
        int p; scanf("%d", &p);
        g[p].push_back(i);
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(1, 0) << "\n";
}
