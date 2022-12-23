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
int res[Ma], b[3], s[3];
int mi{0}, tot;
stack<pair<int, int>> k[2];

void dfs(int u, int v) {
    if (u == tot) {
        if (!cmax(mi, v)) k[1] = k[0];
        return ;
    }
    rep (i, 3) rep (j, 3) if (b[i] + b[j] >= 2 + (i == j) and b[i] and b[j]) {
        --b[i], --b[j];
        k[0].emplace(s[i], s[j]);
        dfs(u + 1, min(v, res[u] * (s[i] + s[j])));
        k[0].pop();
        ++b[i], ++b[j]; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    rep (i, 3) cin >> b[i];
    rep (i, 3) cin >> s[i];
    tot = accumulate(b, b + 3, 0) / 2;
    rep (i, tot) cin >> res[i];
    dfs(0, inf);
    cout << mi << endl;
    /*while (!k[1].empty()) k[0].emplace(k[1].top()), k[1].pop();
    while (!k[0].empty()) {
        cerr << k[0].top().first << ' ' << k[0].top().second << endl;
        k[0].pop();
    }*/
}
