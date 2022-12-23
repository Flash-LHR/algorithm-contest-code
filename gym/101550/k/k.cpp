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
constexpr int Ma = 1e5 + 100, inf = 0x3f3f3f3f, Mx = 1e4 + 100;
constexpr db eps = 1e-9;
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

int sign(db x) {return x < -eps ? -1 : x > eps;}
int cmp(db a, db b) {return sign(a - b);}

struct point {
    db x, y;
    point(db x, db y) : x(x), y(y) {}
    point() = default;
    point operator + (const point& b) const {return {x + b.x, y + b.y};}
    point operator - (const point& b) const {return {x - b.x, y - b.y};}
    point operator * (const db& b) const {return {x * b, y * b};}
    point operator / (const db& b) const {return {x / b, y / b};}
    bool operator == (const point& b) const {
        return cmp(x, b.x) == 0 and cmp(y, b.y) == 0;
    }
    bool operator != (const point& b) const {return not(*this == b);}
    db length() const {return hypot(x, y);}
    db length2() const {return x * x + y * y;}
    point unit() const {return *this / length();}
    void scan() {cin >> x >> y;}
    db dis(const point& b) const {return (*this - b).length();}
};

struct line {
    point u, v;
    line(point u, point v) : u(u), v(v) {}
    line() = default;
    point getVec() const {return v - u;}
    db length() const {return v.dis(u);}
};

using polygon = vector<point>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int n; cin >> n;
    polygon a(n);
    rap (i, a) i.scan();
    int m; cin >> m;
    polygon b(m);
    rap (i, b) i.scan();
    point ca = a[0], cb = b[0];
    db ans{inf};
    for (int i = 1, j = 1; i < n and j < m;) {
        line s{ca, a[i]}, y{cb, b[j]};
        db len = min(s.length(), y.length());
        point d1 = s.getVec().unit(), d2 = y.getVec().unit();
        db l = 0, r = len;
        auto dis = [&] (db t) -> db {
            return (ca + d1 * t).dis(cb + d2 * t);
        };
        while (r - l > eps) {
            db lm(l + (r - l) / 3.0), rm = (l + r) / 2.0;
            if (dis(lm) < dis(rm)) r = rm;
            else l = lm;
        }
        cmin(ans, dis(l));
        ca = ca + d1 * len; cb = cb + d2 * len;
        if (ca == a[i]) ++i;
        if (cb == b[j]) ++j;
    }
    cout << ans << endl;
}

