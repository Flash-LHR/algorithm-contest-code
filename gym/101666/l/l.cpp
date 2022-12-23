#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using db = long double;
using ll = long long;
using str = string;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
#define mkp make_pair
#define F first
#define S second
#define seg(x) x.begin(), x.end()
#define ep emplace_back
constexpr db pi = acos(-1.0), eps = 1e-9;
constexpr int Ma = 1e5 + 100, inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;
template <typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template <typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

db f[Ma];
map<str, int> id;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int n; cin >> n;
    id["pink"] = 0;
    f[0] = log2(1.0);
    rep (i, n) {
        str t, s; cin >> t >> s;
        db p; cin >> p;
        if (!id.count(s))
            continue;
        if (!id.count(t)) {
            int who = id.size();  id[t] = who;
            f[who] = f[id[s]] + log2(p);
        } else cmax(f[id[t]], f[id[s]] + log2(p));
    }
    if (id.count("blue"))
        cout << min((db)10.0, pow((db)2.0, f[id["blue"]])) << endl;
    else cout << "0.0" << endl;
}
