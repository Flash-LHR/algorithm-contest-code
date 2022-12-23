#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define F first
#define S second
#define mkt make_tuple
#define mkp make_pair
#define eb emplace_back
#define ep emplace
#define sz(x) (int)x.size()
#define state(x) (1<<(x))
#define endl '\n'
constexpr int Ma = 60, inf = 0x3f3f3f3f;
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

int lim(int level) {
    if (level > 20) return 2;
    if (level > 15) return 3;
    if (level > 10) return 4;
    return 5;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int rank{25}, star{0}, seq{0};
    string s; cin >> s;
    rap (i, s) {
        if (rank == 0) break;
        if (i == 'W') {
            ++star;
            ++seq;
            if (seq >= 3 and rank >= 6) ++star;
            if (star > lim(rank)) star -= lim(rank), --rank;
        } else {
            if (1 <= rank and rank <= 20) --star;
            if (star < 0 and rank < 20) ++rank, star = lim(rank) - 1;
            if (rank == 20 and star < 0) star = 0;
            seq = 0;
        }
        //cerr << i << endl;
        //cerr << rank << ' ' << star << ' ' << seq << ' ' << lim(rank)<< endl;
    }
    if (rank) cout << rank << endl;
    else cout << "Legend" << endl;
}

