#include <bits/stdc++.h>
using namespace std;

typedef  long long ll;
const int Ma = 1e6, inf = 0x3f3f3f3f;
typedef pair<int, int> pa;
int t[Ma], x[Ma], ct[Ma];
int L[Ma], R[Ma];
#define F first
#define S second
#define rep(i, x) for (int i=0; i<(x);++i)
int cnt;

int gid(int tt) {
    return lower_bound(x, x +cnt, tt)  - x;
}

int main() {
    int n; scanf("%d", &n);
    cnt = 0;
    rep (i, n) scanf("%d%d", L + i, R + i), x[cnt++] = R[i];
    sort(x, x + cnt);
    cnt = unique(x, x + cnt) - x;
    rep (i, n) {
        ++ct[gid(R[i])];
        t[gid(R[i])] = max(t[gid(R[i])], L[i]);
    }

    ll ans = 0, pre = 0;
    for (int i = 0; i < cnt; ++i) {
        if (pre <= t[i]) ans += (ll)t[i] * ct[i];
        else ans += pre * ct[i];
        pre = max((ll)t[i], pre);
    }
    printf("%lld\n", ans);

    return 0;
}

