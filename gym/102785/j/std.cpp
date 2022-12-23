#include <bits/stdc++.h>
using namespace std;

#define seg(x) x.begin(), x.end()
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
#define endl '\n'
#define ep emplace
#define eb emplace_back

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string reg; string p;
    cin >> reg >> p;
    if (regex_match(p, regex(reg)))
        cout << "Yes" << endl;
    else cout << "No" << endl;
}
