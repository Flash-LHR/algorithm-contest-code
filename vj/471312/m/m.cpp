#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T& x) {
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch))  {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

template <typename T>
inline void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
inline void print(T x, char ch) {
    print(x), putchar(ch);
}

typedef long long ll;

struct TA {
    const static int M = (int)1e6;
    int n; ll tree[M + 5];

    void init(int n) {
        this->n = n;
        memset(tree, 0, sizeof(ll) * (n + 1));
    }

    int lowbit(int n) {
        return n & -n;
    }

    void add(int p, int x) {
        while(p <= n) {
            tree[p] += x;
            p += lowbit(p);
        }
    }

    ll ask(int p) {
        ll s = 0;
        while(p) {
            s += tree[p];
            p -= lowbit(p);
        }
        return s;
    }

    ll ask(int l, int r) {
        return ask(r) - ask(l - 1);
    }
} tr;

void work() {
    int n, q; scan(n), scan(q);
    tr.init(n);
    for(int i = 1, a, b = 0; i <= n; ++i) {
        scan(a);
        tr.add(i, a - b);
        b = a;
    }
    for(int i = 1, op, l, r, x; i <= q; ++i) {
        scan(op);
        if(op == 1) {
            scan(l), scan(r), scan(x);
            tr.add(l, x);
            if(r + 1 <= n) tr.add(r + 1, -x);
        } else {
            scan(l);
            print(tr.ask(l), '\n');
        }
    }
}

int main() {
    work();
    return 0;
}
