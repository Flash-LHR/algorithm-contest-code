#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> next(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && a[j] != a[i]) {
            j = next[j];
        }
        if (a[j] == a[i]) {
            j++;
        }
        next[i + 1] = j;
    }
    
    std::vector<int> f(n + 1);
    for (int i = n - 1, j = 0; i >= 0; i--) {
        while (j > 0 && a[j] != a[i]) {
            j = next[j];
        }
        if (a[j] == a[i]) {
            j++;
        }
        f[j]++;
    }
    
    for (int i = n; i; i--) {
        f[next[i]] += f[i];
    }
    
    for (int i = 1; i <= n; i++) {
        std::cout << f[i] << " \n"[i == n];
    }
    
    return 0;
}
