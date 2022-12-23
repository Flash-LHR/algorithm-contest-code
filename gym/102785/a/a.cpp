#include <bits/stdc++.h>
using namespace std;

#define seg(x) x.begin(), x.end()
#define endl '\n'

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int bef = -1;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (b % a) return cout << "DEFECT" << endl, 0;
        if (bef == -1) bef = b / a;
        else if (bef != b / a) return cout << "DEFECT" << endl, 0;
    }
    cout << "QUALITY" << endl;
}

