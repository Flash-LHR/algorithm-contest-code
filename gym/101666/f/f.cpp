#include <bits/stdc++.h>
using namespace std;

using db = double;
using ll = long long;
constexpr db pi = acos(-1.0);
constexpr int Ma = 1e6;

int a[Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<>());
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++)
        if (i & 1) b += ::a[i];
        else a += ::a[i];
    cout << a << ' ' << b << endl;
}
