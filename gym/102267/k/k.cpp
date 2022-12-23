#include <bits/stdc++.h>
using namespace std;

const int Ma = 1e6 + 100;

int a[Ma];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long ans{0};
    for (int i = 1; i < (1 << n); i++) {
        int me{0};
        for (int j = 0; j < n; j++) if (i & (1 << j)) me |= a[j];
        ans += me;
    }
    cout << ans << endl;
}

