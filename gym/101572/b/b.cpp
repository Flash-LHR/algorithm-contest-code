#include <bits/stdc++.h>
using namespace std;

using db = double;
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
constexpr int Ma = 600;
constexpr db dinf = numeric_limits<db>::max();
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}

struct Node {
    string name;
    db a, b;
    bool operator < (const Node& B) {
        return b < B.b;
    }
} nd[Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << fixed << setprecision(12);
    int n; cin >> n;
    rep (i, n) cin >> nd[i].name >> nd[i].a >> nd[i].b;
    sort(nd, nd + n);
    db ans{dinf}; int who = -1;
    rep (i, n) {
        int cur = 0; db now{nd[i].a};
        for (int j = 0; cur < 3; j++) if (j != i) {
            now += nd[j].b;
            ++cur;
        }
        if (!cmin(ans, now)) who = i;
    }
    cout << ans << endl;
    cout << nd[who].name << endl;
    int cur{0};
    rep (i, n) if (i != who) {
        cout << nd[i].name << endl;
        if (++cur == 3) break;
    }
}
