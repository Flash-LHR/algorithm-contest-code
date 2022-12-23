#include <bits/stdc++.h>
using namespace std;

constexpr int Ma = 1e4 + 10;

using ll = long long;
ll d[Ma], f[Ma];

int main() {
    for (int i = 1; i < Ma; i++) d[i] = 2 * d[i - 1] + 1;
    cout << d[Ma - 1] << endl;
}

