#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T& x)
{
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
    x *= f;
}

template <typename T>
void print(T x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch)
{
    print(x), putchar(ch);
}

typedef double db;
typedef long long ll;

namespace Geo {
    typedef double db;
    const db eps = 1e-9, PI = acos(-1), inf = numeric_limits<db>::max();
    inline int sign(db a) {return a < -eps ? -1 : a > eps;}
    inline int cmp(db a, db b) {return sign(a - b);}
    inline bool inmid(db k, db a, db b) {return sign(a - k) * sign(b - k) <= 0;}
    struct Point {
        db x, y;
        Point(db _x, db _y): x(_x), y(_y){}
        Point() = default;
        Point operator+(const Point& b) const {return Point(x + b.x, y + b.y);}
        Point operator-(const Point& b) const {return Point(x - b.x, y - b.y);}
        Point operator*(const db& b) const {return Point(x * b, y * b);}
        Point operator/(const db& b) const {return Point(x / b, y / b);}
        bool operator==(const Point& b) const {return !cmp(x, b.x) && !cmp(y, b.y);}
        bool operator!=(const Point& b) const {return !(*this == b);}
        bool operator<(const Point& b) const {
            int c = cmp(x, b.x);
            if(c) return c == -1;
            return cmp(y, b.y) == -1;
        }
        bool operator>(const Point& b) const {return b < *this;}
        Point right(const db& len) {return Point(x + len, y);}
        Point up(const db& len) {return Point(x, y + len);}
        db length() const {return hypot(x, y);}
        db length2() const {return x * x +  y * y;}
        Point unit() const {return *this / this->length();}
        void print() const {printf("%.11f %.11f\n", x, y);}
        void scan() const {scanf("%lf %lf", &x, &y);}
        db dis(Point b) const {return (*this - b).length();}
        db dis2(Point b) const {return (*this - b).length2();}
        Point rotate(db ac) const {return Point(x * cos(ac) - y * sin(ac), y * cos(ac) + x * sin(ac));}
        Point rotate90() const {return Point(-y, x);}
        db dot(Point o) const {return x * o.x + y * o.y;}
        db det(Point o) const {return x * o.y - y * o.x;}
    };
    typedef Point Vector;
    typedef vector<Point> Polygon;
    struct Line {
        Point u, v;
        Line(const Point& _a, const Point& _b): u(_a), v(_b){}
        Line() = default;
        Vector getVec() const {return v - u;}
        Line go(Vector t) {return Line(u + t, v + t);}
        bool isPoint() const {return u == v;}
        db length() const {return u.dis(v);}
        db length2() const {return u.dis2(v);}
        void print() const {u.print(), v.print();}
        void scan() {u.scan(), v.scan();}
    };
    inline db dot(Point ab, Point ac) { //点积
        return ab.x * ac.x + ab.y * ac.y;
    } //|ab|*|ac|*cosa
    inline int dotOp(Point c, Point a = {0, 0}, Point b = {0, 1e5}) {
        return sign(dot(b - a, c - a));
    } //+: 1,4  -: 2,3
    inline db cross(Point ab, Point ac) { //叉积
        return ab.x * ac.y - ab.y * ac.x;
    } //|ab|*|ac|*sina
    inline int crossOp(Point c, Point a = {0, 0}, Point b = {0, 1e5}) {
        return sign(cross(b - a, c - a));
    } //+: 1,2  -: 3,4
    inline int Op(Point c, Point a = {0, 0}, Point b = {0, 1e5}) { //相对象限
        int lr = dotOp(c, a, b), ud = crossOp(c, a, b);
        if(!lr || !ud) return 0;
        return lr + ud == 2 ? 1 : (lr + ud == -2 ? 3 : (lr == -1 ? 2 : 4));
    }
    inline int Quadrant(const Point& a) { //象限
        int x = cmp(a.x, 0), y = cmp(a.y, 0);
        if(x > 0 && y > 0) return 1;
        if(x < 0 && y > 0) return 2;
        if(x < 0 && y < 0) return 3;
        if(x > 0 && y < 0) return 4;
        return 0;
    }
    bool parallel(const Line& a, const Line& b) { //直线平行
        return sign(cross(a.getVec(), b.getVec())) == 0;
    }
    bool sameDir(const Line& a, const Line& b) { //直线同向
        return parallel(a, b) && sign(dot(a.getVec(), b.getVec())) == 1;
    }
    bool vertical(const Line& a, const Line& b) { // 直线垂直
        return sign(dot(a.getVec(), b.getVec())) == 0;
    }
//    bool compairAng(const Point& a, const Point& b) {
//    }
//    bool operator<(const Line& a, const Line& b) {
//    }
    inline db disPtoL(Point c, Line a) { //点到直线距离
        return fabs(cross(a.getVec(), c - a.u)) / a.length();
    }
    inline Point nearestPoint(Point c, Line ab) { //点到线段的最近点
        db t = dot(c - ab.u, ab.getVec()) / ab.length2();
        if(0 <= t && t <= 1) return ab.u + ab.getVec() * t;
        return c.dis(ab.u) > c.dis(ab.v) ? ab.v : ab.u;
    }
    inline db disPtol(Point c, Line a) { //点到线段距离
        return c.dis(nearestPoint(c, a));
    }
    inline Point pjPoint(Point c, Point a, Point b) { //投影点
        return a + (b - a).unit() * dot(c - a, b - a) / (b - a).length();
    }
    inline Point symPoint(Point c, Point a, Point b) { //对称点
        return pjPoint(c, a, b) * 2 - c;
    }
    inline Point getInsec(Point a, Point b, Point c, Point d) { //获取交点
        db w1 = cross(a - c, d - c), w2 = cross(d - c, b - c);
        return (a * w2 + b * w1) / (w1 + w2);
    }
    inline Point getInsec(Line a, Line b) { //直线交点
        return getInsec(a.u, a.v, b.u, b.v);
    }
    inline bool inseg(Point c, Point a, Point b) { //点在线段上
        if(c == a || c == b) return 1;
        return sign(cross(b - a, c - a)) == 0 && sign(dot(a - c, b - c)) == -1;
    }
    inline bool inseg(Point c, Line ab) { //点在线段上
        return inseg(c, ab.u, ab.v);
    }
    inline bool intersect(db l1, db r1, db l2, db r2) { //排斥实验 检查线段对角线矩形是否相交
        if(l1 > r1) swap(l1, r1);
        if(l2 > r2) swap(l2, r2);
        return cmp(r2, l1) != -1 && cmp(r1, l2) != -1;
    }
    inline int spanLine(Point a, Point b, Point c, Point d) { //线段ab跨立线段cd 跨立试验 <0成功 =0在直线上 >0失败
        return sign(cross(a - c, d - c)) * sign(cross(b - c, d - c));
    }
    inline int spanLine(Line a, Line b) { //线段a跨立线段b 跨立试验 <0成功 =0在直线上 >0失败
        return spanLine(a.u, a.v, b.u, b.v);
    }
    inline bool checkSSsp(Point a, Point b, Point c, Point d) { //线段严格相交
        return spanLine(a, b, c, d) < 0 && spanLine(c, d, a, b) < 0;
    }
    inline bool checkSS(Point a, Point b, Point c, Point d) { //线段非严格相交
        return intersect(a.x, b.x, c.x, d.x) && intersect(a.y, b.y, c.y, d.y)
            && spanLine(a, b, c, d) <= 0 && spanLine(c, d, a, b) <= 0;
    }
    inline bool checkSS(Line a, Line b, bool Notsp = true) {
        if(Notsp) return checkSS(a.u, a.v, b.u, b.v);
        else      return checkSSsp(a.u, a.v, b.u, b.v);
    }
    inline db disltol(Line a, Line b) { //线段到线段距离
        if(checkSS(a, b, 1)) return 0;
        return min(min(disPtol(a.u, b), disPtol(a.v, b)),
                   min(disPtol(b.u, a), disPtol(b.v, a)));
    }
    inline bool cmpAtan(Point a, Point b) { //极角排序
        if(cmp(atan2(a.y, a.x), atan2(b.y, b.x)) != 0) return atan2(a.y, a.x) < atan2(b.y, b.x);
        return a.x < b.x;
    }
    inline void sortACW(Polygon& v) { //逆时针排序
        Point g(0, 0);
        int n = v.size();
        for(int i = 0; i < n; ++i) g.x += v[i].x, g.y += v[i].y;
        g.x /= n, g.y /= n;
        sort(v.begin(), v.end(), [&](Point& a, Point& b) {return sign(cross(a - g, b - g)) == 1;});
    }
    inline db area(const Polygon& v) { //多边形面积 需要逆时针排序
        db ans = 0;
        int len = v.size();
        if(len < 3) return 0;
        for(int i = 0; i < len; ++i) ans += cross(v[i], v[(i + 1) % len]);
        return ans / 2;
    }
    inline bool isConvex(const Polygon& v) { //判断凸多边形 需要逆时针排序
        int n = v.size();
        if(n < 3) return 0;
        for(int i = 0; i < n; ++i) {
            if(cross(v[(i + 1) % n] - v[i], v[(i + 2) % n] - v[(i + 1) % n]) < 0) return 0;
        }
        return 1;
    }
    inline int contain(const Polygon& v, Point q) { //点和多边形位置关系 内部1 外部-1 多边形上0
        int n = v.size();
        int res = -1;
        for(int i = 0; i < n; ++i) {
            Vector a = v[i] - q, b = v[(i + 1) % n] - q;
            if(cmp(a.y, b.y) == 1) swap(a, b);
            if(sign(a.y) != 1 && sign(b.y) == 1 && sign(cross(a, b)) == 1) res = -res;
            if(sign(cross(a, b)) == 0 && sign(dot(a, b)) != 1) return 0;
        }
        return res;
    }
    inline Polygon ConvexHull(Polygon A, int flag = 1) { //凸包 不严格0 严格1
        int n = A.size();
        if(n <= 2) return A;
        Polygon ans(n * 2);
        int now = -1;
        sort(A.begin(), A.end());
        for(int i = 0; i < n; ans[++now] = A[i++])
            while(now > 0 && crossOp(A[i], ans[now - 1], ans[now]) < flag) --now;
        for(int i = n - 2, pre = now; i >= 0; ans[++now] = A[i--])
            while(now > pre && crossOp(A[i], ans[now - 1], ans[now]) < flag) --now;
        ans.resize(now);
        return ans;
    }
    inline db convexDimater(Polygon v) { //凸包直径
        int now = 0, n = v.size();
        db ans = 0;
        for(int i = 0; i < n; ++i) {
            now = max(now, i);
            while(1) {
                db k1 = v[i].dis(v[now % n]), k2 = v[i].dis(v[(now + 1) % n]);
                ans = max(ans, max(k1, k2));
                if(cmp(k2, k1) == 1) ++now;
                else                 break;
            }
        }
        return ans;
    }
    inline Polygon convexCut(Polygon v, Line a) { //凸包v被直线a分割成的逆时针凸包
        int n = v.size();
        Polygon ans;
        for(int i = 0; i < n; ++i) {
            int k1 = crossOp(v[i], a.u, a.v), k2 = crossOp(v[(i + 1) % n], a.u, a.v);
            if(k1 >= 0) ans.emplace_back(v[i]);
            if(k1 * k2 < 0) ans.emplace_back(getInsec(a, Line(v[i], v[(i + 1) % n])));
        }
        return ans;
    }
    db NPPD(int l, int r, const vector<Point>& v, vector<int>& tmp) {
        if(l == r) return inf;
        if(l + 1 == r) return v[l].dis(v[r]);
        int mid = (l + r) >> 1;
        db d = min(NPPD(l, mid, v, tmp), NPPD(mid + 1, r, v, tmp));
        int p = 0;
        for(int i = l; i <= r; ++i) if(fabs(v[mid].x - v[i].x) < d) tmp[p++] = i;
        sort(tmp.begin(), tmp.begin() + p, [&](int& a, int& b){return cmp(v[a].y, v[b].y) == -1;});
        for(int i = 0; i < p; ++i) {
            for(int j = i + 1; j < p && v[tmp[j]].y - v[tmp[i]].y < d; ++j) {
                d = min(d, v[tmp[j]].dis(v[tmp[i]]));
            }
        }
        return d;
    }
    db nearestPPDis(vector<Point> v) {//平面最近点对
        sort(v.begin(), v.end());
        int n = v.size();
        vector<int> tmp(n);
        return NPPD(0, n - 1, v, tmp);
    }
    struct Circle {
        Point o;
        db r;
        void scan() {
            o.scan();
            scanf("%lf", &r);
        }
        Circle(Point _o, db _r): o(_o), r(_r){}
        Circle() = default;
        bool operator==(const Circle b) const {
            return o == b.o && cmp(r, b.r) == 0;
        }
        db area() {return PI * r * r;}
        int contain(Point t) { //1圆外 0圆上 -1圆内
            return cmp(o.dis(t), r);
        }
        bool intersect(Circle b) {//两圆是否相交
            return cmp(o.dis(o), r + b.r) != 1
                && cmp(o.dis(o), fabs(r - b.r)) != -1;
        }
        int posRela(Circle b) {//0外离 1外切 2相交 3内切 4内含
            db d = o.dis(b.o);
            if(cmp(d, r + b.r) == 1) return 0;
            if(cmp(d, r + b.r) == 0) return 1;
            if(cmp(d, r + b.r) == -1 && cmp(d, fabs(r - b.r)) == 1) return 2;
            if(cmp(d, fabs(r - b.r)) == 0) return 3;
            if(cmp(d, fabs(r - b.r)) == -1) return 4;
            assert(0);
        }
        int intersect(Line t) { //-1相交 0相切 1相离
            return cmp(disPtoL(o, t), r);
        }
        int intersect_seg(Line t) {
            Point k = nearestPoint(o, t);
            return cmp(o.dis(k), r);
        }
    };
}

typedef Geo::Point point;
typedef Geo::Line line;
typedef Geo::Polygon polygon;
typedef Geo::Circle circle;
function<int(db)> sign = Geo::sign;
function<int(db, db)> cmp = Geo::cmp;

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n;
line l[M + 5];
int fa[M + 5];

int tofind(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = tofind(fa[x]);
}

void Union(int a, int b)
{
    a = tofind(a), b = tofind(b);
    if(a != b) fa[a] = b;
}

void work()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) l[i].scan(), fa[i] = i;
    int C = 0, I = 0, E = n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            if(checkSS(l[i], l[j]))
            {
                Union(i, j);
                ++I;
            }
        }
    }
    for(int i = 1; i <= n; ++i) if(fa[i] == i) ++C;
    printf("%d\n", C + I - E);
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    int T; read(T);
//    for(int ca = 1; ca <= T; ++ca)
//    {
//        work();
//    }
    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


