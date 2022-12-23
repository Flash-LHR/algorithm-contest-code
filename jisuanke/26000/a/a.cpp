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

const int M = (int)1e7;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int prime[M + 5], cnt;
bool is_prime[M + 5];
int v[M + 5];
int pre[M + 5];

void init() {
    memset(is_prime, 1, sizeof is_prime);
    cnt = is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i <= M; ++i) {
        if(is_prime[i]) {
            prime[++cnt] = i;
            v[i] = i;
        }
        for(int j = 1; j <= cnt && i * prime[j] <= M; ++j) {
            is_prime[i * prime[j]] = 0;
            v[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
    for(int i = 2; i <= M; ++i) {
        pre[i] = pre[i - 1] + (is_prime[i] || is_prime[i / v[i]]);
    }
}

void work() {
    int l, r; scan(l), scan(r);
    print(pre[r] - pre[l - 1], '\n');
}

int main() {
    /*ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);*/
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    init();
    int T; scan(T);
    for(int ca = 1; ca <= T; ++ca) {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}

