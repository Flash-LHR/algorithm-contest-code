#include <bits/stdc++.h>
using namespace std;

const int Ma = 4e6 + 100;
using ll = long long;

vector<int> res[Ma];

ll d(ll x) {return res[x].size();}

ll sndd(ll x) {
    ll ans = 0;
    for (auto& i : res[x]) ans += d(i);
    cerr << ans / 3 << ' ' << ans % 3 << endl;
    return ans;
}

int main() {
    for (int i = 1; i < Ma; i++)
        for (int j = i; j < Ma; j += i) 
            res[j].emplace_back(i);
    int n;
    while (cin >> n, n) {
        ll x = 1;
        for (int i = 2; i <= n; i++) x *= i;
        cerr << x << endl;
        cout << sndd(x) << endl;
    }
}
