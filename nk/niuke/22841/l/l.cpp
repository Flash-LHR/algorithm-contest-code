#include <bits/stdc++.h>
using namespace std;
   
constexpr int Ma = 1e5 + 100;
int res[Ma];
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define endl '\n'

void solve() {
    int n; cin >> n;
    rep (i, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        res[x1 + 1]++, res[x2 + 1]--;
    }
    int ans{0};
    for (int i = 1; i < Ma; i++) {
        res[i] += res[i - 1];
        if (res[i]) ++ans;
    }
    cout << ans << endl;
}

int main() {
    int t = 1;
    while (t--) solve();
}

