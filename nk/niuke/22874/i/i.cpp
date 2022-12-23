#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lowbit(x) ((x)&(-(x)))
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
constexpr int Ma = 3e5 + 100;

struct BitTree {
     int sum[Ma];
     void add(int pos, int val=1) {
         for (; pos < Ma; pos += lowbit(pos))
             sum[pos] += val;
     }
     int pre(int pos) {
         int s{0};
         for (; pos; pos -= lowbit(pos))
             s += sum[pos];
         return s;
     }
     int range(int l, int r) {return pre(r) - pre(l - 1);}
} bt;

int a[Ma];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, q; cin >> n >> q;
    rep (i, n) cin >> a[i + 1];
    a[n + 1] = numeric_limits<int>::max();
    auto up = [&] (int pos, int val=1) {
        bt.add(pos, val * (a[pos - 1] <= a[pos]));
    };
    rep (i, n) up(i + 1);
    while (q--) {
        int op, l, r; cin >> op >> l >> r;
        if (op == 1) {
            up(l, -1);
            if (l + 1 <= n) up(l + 1, -1);
            a[l] = r;
            up(l);
            if (l + 1 <= n) up(l + 1);
        } else {
            if (l == r) {
                cout << "Yes" << endl;
            } else if (bt.range(l + 1, r) == (r - l)) {
                cout << "Yes" << endl;
            } else cout << "No" << endl;
        }
    }
}

