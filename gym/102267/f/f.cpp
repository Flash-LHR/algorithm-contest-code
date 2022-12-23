#include <bits/stdc++.h>
using namespace std;

using db=long double;
using ll=long long;
#define endl '\n'
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
const int Ma = 3000 + 100, mod = 1e9 + 7;

constexpr db eps = 1e-9, pi = acos(-1.0);

int sign(db x) {return x < -eps ? -1 : x > eps;}
int cmp(db a, db b) {return sign(a - b);}

struct point {
    db x, y, a, r;
    point(db x=0, db y=0) : x(x), y(y) {}
    point operator - (const point& b) {return {x - b.x, y - b.y};}
    point operator + (const point& b) {return {x + b.x, y + b.y};}
    point operator * (const db& b) {return {x * b, y * b};}
    point operator / (const db& b) {return {x / b, y / b};}
    void scan() {
        cin >> x >> y >> a >> r;
        a = a / 180.0 * pi;
        r = r / 180.0 * pi;
    }
    point rotate(db ac) const {
        return {x * cos(ac) - y * sin(ac), y * cos(ac) + x * sin(ac)};
    }
    point rotate90() const {
        return {-y, x};
    }
    void print() {
        cerr << "Point(" << x << ", " << y << ")" << endl;
    }
};

db cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

int in[Ma];
point p[Ma], pp[Ma];
vector<int> g[Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    rep (i, n) p[i].scan();
    rep (i, n) {
        rep (j, n) pp[j] = p[j] - p[i];
        point l = point(10, 0).rotate(p[i].a - p[i].r),
              r = point(10, 0).rotate(p[i].a + p[i].r);
        point out = point(10, 0).rotate(p[i].a).rotate90();
        rep (j, n) if (i != j) {
            if (sign(cross(l, pp[j])) != -1 and sign(cross(r, pp[j])) != 1 and
                sign(cross(out, pp[j])) != 1)
                in[j]++, g[i].emplace_back(j);
        }
    }
    vector<int> ans;
    queue<int> q;
    rep (i, n) if (in[i] == 0) q.emplace(i);
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        ans.emplace_back(t);
        rap (i, g[t]) if (--in[i] == 0)
            q.emplace(i);
    }
    if ((int)ans.size() != n)  cout << "-1" << endl;
    else rep (i, n) cout << ans[i] + 1 << " \n"[i == n - 1];
}

