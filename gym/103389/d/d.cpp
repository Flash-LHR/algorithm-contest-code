#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int pre; cin >> pre;
    ll tot{0};
    for (int i = 1; i < n; i++) {
        int t; cin >> t;
        tot += max(pre, t);
        pre = t;
    }
    cout << tot << endl;

    return 0;
}
