#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = double;
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define mkp make_pair
#define mkt make_tuple
#define lowbit(x) ((x)&(-(x)))
#define endl '\n'
constexpr int Ma = 1e5 + 100, inf = 0x3f3f3f3f;
constexpr db dinf = numeric_limits<db>::max();
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}

struct BitTree {
    int sum[Ma];
    void add(int pos, int val) {
        for (++pos; pos < Ma; pos += lowbit(pos))
            sum[pos] += val;
    }
    int pre(int pos) {
        int tot{0};
        for (++pos; pos; pos -= lowbit(pos))
            tot += sum[pos];
        return tot;
    }
} bt;

tree<pair<int, int>, null_type, less<>, rb_tree_tag,
    tree_order_statistics_node_update> pro[Ma];
int tt[Ma], cnt[Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //cout << fixed << setprecision(12);
    int n, m; cin >> n >> m;
    rep (i, n) bt.add(0, 1), pro[0].insert(mkp(0, n - i - 1));
    rep (i, m) {
        int t, p; cin >> t >> p;
        bt.add(cnt[t], -1);
        pro[cnt[t]].erase(mkp(-tt[t], n - t));
        cnt[t]++; tt[t] += p;
        bt.add(cnt[t], 1);
        pro[cnt[t]].insert(mkp(-tt[t], n - t));
        cout << n - bt.pre(cnt[1] - 1) - pro[cnt[1]].order_of_key(mkp(-tt[1], n - 1)) << endl;
    }
}
