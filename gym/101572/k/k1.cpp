#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = double;
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
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

int res[Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int b[3]; rep (i, 3) cin >> b[i];
    int s[3]; rep (i, 3) cin >> s[i];
    vector<tuple<int, int, int>> R;
    rep (i, 3) rep (j, 3)
        R.ep(s[i] + s[j], i, j);
    //sort(seg(R));
    int tot = accumulate(b, b + 3, 0) / 2;
    rep (i, tot) cin >> res[i];
    auto ck = [&] (int X) {
        int bb[3]; memcpy(bb, b, sizeof b);
        rep (i, tot) {
            bool can{false};
            rap (j, R) {
                int val, x, y;
                tie(val, x, y) = j;
                if (bb[x] >= 1 and bb[y] >= (1 + (x == y)) and
                    val * res[i] >= X) {
                    --bb[x], --bb[y];
                    can = true;
                    break;
                }
            }
            if (not can) return false;
        }
        return true;
    };
    int mi{0};
    {
        sort(res, res + tot);
        int l = 0, r = inf;
        while (r - l > 1) {
            int mid(l + (r - l) / 2);
            if (ck(mid)) l = mid;
            else r = mid;
        }
        cmax(mi, l);
    }
    /*{
        sort(res, res + tot, greater<>());
        int l = 0, r = inf;
        while (r - l > 1) {
            int mid(l + (r - l) / 2);
            if (ck(mid)) l = mid;
            else r = mid;
        }
        cmax(mi, l);
    }*/
    cout << mi << endl;
}
