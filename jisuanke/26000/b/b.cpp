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

const int M = (int)20;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, a[M + 5][M + 5];
int f[1<<M];

void work() {
    scan(n);
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) scan(a[i][j]);
    auto cal = [&](int sta, int p) {
        int s = 0;
        for(int i = 0; i < n; ++i) if(sta>>i&1) s += a[i][p];
        return s;
    };
    for(int i = 0; i < (1<<n); ++i) {
        for(int j = 0; j < n; ++j) {
            if(i>>j&1) continue;
            f[i|(1<<j)] = max(f[i|(1<<j)], f[i] + cal(i, j));
        }
    }
    print(f[(1<<n) - 1], '\n');
}

int main() {
    /*ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);*/
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T = 1; //scan(T);
    for(int ca = 1; ca <= T; ++ca) {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}

