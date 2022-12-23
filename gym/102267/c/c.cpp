#include <bits/stdc++.h>
using namespace std;

const int Ma = 1e7 + 100;

int main() {
    int s, x; cin >> s >> x;
    int cnt{0};
    while (s) ++cnt, s /= x;
    cout << cnt << endl;
}

