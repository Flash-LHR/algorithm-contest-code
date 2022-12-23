#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define S second
#define F first
#define endl '\n'
using ll=long long;

const int ma = 1e6 + 100;

pair<int, int> res[ma];
int cnt[ma], val[ma];
int up_cnt[ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int X, Y; cin >> X >> Y;
    int n; cin >> n;
    ll up_tot{0}, down_tot{0};
    int down{0};
    rep (i, n) {
        cin >> res[i].S >> res[i].F;
        ++cnt[res[i].S]; val[res[i].S] = max(val[res[i].S], res[i].F + 1);
    }
    rep (i, X) if (cnt[i])
        down_tot += val[i] * 2, ++down;
    sort(res, res + n);
    int up{0};
    int cur = 0; ll ans = numeric_limits<ll>::max();
    for (int i = 0; i < Y; i++) {
        down_tot -= down * 2;
        up_tot += up * 2;
        //cerr << up_tot << ' ' << down_tot << ' ' << up << endl;
        while (cur < n and res[cur].F == i) {
            if (up_cnt[res[cur].S]++ == 0) ++up;
            if (--cnt[res[cur].S] == 0) --down;
            ++cur;
        }
        ans = min(ans, up_tot + down_tot);
    }
    cout << ans + X - 1 << endl;
}
