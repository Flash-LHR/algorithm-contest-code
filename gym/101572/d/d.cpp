#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = double;
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define ep emplace_back
#define mkp make_pair
#define mkt make_tuple
#define lowbit(x) ((x)&(-(x)))
#define seg(x) x.begin(), x.end()
#define rseg(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define endl '\n'
constexpr int Ma = 1e5 + 100, inf = 0x3f3f3f3f;
constexpr db dinf = numeric_limits<db>::max();
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

bitset<20> res[Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n >> k;
    rep (i, n) {
        string s; cin >> s; res[i] = bitset<20>(s);
    }
    bitset<20> ans; size_t mi{inf};
    while ((db)clock() / CLOCKS_PER_SEC < 3.8) {
        bitset<20> t(rng() % (1 << k));
        size_t now{0};
        rep (i, n)
        {
            cmax(now, k - (res[i] ^ t).count());
            if(now >= mi) break;
        }
        if (now < mi) {
            mi = now; ans = t;
        }
    }
    cout << ans.to_string().substr(20 - k) << endl;
}
