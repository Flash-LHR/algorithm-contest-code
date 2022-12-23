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

int n; ll h;
ll a[M + 5];

void work() {
    scan(n), scan(h);
    for(int i = 1; i <= n; ++i) scan(a[i]);
    auto check = [&](ll mid) {
        ll s = 0;
        for(int i = 1; i <= n; ++i) {
            if(i < n) s += min(mid, a[i + 1] - a[i]);
            else s += mid;
            if(s >= h) return true;
        }
        return false;
    };
    ll l = 1, r = (ll)1e18, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    print(r, '\n');
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
    //work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}

