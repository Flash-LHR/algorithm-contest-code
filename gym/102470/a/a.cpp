#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define seg(x) x.begin(), x.end()
#define F first
#define S second
using db = double;
const int Ma = 5e4 + 100;
const db inf = numeric_limits<db>::max(), eps = 1e-9;
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false); }
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false); }

int sign(db x) {return x < -eps ? -1 : x > eps;}
int cmp(db a, db b) {return sign(a - b);}

struct point {
    db x, y;
    void scan() {
        scanf("%lf%lf", &x, &y);
    }
    db length() const {return pow(x * x + y * y, 0.5);}
    db length2() const {return x * x + y * y;}
    point unit() const {
        return *this / length();
    }
    db dis(const point& b) const {return (*this - b).length();}
    db dis2(const point& b) const {return (*this - b).length2();}
    point operator + (const point& b) const {return {x + b.x, y + b.y};}
    point operator - (const point& b) const {return {x - b.x, y - b.y};}
    point operator * (const db& b) const {return {x * b, y * b};}
    point operator / (const db& b) const {return {x / b, y / b};}
    void print() const {printf("%.6f %.6f\n", x, y);}
};
inline db dot(const point& ab, const point& ac) {
    return ab.x * ac.x + ab.y * ac.y;
}
inline db cross(const point& ab, const point& ac) {
    return ab.x * ac.y - ab.y * ac.x;
}

struct line {
    point u, v;
    db length() const {return v.dis(u);}
    point getVec() const {return v - u;};
};

db disPtoL(const point& c, const line& a) {
    return fabs(cross(a.v - a.u, c - a.u) / a.length());
}

struct circle {
    point o; db r;
    int intersect(const line& t) const {
        return cmp(disPtoL(o, t), r);
    }
};

inline point pjPoint(point c, point a, point b) {
    return a + (b - a).unit() * dot(c - a, b - a) / (b - a).length();
}

inline vector<db> getCLInsec(circle a, const line& b) {
    int aim = a.intersect(b);
    if (aim == 1) return {};
    if (aim == 0) return {pjPoint(a.o, b.u, b.v).x};
    point t = pjPoint(a.o, b.u, b.v);
    db temp = a.o.dis(t);
    db len = a.r * a.r - temp * temp;
    len = pow(len, 0.5);
    return {(t - b.getVec().unit() * len).x, (t + b.getVec().unit() * len).x};
}

circle c[Ma];
db x; int n;
line y{{0, 0}, {1, 0}};

bool ck(db r) {
    rep (i, n) c[i].r = r;
    cerr << "r == " << r << endl;
    db l = -inf; r = inf;
    rep (i, n) {
        if (c[i].r < fabs(c[i].o.y)) return false;
        db len = pow(c[i].r * c[i].r - c[i].o.y * c[i].o.y, 0.5);
        cmax(l, c[i].o.x - len);
        cmin(r, c[i].o.x + len);
        cerr << len << ' ' << l << ' ' << r << endl;
        if (cmp(r, l) == -1) return false;
    }
    cerr << l << ' ' << r << endl;
    x = (l + r) / 2.0;
    return true;
}

/*int main() {
    while (~scanf("%d", &n) and n) {
        for (int i = 0; i < n; i++) c[i].o.scan();
        db l = 0, r = 1e9;
        while (r - l > eps) {
            db mid((l + r) / 2.0);
            if (ck(mid)) r = mid;
            else l = mid;
        }
        ck(r);
        printf("%.9lf %.9lf\n", x, r);
        //if ((db)clock() / CLOCKS_PER_SEC > 1.8) break;
    }

    return 0;
}*/

point p[Ma];

db cal(db x) {
    db ans = 0;
    point t{x, 0};
    rep (i, n) cmax(ans, p[i].dis2(t));
    return ans;
}

int main() {
    while (~scanf("%d", &n) and n) {
        rep (i, n) p[i].scan();
        db l = -2e5, r = 2e5;
        while (r - l > eps) {
            db lm = l + (r - l) / 3.0, rm = (l + r) / 2.0;
            if (cal(lm) > cal(rm)) l = lm;
            else r = rm;
        }
        printf("%.9f %.9f\n", r, sqrt(cal(r)));
    }
}
