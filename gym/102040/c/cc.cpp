#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

const int Ma = 1e6 + 100, mod = 1e7 + 7;
using ll=long long;
using db=double;
#define endl '\n'

ll cal(ll x) {
    return (x + 1) * (x + 2) / 2;
}

bool is[Ma]; int prim[Ma], cnt;

int main() {
    is[1] = is[0] = true;
    for (int i = 2; i < Ma; i++) {
        if (!is[i]) prim[cnt++] = i;
        for (int j = 0; j < cnt and prim[j] * i < Ma; j++) {
            is[prim[j] * i] = true;
            if (i % prim[j] == 0) break;
        }
    }
    //cerr << cnt << endl;
    int n;
    while (cin >> n, n) {
        ll ans{1};
        for (int i = 0; i < cnt and prim[i] <= n; i++) {
            int t = n, c{0};
            while (t) c += (t /= prim[i]);
            ans *= cal(c) % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
}
