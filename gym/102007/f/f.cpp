#include <bits/stdc++.h>
using namespace std;

constexpr int Ma = 1e6 + 100, inf = 0x3f3f3f3f;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define F first
#define S second
#define endl '\n'
using ll = long long;
using db = double;
constexpr db eps = 1e-9;
#define ep emplace_back
template<typename T>
bool cmin(T &a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T &a, const T& b) {return a >= b || (a = b, false);}

#define int ll

pair<ll, ll> res[Ma];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m; 
    rep (i, n)
        cin >> res[i].F >> res[i].S;
    int l = 0, r = 2 * inf;
    auto ck = [&] (int x) {
        ll money = 0;
        rep (i, n) if (res[i].F * x > res[i].S) {
            money += res[i].F * x - res[i].S;
            if (money >= m) return true;
        }
        return false;
    };
    while (r - l > 1) {
        int mid(l + (r - l) / 2);
        if (ck(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}

