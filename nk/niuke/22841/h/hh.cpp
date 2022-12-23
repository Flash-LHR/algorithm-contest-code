#include <bits/stdc++.h>
using namespace std;
   
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define endl '\n'
constexpr int Ma = 1e5;

int k;

int cal(int n, int dn, int m, int dm, int t) {
    if (n <= 0) return 1;
    n += dn;
    if (n <= 0) return 1;
    if (m <= 0) return 0;
    m += dm;
    if (m <= 0) return 0;
    int x = 0;
    fep (i, -1, 2) fep (j, -1, 2) if (i != 0 and j != 0)
        x |= !cal(n - t, i * k, m - t, j * k, t + 1);
    return x;
}

void solve() {
    int n; cin >> n >> k;
    cout << cal(n, n, 1) << endl;
}

int main() {
    cout << boolalpha;
    int t = 1;
    cin >> t;
    while (t--) solve();
}

