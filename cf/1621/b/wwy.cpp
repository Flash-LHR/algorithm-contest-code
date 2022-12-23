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

void work() {
    ll n, l, r, c, mn, mx, mx2, c1, c2, c3, i;
    bool f;
    cin >> n;
    mx = mx2 = -inf;
    mn = inf + 1;
    c1 = c2 = c3 = inf + 1;
    for(i = 1; i <= n; ++i) {
        cin >> l >> r >> c;
        if(r - l + 1 > mx2) mx2 = r - l + 1, c3 = c;
        else if(r - l + 1 == mx2) c3 = min(c3, c);

        if(l < mn) mn = l, c1 = c;
        else if(l == mn) c1 = min(c1, c);
        
        if(r > mx) mx = r, c2 = c;
        else if(r == mx) c2 = min(c2, c);

        if(mx2 == mx - mn + 1 && c3 < c1 + c2) cout << c3 << "\n";
        else cout << c1 + c2 << "\n";
    }
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
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}

