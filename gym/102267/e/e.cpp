#include <bits/stdc++.h>
using namespace std;

using db=long double;
using ll=long long;
#define endl '\n'
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)

bool ban[13][13];

bool ck (int r, int c) {
   return r > 0 and r <= 12 and c > 0 and c <= 12 and !ban[r][c];
}

char dir[] = {'U', 'D', 'L', 'R'};
int xz[] = {-1, 1, 0, 0},
    yz[] = {0, 0, -1, 1};

string s;

struct point {
    int x, y;
    void scan() {cin >> x >> y; ban[x][y] = true;}
    bool go(int id) {
        if (ck(x + xz[id], y + yz[id])) {
            ban[x][y] = false;
            x += xz[id]; y += yz[id];
            ban[x][y] = true;
            return true;
        }
        return false;
    }
    void print() {
        cout << "P(" << x << ' ' << y << ")" << endl;
    }
    void rev() {ban[x][y] = false;}
};

void solve() {
    point a[4]; s.clear();
    rep (i, 4) a[i].scan();
    auto go = [&] (int d) {
        s += dir[d];
        bool mv = false, have{false};
        bool vis[4]{false, false, false, false};
        do {
            mv = false;
            rep (i, 4) if (!vis[i]) mv |= (vis[i] = a[i].go(d));
            have |= mv;
        } while (mv);
        return have;
    };
    bool can{false};
    do {
        can = false;
        bool c{false};
        do {
            c = false;
            c |= go(2);
            can |= c;
        } while (c);
        do {
            c = false;
            c |= go(1);
            can |= c;
        } while (c);
    } while (can);
    if (ban[12][1] and ban[12][2] and ban[11][1] and ban[11][2])
        go(0), go(0), go(2);
    else if (ban[12][1] and ban[12][2] and ban[12][3] and ban[12][4])
        go(0), go(0), go(0), go(0), go(2), go(1), go(2), go(2), go(1);
    else if (ban[11][1] and ban[12][1] and ban[12][2] and ban[12][3])
        go(0), go(0), go(0), go(0), go(2), go(3), go(1), go(2), go(2), go(2), go(1), go(1);
    else if (ban[10][1] and ban[11][1] and ban[12][1] and ban[12][2])
        go(0), go(0), go(2), go(1);
    assert(ban[9][1] and ban[10][1] and ban[11][1] and ban[12][1]);
    auto gogo = [&] (int d, int num) {
        rep (i, num) go(d);
    };
    gogo(3, 8); gogo(1, 2); gogo(0, 3); gogo(3, 2); gogo(1, 3);
    gogo(0, 1); gogo(3, 4); gogo(1, 1); gogo(2, 2); gogo(0, 5);
    cout << s.size() << endl;
    cout << s << endl;
    rep (i, 4) a[i].rev();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ban[6][6] = ban[6][7] = ban[7][6] = ban[7][7] = 
    ban[9][2] = ban[9][3] = ban[10][2] = 
    ban[9][10] = ban[9][11] = ban[10][11] = true;
    int t; cin >> t;
    while (t--) solve();
}

