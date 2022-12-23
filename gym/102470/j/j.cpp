#include <bits/stdc++.h>
using namespace std;

const int Ma = 1e5 + 100;
#define rep(i, x) for (int i = 0, i##_ = (x); i < i##_; i++)
#define F first
#define S second
#define mkp make_pair
pair<int, int> res[Ma];

struct ST {
    static const int K = 25;
    int log[Ma + 1];
    int st[Ma][K + 1];
    int (*f)(int, int);
    ST(int (*f)(int, int)) : f(f) {
        log[1] = 0;
        for (int i = 2; i <= Ma; i++) log[i] = log[i / 2] + 1;
    }
    void build(int* ary, int N) {
        for (int i = 0; i < N; i++) st[i][0] = ary[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= N; i++)
                st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    int querry(int l, int r) {
        int j = log[r - l + 1];
        return f(st[l][j], st[r - (1 << j) + 1][j]);
    }
};
int mx(int a, int b) {return a > b ? a : b;}
int mi(int a, int b) {return a < b ? a : b;}
ST h_st(mi), sa_st(mx);

struct SA {
    int sa[Ma], rk[Ma], c[Ma], se[Ma], sv[Ma], heigh[Ma];
    string res;
    void rsort(int* sa, int n, int m, int* x, int* y = nullptr) {
        memset(c, 0, sizeof(int) * (m + 1));
        for (int i = 0; i < n; i++) ++c[x[i]];
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--)
            y == nullptr ? sa[--c[x[i]]] = i : sa[--c[x[y[i]]]] = y[i];
    }
    bool cmp(int* ck, int w, int n, int a, int b) {
        return ck[a] == ck[b] and ck[a + w] == ck[b + w];
    }
    void build(int* r, int n, int m = 28) {
        r[n++] = 0;
        memset(c, 0, sizeof(int) * m);
        memcpy(rk, r, sizeof(int) * n);
        rsort(sa, n, m, rk);
        int *x = rk, *y = se;
        for (int w = 1, p = 1; w <= n; m = p, w <<= 1) {
            for (p = 0; p < w; p++) y[p] = n - 1 - p;
            for (int i = 0; i < n; i++)
                if (sa[i] >= w) y[p++] = sa[i] - w;
            rsort(sa, n, m, x, y);
            std::swap(x, y);
            x[sa[0]] = 0;
            p = 1;
            for (int i = 1; i < n; i++)
                x[sa[i]] = cmp(y, w, n, sa[i - 1], sa[i]) ? p - 1 : p++;
        }
        if (x != rk) swap(rk, se);
    }
    void build(char* s) {
        int cnt{0};
       int len = strlen(s);
       rep (i, len) sv[cnt++] = s[i] - 'a' + 1;
       res = s;
       build(sv, cnt);
    }
    void getH() {
        int n = res.length(), k = 0, j;
        for (int i = 0; i < n; heigh[i++] = k)
            for (k ? --k : 0, j = sa[rk[i] - 1]; sv[i + k] == sv[j + k]; ++k) ;
        int h[n];
        rep (i, n) h[i] = heigh[sa[i + 1]];
        /*cerr << "h == ";
        rep (i, n) cerr << h[i] << ' ';
        cerr << endl;*/
        h_st.build(h, n);
        sa_st.build(sa + 1, n);
    }
    pair<int, int> solve(int lim) {
        getH();
        pair<int, int> ans; int n = res.length();
        for (int i = 0; i < n - lim + 1; i++) {
            if (lim == 1) {
                if (n - sa[i + 1] > ans.F or (n - sa[i + 1] == ans.F and sa[i + 1] > ans.S))
                    ans = mkp(n - sa[i + 1], sa[i + 1]);
            } else {
                int len = h_st.querry(i + 1, i + lim - 1);
                //printf("sa = %d, sa[lim] = %d, len = %d lim = %d i + 1= %d i + lim - 1 = %d\n", sa[i+1], sa[i+lim-1], len, lim, i+1, i+lim-1);
                int id = sa_st.querry(i, i + lim - 1);
                if (len > ans.F or (len == ans.F and id > ans.S))
                    ans = mkp(len, id);
            }
        }
        return ans;
    }
} sa;

char s[Ma];

int main() {
    int m;
    while (~scanf("%d", &m) and m) {
        scanf("%s", s);
        sa.build(s);
        pair<int, int> res = sa.solve(m);
        if (res.F == 0) puts("none");
        else printf("%d %d\n", res.F, res.S);
    }

    return 0;
}
