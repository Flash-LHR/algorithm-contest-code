#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int tot{0};
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s; getline(cin, s);
        for (auto& j : s) if (j == '-') ++tot;
    }
        cout << tot << '\n';

    return 0;
}
