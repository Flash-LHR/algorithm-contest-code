#include <bits/stdc++.h>
using namespace std;
   
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define endl '\n'
constexpr int Ma = 1e5;

void solve() {
    int n, k; cin >> n >> k;
    ll x = sqrt(n * 2);
    while (x * (x + 1) <= n * 2) ++x;
    --x;
    //cerr << x << endl;
    //cerr << n - (x * (x + 1) / 2) << ' ' <<  x << ' ' << k << endl;
    if (n - (x * (x + 1) / 2) + x + 1 > k) cout << "freesin" << endl;
    else cout << "pllj" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}

