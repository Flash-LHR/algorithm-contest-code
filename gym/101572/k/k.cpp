#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = double;
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define ep emplace_back
#define mkp make_pair
#define mkt make_tuple
#define lowbit(x) ((x)&(-(x)))
#define seg(x) x.begin(), x.end()
#define rseg(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define endl '\n'
constexpr int Ma = 1e5 + 100, inf = 0x3f3f3f3f;
constexpr db dinf = numeric_limits<db>::max();
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}

vector<int> score[Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int b[3]; rep (i, 3) cin >> b[i];
    int s[3]; rep (i, 3) cin >> s[i];
    int tot = accumulate(b, b + 3, 0);
    vector<int> res(tot);
    vector<int> rc(tot / 2);
    rep (i, tot / 2) {
        cin >> res[i * 2]; res[i * 2 + 1] = res[i * 2];
        rc.ep(res[i * 2]);
    }
    sort(seg(rc)); rc.erase(unique(seg(rc)), rc.end());
    sort(rseg(res));
    int mi = inf;
    for (int i = 2; i >= 0; i--)
        while (b[i])
            score[res.back()].ep(s[i] * res.back()), res.pop_back(), --b[i];
    for (auto& i : rc)
        for (int j = 0, jj = sz(score[i]) - 1; j < jj; j++, --jj)
            cmin(mi, score[i][j] + score[i][jj]);
    cout << mi << endl;
}
