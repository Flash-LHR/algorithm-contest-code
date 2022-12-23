#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define F first
#define S second
#define mkt make_tuple
#define mkp make_pair
#define eb emplace_back
#define ep emplace
#define sz(x) (int)x.size()
#define state(x) (1<<(x))
constexpr int Ma = 60, inf = 0x3f3f3f3f;
template<typename T>
bool cmin(T& a, const T& b) {return a <= b || (a = b, false);}
template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

tuple<int, int, int> res[Ma];
tuple<int, int, int> bres[Ma];
using meta = tuple<int, int, int>;

int to_id(char t) {
    switch (t) {
        case 's' : return 0;
        case 'h' : return 1;
        case 'd' : return 2;
        case 'c' : return 3;
        default : assert(false);
    }
    return 4;
}

int to_val(char t) {
    if (isdigit(t)) return t - '0';
    switch (t) {
        case 'T' : return 10;
        case 'J' : return 11;
        case 'Q' : return 12;
        case 'K' : return 13;
        case 'A' : return 14;
        default : assert(false);
    }
    return 15;
}

int f[Ma];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    rep (i, n) {
        char t[3]; cin >> t;
        res[i] = mkt(to_id(t[1]), to_val(t[0]), i);
    }
    int ans{inf};
    for (int i = 0; i < state(4); i++) {
        int t[4]; iota(t, t + 4, 0);
        do {
            int t_to[4];
            rep (j, 4) t_to[t[j]] = j;
            sort(res, res + n, [&] (const meta& a, const meta& b) {
                        if (get<0>(a) != get<0>(b)) return t_to[get<0>(a)] < t_to[get<0>(b)];
                        int id = t_to[get<0>(a)];
                        if (i & state(id)) return a > b;
                        else return a < b;
                    });
            int tot{0};
            rep (j, n) {
                int pos = lower_bound(f, f + tot, get<2>(res[j])) - f;
                f[pos] = get<2>(res[j]);
                if (pos == tot) ++tot;
            }
            cmin(ans, n - tot);
            /*if (!cmin(ans, n - tot)) {
                cerr << tot << " : "<< endl;
                rep (j, n) cerr << get<2>(res[j]) << ' ';
                cerr << endl;
            }*/
        } while (next_permutation(t, t + 4));
    }
    cout << ans << endl;
}

