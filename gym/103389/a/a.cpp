#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
constexpr int Ma = 100;

int a[Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    cout << fixed << setprecision(12);
    int n, x, y; cin >> n >> x >> y;
    rep (i, n) cin >> a[i + 1];
    vector<int> go, rgo;
    int q; cin >> q;
    if (y > x) {
        for (int i = x + 1; i <= y and (int)go.size() < q; i++)
            go.emplace_back(a[i]);
        for (int i = x - 1; i > 0 and (int)rgo.size() < q; i--)
            rgo.emplace_back(a[i]);
    } else {
        for (int i = x - 1; i >= y and (int)go.size() < q; i--)
            go.emplace_back(a[i]);
        for (int i = x + 1; i <= n and (int)rgo.size() < q; i++)
            rgo.emplace_back(a[i]);
    }

    vector<int> t(q);
    for (auto& i : t) cin >> i;
    if (t == go and rgo == t) cout << "Unsure" << endl;
    else if (t == go) cout << "Right" << endl;
    else cout << "Wrong" << endl;

    return 0;
}
