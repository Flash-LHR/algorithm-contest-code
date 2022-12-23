#include <bits/stdc++.h>
using namespace std;

using db=double;
const int Ma = 1e6 + 100;
const db pi = acos(-1.0);

int main() {
    cout << fixed << setprecision(10);
    int V, S; cin >> V >> S;
    db r = (S / 2.0) / sin(pi / V);
    cout << pi * r * r << endl;
}

