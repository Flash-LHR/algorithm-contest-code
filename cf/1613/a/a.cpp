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
    ll x1, p1, x2, p2; scan(x1), scan(p1), scan(x2), scan(p2);
    auto cal = [](ll x) {
        int c = 0;
        while(x) {
            ++c;
            x /= 10;
        }
        return c;
    };
    ll c1 = cal(x1), c2 = cal(x2);
    if(c1 + p1 < c2 + p2) puts("<");
    else if(c1 + p1 > c2 + p2) puts(">");
    else {
        while(p1 > p2 && c1 < c2) x1 *= 10, --p1, ++c1;
        while(p1 < p2 && c1 > c2) x2 *= 10, --p2, ++c2;
        if(x1 > x2) puts(">");
        else if(x1 < x2) puts("<");
        else puts("=");
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
    //work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}

