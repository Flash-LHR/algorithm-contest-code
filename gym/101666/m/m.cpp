#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = double;
using ll = long long;
using str = string;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
#define mkp make_pair
#define F first
#define S second
#define seg(x) x.begin(), x.end()
#define ep emplace_back
constexpr db pi = acos(-1.0), eps = 1e-9;
constexpr int Ma = 1e5 + 100, inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
template <typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template <typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

int xl, xr, yl, yr;

struct point {
    int x, y;
    bool operator < (const point& b) const {
        return x != b.x ? ((x < b.x) == (xl < xr)) :
                          ((y < b.y) == (yl < yr));
    }
} p[Ma];

struct SegTree {
    int mx[Ma * 4];
    void modify(int o, int l, int r, int pos, int val) {
        if (l == r) {
            assert(l == pos); cmax(mx[o], val);
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
    int querry(int o, int l, int r, int L, int R) {
        if (r < L or R < l) return 0;
        if (L <= l and r <= R) return mx[o];
        int mid((l + r) >> 1);
        return max(querry(o << 1, l, mid, L, R),
                   querry(o << 1 | 1, mid + 1, r, L, R));
    }
} sg;

inline int sign(db x) {return x < 0 ? -1 : x > 0;}
inline bool inmid(int k, int a, int b) {return sign(a - k) * sign(b - k) <= 0;}

int yy[Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int n; cin >> n;
    cin >> xl >> yl >> xr >> yr;
    yy[0] = yr, yy[1] = yl;
    int len = 2;
    int cur = 0;
    rep (i, n) {
        cin >> p[cur].x >> p[cur].y;
        if (inmid(p[cur].x, xl, xr) and inmid(p[cur].y, yl, yr)) {
            yy[len++] = p[cur].y;
            ++cur;
        }
    }
    sort(yy, yy + len);
    len = unique(yy, yy + len) - yy;
    auto gid = [&] (int x) {
        return lower_bound(yy, yy + len, x) - yy;
    };
    sort(p, p + cur);
    int ans = 0;
    rep (i, cur) {
        int l = yl, r = p[i].y;
        if (l > r) swap(l, r);
        l = gid(l), r = gid(r);
        int now = sg.querry(1, 0, len - 1, l, r) + 1;
        //cerr << 0 << ' ' << len - 1 << ' ' << gid(p[i].y) << endl;
        sg.modify(1, 0, len - 1, gid(p[i].y), now);
        cmax(ans, now);
    }
    cout << ans << endl;
}
