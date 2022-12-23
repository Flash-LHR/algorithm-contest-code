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
    const static int M = (int)1<<12;
    int n, m; ll tree[M + 5][M + 5];

    void init(int n, int m) {
        this->n = n, this->m = m;
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) tree[i][j] = 0;
        }
    }

    int lowbit(int n) {
        return n & -n;
    }

    void add(int x, int y, ll k) {
        while(x <= n) {
            int yy = y;
            while(yy <= m) {
                tree[x][yy] += k;
                yy += lowbit(yy);
            }
            x += lowbit(x);
        }
    }

    ll ask(int x, int y) {
        ll s = 0;
        while(x) {
            int yy = y;
            while(yy) {
                s += tree[x][yy];
                yy -= lowbit(yy);
            }
            x -= lowbit(x);
        }
        return s;
    }

    ll ask(int a, int b, int c, int d) {
        return ask(c, d) - ask(c, b - 1) - ask(a - 1, d) + ask(a - 1, b - 1);
    }
} tr;

void work() {
    int n, m; cin >> n >> m;
    tr.init(n, m);
    int op, x, y, k, a, b, c, d;
    while(cin >> op) {
        if(op == 1) {
            cin >> x >> y >> k;
            tr.add(x, y, k);
        } else {
            cin >> a >> b >> c >> d;
            cout << tr.ask(a, b, c, d) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    work();
    return 0;
}
