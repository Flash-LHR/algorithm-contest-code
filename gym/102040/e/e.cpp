#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define endl '\n'
const int Ma = 4e6 + 100;
using ll = long long;
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}
int lim, d_lim, e_lim, dt_lim, et_lim;

void solve(int n) {
    int score = 0;
    while (n--) {
        char t; int h[2], m[2], s[2];
        scanf("%c:%d:%d:%d:%d:%d:%d\n", &t, h, m, s, h + 1, m + 1, s + 1);
        rep (i, 2) s[i] += m[i] * 60 + h[i] * 60 * 60;
        cmax(s[0], lim);
        int late = t == 'D' ? d_lim : e_lim;
        int t_lim = t == 'D' ? dt_lim : et_lim;
        if (s[0] > late or s[1] - s[0] < t_lim) ++score;
    }
    if (score > 3) cout << "Issue Show Cause Letter" << endl;
    else if (score) cout << score << " Point(s) Deducted" << endl;
    else cout << "All OK" << endl;
}

int main() {
    lim = 8 * 60 * 60 + 30 * 60;
    d_lim = 9 * 60 * 60 + 30 * 60;
    e_lim = 12 * 60 * 60 + 30 * 60;
    dt_lim = 8 * 60 * 60;
    et_lim = 9 * 60 * 60;
    int n;
    while (scanf("%d\n", &n), n) solve(n);
}
