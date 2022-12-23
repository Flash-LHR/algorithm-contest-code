#include <bits/stdc++.h>
using namespace std;

constexpr int Ma = 1e6 + 100, inf = 0x3f3f3f3f;
using ll = long long;
#define ep emplace_back
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}

ll f[Ma];

int main() {
    memset(f, inf, sizeof f);
    int n; scanf("%d", &n);
    for (int i = 1; i < Ma; i++)
        for (int j = i; j < Ma; j += i) {
            cmin(f[j], (ll)i + j / i);
        }
    ll ans = numeric_limits<ll>::max();
    for (int i = 1; i <= n; i++) if (n % i == 0) {
        cmin(ans, (ll)n / i * 2 + f[n / i] * i * 2);
    }
    printf("%lld\n", ans);
}

