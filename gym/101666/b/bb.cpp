#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = double;
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
#define mkp make_pair
#define F first
#define S second
#define seg(x) x.begin(), x.end()
#define ep emplace_back
constexpr db pi = acos(-1.0), eps = 1e-8;
constexpr int Ma = 100;

int sign(db x) {return x < -eps ? -1 : x > eps;}
int cmp(db a, db b) {return sign(a - b);}

struct point {
    db x, y;
    point (db x, db y) : x(x), y(y) {}
    point() = default;
    point operator + (const point& b) const {return {x + b.x, y + b.y};}
    point operator - (const point& b) const {return {x - b.x, y - b.y};}
    point operator * (const db& b) const {return {x * b, y * b};}
    point operator / (const db& b) const {return {x / b, y / b};}
    bool operator == (const point& b) const {
        return cmp(x, b.x) == 0 and cmp(y, b.y) == 0;
    }
    bool operator != (const point& b) const {
        return not(*this == b);
    }
    bool operator < (const point& b) const {
        int c = cmp(x, b.x);
        if (c) return c == -1;
        return cmp(y, b.y) == -1;
    }
    db length() const {return hypot(x, y);}
    db length2() const {return x * x + y * y;}
    point unit() const {return *this / length();}
    db dis(const point& b) const {return (*this - b).length();}
    db dis2(const point& b) const {return (*this - b).length2();}
    point rotate90() const {return {-y, x};}
    void scan() {scanf("%lf%lf", &x, &y);}
    void print() {printf("P(%.6f, %.6f)\n", x, y);}
};

inline db dot(point ab, point ac) {
    return ab.x * ac.x + ab.y * ac.y;
}

inline db cross(point ab, point ac) {
    return ab.x * ac.y - ab.y * ac.x;
}

inline point nearestPoint(point c, point u, point v) {
    db t = dot(c - ab.u, v - u) / dot(v - u, v - u);
    if (0 <= t and t <= 1) return u + (v - u) * t;
    return c.dis(u) > c.dis(v) ? v : u;
}

inline pjPoint(point c, point a, point b) {
    return a + (b - a).unit() * dot(c - a, b - a) / (b - a).length();
}

inline db disPtoL(point c, point u, point v) {
    return fabs(cross(v - u, c - u)) / (v - u).length();
}

struct circle {
    point o; db r;
    void scan() {
        o.scan(); scanf("%lf", &r);
    }
    void print() {
        puts("Circle("); o.print(); printf("r == %.6f\n", r);
        puts(")Circle");
    }
    circle(point t, db r) : o(t), r(r) {}
    circle() = default;
    bool operator == (const circle& b) const {
        return o == b.o and cmp(r, b.r) == 0;
    }
    int contain(point t) {
        return cmp(o.dis(t), r);
    }
    int intersect(point u, point v) {
        return cmp(disPtoL(o, t), r);
    }
    int intersect_seg(point u, point v) {
        point t = nearestPoint(o, u, v);
        return cmp(o.dis(k), r);
    }
} c[Ma];

inline vector<point> getCLInsec(circle a, point u, point v) {
    int aim = a.intersect(b);
    if (aim == 1) return {};
    if (aim == 0) return {pjPoint(a.o, u, v)};
    point t = pjPoint(a.o, u, v);
    db temp = a.o.dis(t);
    db len = a.r * a.r - temp * temp;
    len = sqrt(len);
    return {t - (v - u).unit() * len,
            t + (v - u).unit() * len};
}

inline int numOfCC(circle a, circle b) {
    if (a == b) return 0;
    if (cmp(a.r, b.r) == -1) swap(a, b);
    db dis = a.o.dis(b.o);
    int t1 = cmp(dis, a.r + b.r), t2 = cmp(dis, a.r - b.r);
    if (t1 > 0) return 4;
    else if (t1 == 0) return 3;
    else if (t2 > 0) return 2;
    else if (t2 == 0) return 1;
    else return 0;
}

inline vector<point> getInsect(circle a, circle b) {
    if (cmp(a.r, b.r) == -1) swap(a, b);
    int p = numOfCC(a, b);
    if (p == 0 || p == 4) return {};
    if (p != 2) return {a.o + (b.o - a.o).unit() * a.r};
    db len = a.o.dis2(b.o),
       COSA = (len + a.r * a.r - b.r * b.r) / (2.0 * sqrt(len) * a.r);
    db dia = a.r * COSA, aid = sqrt(a.r * a.r - dia * dia);
    point k = (b.o - a.o).unit(), m = a.o + k * dia, del = k.rotate90() * aid;
    return {m - del, m + del};
}

vector<int> res[Ma];

map<point, int> id;
point p[Ma * Ma * 2];
vector<pair<int, db>> g[Ma * Ma * 2];
db dis[Ma * Ma * 2];
bool vis[Ma * Ma * 2];

db dij(int s, int t) {
    for (int i = 0; i < sz(id); i++)
        dis[i] = numeric_limits<db>::max();
    dis[s] = 0.0;
    __gnu_pbds::priority_queue<pair<db, int>> q;
    q.push(mkp(0.0, s));
    while (!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if (vis[u]) continue;
        if (u == t) return dis[t];
        vis[u] = true;
        rap (i, g[u]) if (!vis[i.F] and cmp(dis[i.F], dis[u] + i.S) == 1) {
            dis[i.F] = dis[u] + i.S;
            q.push(mkp(-dis[i.F], i.F));
        }
    }
    return numeric_limits<db>::max();
}

int main() {
    point a, b; a.scan(); b.scan();
    int n; scanf("%d", &n);
    rep (i, n) c[i].scan();
    id[a] = 0; id[b] = 1;
    p[0] = a, p[1] = b;
    rep (i, n) {
        rep (j, n) if (i != j) {
            vector<point> rc = getInsect(c[i], c[j]);
            rap (k, rc) {
                if (id.find(k) == id.end()) {
                    int who = id.size();
                    id[k] = who;
                    p[who] = k;
                }
                res[i].emplace_back(id[k]);
            }
        }
    }
    rep (i, sz(id))
        rep (j, sz(id)) if (i != j) {
            vector<pa> res;
            rep (k, n) if (c[k].intersect_seg(p[i], p[j]) != 1) {
                vector<point> rc = getCLInsec(c[k], p[i], p[j]);
                db l, r;
                ;
                res.ep();
            }
        }
    db ans = dij(0, 1);
    if (ans != numeric_limits<db>::max())
        printf("%.11f\n", ans);
    else puts("impossible");
}
