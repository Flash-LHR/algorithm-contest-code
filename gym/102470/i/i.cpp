#include <bits/stdc++.h>
using namespace std;

const int Ma = 1e5 + 100;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define F first
#define S second
pair<int, int> res[Ma];

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m) and n + m) {
        rep (i, n) scanf("%*d%*d%d%d", &res[i].F, &res[i].S);
        while (m--) {
            int a, b; scanf("%d%d", &a, &b);
            int cnt{0}; 
            rep (i, n) if (res[i].F + res[i].S - 1 >= a and res[i].F <= a + b - 1) ++cnt;
            printf("%d\n", cnt);
        }
    }

    return 0;
}
