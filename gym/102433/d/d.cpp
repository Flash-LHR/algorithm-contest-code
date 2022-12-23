#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using db = double;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define ep emplace
#define eb emplace_back
#define mkp make_pair
#define mkt make_tuple

constexpr int Ma = 2e5 + 100;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a, b, cnt{0};
    cin >> a >> b;
    while (a != b) {
        if (a < b) cnt += b - a, a = b;
        else if (a & 1) {
            ++a, ++cnt;
        } else {
            /*if (a / 2 >= b)*/ ++cnt, a /= 2;
            //else ++a, ++cnt;
        }
    }
    cout << cnt << endl;
}
