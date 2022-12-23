#include <bits/stdc++.h>
using namespace std;

const int MX = 1000100;

int is[MX], prim[MX], cnt;

#define seg(x) x.begin(), x.end()
using ll = long long;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define fep(i, a, x) for (int i = (a), i##_ = (x); i < i##_; i++)
#define rap(i, x) for (auto& i : (x))
#define ep emplace_back
#define endl '\n'
constexpr int Ma = 5e4 + 100;

template<typename T>
bool cmax(T& a, const T& b) {return a >= b || (a = b, false);}

int a[Ma], v[Ma * 7];
int go[MX], T;
int f[300][300];
int pre[Ma];
vector<int> g[Ma * 2];
int ct[MX];
int res[Ma];

void solve() {
    int n, q; scanf("%d%d", &n, &q);
    int cur{0};
    int cc{-1};
    rep (i, n) {
        scanf("%d", a + i);
        int s = 0;
        while (a[i] != 1) {
            g[go[a[i]]].ep(cur);
            v[cur++] = go[a[i]]; ++s;
            int t = go[a[i]];
            while (a[i] % t == 0) a[i] /= t;
        }
        if (s) cc = i;
        res[i] = s;
    }
    if (cur < 2) {
        while (q--) {
            int l, r; scanf("%d%d", &l, &r);
            printf("%d\n", (l <= cc and cc <= r ? cur : 0));
        }
        rep (i, cur) g[v[i]].clear();
        return ;
    }
    rep (i, n) pre[i + 1] = pre[i] + res[i];
    //cerr << cur << endl;
    T = sqrt(n * log2(cur));
    int len = (cur + T - 1) / T;
    rep (i, len) {
        memset(ct, 0, sizeof ct);
        int ci = 0;
        fep (j, i, len) {
            fep (k, j * T, min(j * T + T, cur)) {
                ++ct[v[k]];
                if (ct[v[k]] > ci) {
                    ci = ct[v[k]];
                }
            }
            f[i][j] = ci;
        }
    }
    while (q--) {
        int l, r; scanf("%d%d", &l, &r);
        //cerr << l << ' ' << r << endl;
        l = pre[l - 1]; r = pre[r] - 1;
        int mx = 0;
        if (l / T == r / T) {
            for (int i = l; i <= r; i++) {
                cmax(mx, (int)(upper_bound(seg(g[v[i]]), r) -
                        lower_bound(seg(g[v[i]]), l)));
            }
            printf("%d\n", mx);
            continue;
        }


        if (r / T - l / T > 1)
            mx = f[l / T + 1][r / T - 1];
        for (int i = l; i < min(cur, l / T * T); i++) {
            cmax(mx, (int)(upper_bound(seg(g[v[i]]), r) -
                    lower_bound(seg(g[v[i]]), l)));
        }
        for (int i = r / T * T; i <= r; i++) {
            cmax(mx, (int)(upper_bound(seg(g[v[i]]), r) -
                    lower_bound(seg(g[v[i]]), l)));
        }
        printf("%d\n", mx);
    }
    rep (i, cur) g[v[i]].clear();
}

int main() {
    is[0] = is[1] = 1;
    for (int i = 2; i < MX; i++) {
        if (!is[i]) prim[cnt++] = i, go[i] = i;
        for (int j = 0; j < cnt && prim[j] * i < MX; j++) {
            is[prim[j] * i] = 1;
            go[prim[j] * i] = prim[j];
            if (i % prim[j] == 0) break;
        }
    }
    int t; scanf("%d", &t);
    while (t--) solve();

    return 0;
}

