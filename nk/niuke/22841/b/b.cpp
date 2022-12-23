#include <bits/stdc++.h>
using namespace std;
   
vector<int> res;

void gcd(int x, int y) {
    if (y == 0) return ;
    res.emplace_back(x / y);
    gcd(y, x % y);
}

void solve() {
    res.clear();
    int x, y; cin >> x >> y;
    gcd(x, y);
    cout << res.size() - 1 << ' ';
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << " \n"[i == (int)res.size() - 1];
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}

