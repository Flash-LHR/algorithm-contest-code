#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using db = double;
using ull = uint64_t;;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define F first
#define S second
#define mkt make_tuple
#define mkp make_pair
#define eb emplace_back
#define ep emplace
#define sz(x) (int)x.size()
#define state(x) (1<<(x))
#define endl '\n'
constexpr int Ma = 2e6 + 100, inf = 0x3f3f3f3f, Mx = 1e4 + 100;
constexpr db eps = 1e-9;
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

struct SegTree {
    ll mx[Ma * 2];
    SegTree() {memset(mx, -1, sizeof mx);}
    ll querry(int o, int l, int r, int L, int R) {
        if (r < L or R < l) return -1;
        if (L <= l and r <= R) return mx[o];
        int mid{(l + r) >> 1};
        return max(querry(o << 1, l, mid, L, R),
                   querry(o << 1 | 1, mid + 1, r, L, R));
    }
    void modify(int o, int l, int r, int pos, ll val) {
        if (l == r) {
            assert(l == pos);
            cmax(mx[o], val);
            return ;
        }
        int mid((l + r) >> 1);
        if (pos <= mid)
            modify(o << 1, l, mid, pos, val);
        else modify(o << 1 | 1, mid + 1, r, pos, val);
        push(o);
    }
    void push(int o) {
        mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
    }
} sg;

int x[Ma], len;
pair<int, int> v[Ma];

int gid(int t) {
    return lower_bound(x, x + len, t) - x;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    cout << fixed << setprecision(12);
    int n; cin >> n;
    rep (i, n) cin >> v[i].F >> v[i].S, x[len++] = v[i].F, x[len++] = v[i].S;
    sort(x, x + len);
    x[len++] = inf;
    len = unique(x, x + len) - x;
    sg.modify(1, 0, len - 1, len - 1, 0);
    rep (i, n) {
        auto [a, b] = v[i];
        ll rc[2]{-1, -1};
        {
            ll pre = sg.querry(1, 0, len - 1, gid(b) + 1, len - 1);
            //cerr << pre << endl;
            if (pre != -1) rc[0] = pre + a;
        }
        {
            swap(a, b);
            ll pre = sg.querry(1, 0, len - 1, gid(b) + 1, len - 1);
            if (pre != -1) rc[1] = pre + a;
            swap(a, b);
        }
        if (rc[0] != -1) sg.modify(1, 0, len - 1, gid(b), rc[0]);
        if (rc[1] != -1) sg.modify(1, 0, len - 1, gid(a), rc[1]);
    }
    cout << sg.mx[1] << endl;
}

