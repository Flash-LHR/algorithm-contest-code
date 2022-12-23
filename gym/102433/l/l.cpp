#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using db = double;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : x)
#define ep emplace
#define F first
#define S second
#define eb emplace_back
#define mkp make_pair
#define mkt make_tuple
#define sz(x) (int)x.size()
#define endl '\n'
#define seg(x) x.begin(), x.end()

#ifdef DEBUG
void err(istream_iterator<string>) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ';
    err(++it, args...);
}
#define debug(args...) {string _s = #args; \
    replace(seg(_s), ',', ' '); \
    cerr << "DEBUG:"; \
    istringstream it(_s); \
    err(istream_iterator<string>(it), args); \
    cerr << endl; \
}
#else
#define debug(...)
#endif

constexpr int Ma = 100;

int ans[Ma], len = 50, tmp[Ma];

void add(int* b) {
    for (int i = 0; i < len; i++) {
        ans[i] += b[i];
        ans[i] %= 10;
    }
}

void cal(int* u, int n, int* v, int m) {
    memset(tmp, 0, sizeof tmp);
    memset(ans, 0, sizeof ans);
    for (int i = 0; i < m; i++) {
        rep (j, i) tmp[j] = 0;
        rep (j, n) tmp[i + j] = (u[j] * v[i]) % 10;
        add(tmp);
    }
}

int a[Ma], b[Ma], n, m;

void read(int* p, int& n) {
    string s; cin >> s;
    reverse(seg(s));
    rep (i, sz(s)) p[i] = s[i] - '0';
    n = sz(s);
}

void print(int* t) {
    int pos = len - 1;
    while (t[pos] == 0) --pos;
    while (pos >= 0) cout << t[pos--];
    cout << endl;
}

bool ck(int pos, int ct) {
    /*rep (i, ct) cerr << ans[i];
    cerr << endl;
    cerr << "show : ";
    for (int i = pos; i >= 0; i--)
        cerr << a[i];
    cerr << endl;*/
    while (pos >= 0) {
        int tot{0};
        rep (i, pos + 1)
            (tot += ans[ct - 1 - i] * ans[ct - 1 - pos + i])
                     %= 10;
        //debug(tot, pos, a[pos]);
        if (a[pos--] != tot) return false;
    }
    return true;
}

bool dfs(int pos, int res, int cnt) {
    if (res == 0) return ck(pos, cnt);
    rep (i, 10) {
        ans[cnt] = i;
        int tot = 0;
        rep (j, cnt + 1)
            (tot += (ans[j] * ans[cnt - j]) % 10) %= 10;
        if (tot == a[pos] and
            dfs(pos - 1, res - 1, cnt + 1)) return true;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    /*while (true) {
        read(a, n); read(b, m);
        cal(a, n, b, m);
        print(ans);
    }*/
    /*rep (i, 10) rep (j, 10) if (i * j != 0)
        ;*/
    read(a, n);
    if (n & 1) {
        int len = (n + 1) / 2;
        if (!dfs(n - 1, len, 0)) {
            cout << "-1" << endl;
            return 0;
        }
        rep (i, len) cout << ans[i];
        cout << endl;
    } else cout << "-1" << endl;
}
