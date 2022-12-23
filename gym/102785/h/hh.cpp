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
constexpr int Ma = 50;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int k; cin >> k;
    if (n < 4 or n == 6) return cout << "0" << endl, 0;
    cout << k << endl;
    rep (i, k) {
        int t; cin >> t;
        if (k == 4) cout << "2020"[t];
        else if (k == 5) cout << "21200"[t];
        else {
            if (t == 0) cout << n - 7 + 3;
            else if (t < 3) cout << 3 - t;
            else if (t == n - 4) cout << 1;
            else cout << 0;
        }
        cout << " \n"[i == k - 1];
    }
}

