#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T& x) {
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
    x *= f;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch) {
    print(x), putchar(ch);
}

typedef double db;
typedef long long ll;

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n;
ll a[M + 5], b[M + 5];

void work() {
    scan(n);
    for(int i = 1; i <= n; ++i) scan(b[i]);
    ll fz = accumulate(b + 1, b + n + 1, 0ll), fm = (ll)n * n * (n + 1) / 2;
    ll x = -((ll)n * n + n - 2) / 2, y = ((ll)n * n + n + 2) / 2;
    for(int i = 1, px = 1, py = n; i <= n; ++i) {
        ll cur = fz + (x - 1) * b[px] + (y - 1) * b[py];
        a[i] = cur / fm;
        if(cur % fm || !(1 <= a[i] && a[i] <= (int)1e9)) {
            puts("NO");
            return;
        }
        ((px %= n) += 1), ((py %= n) += 1);
    }
    puts("YES");
    for(int i = 1; i <= n; ++i) print(a[i], i == n ? '\n' : ' ');
}

int main() {
    /*ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);*/
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T; scan(T);
    for(int ca = 1; ca <= T; ++ca) {
        work();
    }
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}

