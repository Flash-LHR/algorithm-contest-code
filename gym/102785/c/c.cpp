#include <bits/stdc++.h>
using namespace std;

#define seg(x) x.begin(), x.end()
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define sz(x) (int)x.size()
#define endl '\n'
#define ep emplace
#define eb emplace_back

string ord = [] () {
    string t;
    for (char a = 'a'; a <= 'z'; ++a)
        t += toupper(a), t += a;
    return t;
}(), s;

multiset<vector<int>> fz, fm;

void gen(int l, int r, bool is_fz, bool rev) {
    int ck{0};
    for (int i = l; i < r; i++) {
        if (s[i] == '(') ++ck;
        else if (s[i] == ')') --ck;
        else if (!isalpha(s[i]) and !ck) {
            gen(l, i, is_fz, false);
            return gen(i + 1, r,
                   is_fz ^ (s[i] == (rev ? '*' : '/')),
                   s[i] == '/'), void();
        }
    }
    if (s[l] == '(') return gen(l + 1, r - 1, is_fz, false), void();
    multiset<vector<int>> &f = is_fz ? fz : fm;
    vector<int> tc;
    for (int i = l; i < r; i++)
        tc.eb(find(seg(ord), s[i]) - ord.begin());
    f.ep(tc);
}

void print(const vector<int>& rc) {
    rap (i, rc) cout << ord[i];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    gen(0, sz(s), 1, false);
    multiset<vector<int>> rfz, rfm;
    set_difference(seg(fz), seg(fm), inserter(rfz, rfz.begin()));
    set_difference(seg(fm), seg(fz), inserter(rfm, rfm.begin()));
    auto it = rfz.begin();
    rep (i, sz(rfz)) print(*(it++)), cout << "*\n"[i == sz(rfz) - 1];
    if (rfz.empty()) cout << "1" << endl; 
    it = rfm.begin();
    rep (i, sz(rfm)) print(*(it++)), cout << "*\n"[i == sz(rfm) - 1];
    if (rfm.empty()) cout << "1" << endl; 
}

