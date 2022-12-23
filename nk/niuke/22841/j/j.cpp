#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
   
constexpr int Ma = 1e5 + 100;
using ll = long long;
#define mkp make_pair
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define endl '\n'

int a[Ma];

void solve() {
    int n, k; cin >> n >> k;
    rep (i, n) cin >> a[i];
    int l = 0, r = n;
    auto ck = [&] (int x) {
        cc_hash_table<int, null_type> ck;
        cc_hash_table<int, int> dfn;
        set<pair<int, int>> q;
        int win{0};
        rep (i, n) {
            if (ck.find(a[i]) != ck.end()) {
                ++win; q.erase(mkp(dfn[a[i]], a[i]));
                dfn[a[i]] = i;
                q.emplace(dfn[a[i]], a[i]);
            } else {
                ck.insert(a[i]);
                dfn[a[i]] = i;
                if ((int)q.size() >= x) {
                    ck.erase(q.begin()->second);
                    q.erase(q.begin());
                }
                q.emplace(i, a[i]);
            }
            assert(ck.size() == q.size());
        }
        return win >= k;
    };
    while (r - l > 1) {
        int mid(l + ((r - l) >> 1));
        //cerr << l << ' ' << r << endl;
        if (ck(mid)) r = mid;
        else l = mid;
    }
    if (ck(r)) cout << r << endl;
    else cout << "cbddl" << endl;
}

int main() {
    int t = 1;
    while (t--) solve();
}

