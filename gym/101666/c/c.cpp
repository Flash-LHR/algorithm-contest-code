#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = double;
using ll = long long;
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

ll a[Ma];

int main() {
    int n; scanf("%d", &n);
    rep (i, n) cin >> a[i];
    gp_hash_table<ll, null_type> g, s[2];
    int cur = 0;
    rep (i, n) {
        s[cur ^= 1].clear();
        rap (j, s[cur ^ 1]) s[cur].insert(__gcd(j, a[i])),
                            g.insert(__gcd(j, a[i]));
        s[cur].insert(a[i]);
        g.insert(a[i]);
    }
    printf("%lu\n", g.size());
}
