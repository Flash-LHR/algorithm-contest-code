#include <bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define S second
#define F first
#define endl '\n'
using ll=long long;
template<typename T>
T cmax(T& a, const T& b) {return a >= b or (a = b, false);}
template<typename T>
T cmin(T& a, const T& b) {return a <= b or (a = b, false);}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const int Ma = 1e5 + 100;

struct ST {
    static constexpr int K = 25;
    int log[Ma + 1];
    int st[Ma][K + 1];
    int (*f)(int, int);
    ST(int (*f)(int, int)) : f(f) {
        log[1] = 0;
        for (int i = 2; i < Ma; i++) log[i] = log[i / 2] + 1;
    }
    void build(int* ary, int n) {
        for (int i = 0; i < n; i++) st[i][0] = ary[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = f(st[i][j - 1], st[i + (1 << (j -  1))][j - 1]);
    }
    int querry(int l, int r) {
        int j = log[r - l + 1];
        return f(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int mma(int a, int b) {return a > b ? a : b;}
int mmi(int a, int b) {return a < b ? a : b;}

ST ma(mma), mi(mmi);

int l[Ma], r[Ma];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n = 100000; cin >> n;
    rep (i, n) {
        //l[i] = 0; r[i] = rng() % 100000;
        cin >> l[i] >> r[i];
    }
    ma.build(l, n);
    mi.build(r, n);
    cout << mi.querry(2, 4) << endl;
    assert(false);
    int ans{0};
    cout << mi.querry(2, 4) << ' ' << ma.querry(2, 4) << endl;
    rep (i, n) {
        int l = 1, r = n - i + 1;
        while (r - l > 1) {
            int mid(l + (r - l) / 2);
            if (mi.querry(i, i + mid - 1) - ma.querry(i, i + mid - 1) + 1 >= mid)
                l = mid;
            else r = mid;
        }
        //cerr << i << ' ' << l << endl;
        cmax(ans, l);
    }
    assert(ans > 0 and ans <= n);
    cout << ans << endl;
}
