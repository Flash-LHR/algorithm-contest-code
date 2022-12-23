#include <bits/stdc++.h>
using namespace std;

const int Ma = 1e7 + 100;
bool is[Ma];
int prim[Ma], cnt;

int main() {
    is[0] = is[1] = true;
    for (int i = 2; i < Ma; i++) {
        if (!is[i]) prim[cnt++] = i;
        for (int j = 0; j < cnt and prim[j] * i < Ma; j++) {
            is[prim[j] * i] = true;
            if (i % prim[j] == 0) break;
        }
    }
    int x; std::cin >> x;
    for (int i = 0; i < cnt; i++) if (x > prim[i]) {
        if (!is[x - prim[i]]) {
            cout << prim[i] << ' ' << x - prim[i] << endl;
            return 0;
        }
    } else break;
    cout << "-1" << endl;
}

