#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define seg(x) x.begin(), x.end()
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
#define endl '\n'
#define ep emplace
#define eb emplace_back
#define mkt make_tuple
#define F first
#define S second
#define state(x) (1<<(x))
constexpr int Ma = 1e6, inf = 0x3f3f3f3f, ma = 2e9;

template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

using nd = tuple<stack<int>, stack<int>, stack<int>>;

set<nd> ck;
int res[Ma];

void dfs(nd now, int st, int step=0) {
    if (ck.count(now)) return ;
    ck.ep(now);
    cmin(res[st], step);
    stack<int> val[3];
    tie(val[0], val[1], val[2]) = now;
    rep (i, 3) rep (j, 3) if (i != j and
            !val[i].empty() and (val[j].empty() or
            val[i].top() < val[j].top())) {
        int stt = st;
        if (i == 0 or j == 0)
            stt ^= state(val[i].top());
        val[j].ep(val[i].top()); val[i].pop();
        dfs(mkt(val[0], val[1], val[2]),
            stt,
            step + 1);
        val[i].ep(val[j].top()); val[j].pop();
    }
}

void solve(int n) {
    memset(res, inf, sizeof res);
    nd me;
    rep (i, n) get<0>(me).ep(n - 1 - i);
    dfs(me, (1 << n) - 1);
    rep (i, 1 << n)
        cerr << bitset<20>(i).to_string().substr(20 - n) << " == " << res[i] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    while (cin >> n) solve(n);
}

