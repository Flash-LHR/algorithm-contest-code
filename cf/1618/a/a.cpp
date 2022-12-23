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

int a[M + 5];
int b[M + 5];
int c[M + 5];

void work() {
    for(int i = 1; i <= 7; ++i) scan(b[i]);
    a[1] = b[1];
    auto check = [&](int p) {
        a[2] = b[p];
        a[3] = b[7] - a[1] - a[2];
        for(int i = 1; i <= 7; ++i) {
            c[i] = 0;
            for(int j = 1; j <= 3; ++j) if(i>>(j-1)&1) c[i] += a[j];
        }
        sort(c + 1, c + 8);
        for(int i = 1; i <= 7; ++i) if(c[i] != b[i]) return 0;
        return 1;
    };
    for(int i = 2; i <= 7; ++i) {
        if(check(i)) {
            printf("%d %d %d\n", a[1], a[2], a[3]);
            return;
        }
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

