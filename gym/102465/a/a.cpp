#include <bits/stdc++.h>
using namespace std;

const int ma = 1e6 + 100;
int vis[ma]; int light{0};

int main() {
    int n, k; scanf("%d%d", &n, &k);
    int mx{0};
    while (k--) {
        int t; scanf("%d", &t);
        for (int i = t; i <= n; i += t) {
            if (!vis[i]) ++light;
            else --light;
            vis[i] ^= 1;
        }
        mx = max(light, mx);
    }
    printf("%d\n", mx);
}
