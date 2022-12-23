#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
constexpr int Ma = 100;

char mz[Ma][Ma];
int n, m;
bool ck(int r, int c) {
    return r > 0 and r <= n and c > 0 and c <= m and mz[r][c] == '.';
}
int xz[] = {-1, -1, 0, 1, 1, 1, 0, -1},
    yz[] = {0, 1, 1, 1, 0, -1, -1, -1};
int v{0}, r, c, dir{0}; 

int nm(int x) {
    if (x < 0) x %= 8, x += 8;
    return x % 8;
}

bool judge(int r1, int r2, int c1, int c2) {
    if (r2 < r1) swap(r1, r2);
    if (c2 < c1) swap(c1, c2);
    int cnt{0};
    fep (i, r1, r2 + 1) fep (j, c1, c2 + 1)
        if (mz[i][j] != '.') ++cnt;
    return cnt < 2;
}

void go(char d) {
    if (d == 'L') dir = nm(dir - 1);
    if (d == 'R') dir = nm(dir + 1);
    if (d == 'U') ++v;
    if (d == 'D') v = max(v - 1, 0);
    //cerr << d << ' ' << dir << endl;
    rep (i, v) {
        int rr = r + xz[dir], cc = c + yz[dir];
        if (ck(rr, cc) and judge(r, rr, c, cc))
            r = rr, c = cc;
        else {
            cout << "Crash! " << r << ' ' << c << endl;
            v = 0;
            return ;
        }
    }
    cout << r << ' ' << c << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
//    cout << fixed << setprecision(12);
    cin >> n >> m;
    rep (i, n) cin >> (mz[i + 1] + 1);
    fep (i, 1, n + 1) fep (j, 1, m + 1)
        if (mz[i][j] == '*') r = i, c = j, mz[i][j] = '.';
    int q; cin >> q;
    string s; cin >> s;
    rap (i, s)
        go(i);

    return 0;
}
