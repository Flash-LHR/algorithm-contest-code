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

const int M = (int)2e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n;
int p[M + 5];
char s[M + 5];
vector<int> id[2];
int q[M + 5];

void work() {
    scan(n);
    id[0].clear(), id[1].clear();
    for(int i = 1; i <= n; ++i) scan(p[i]);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; ++i) id[s[i] - '0'].push_back(i);
    sort(id[0].begin(), id[0].end(), [&](int a, int b) {
            return p[a] < p[b];
            });
    sort(id[1].begin(), id[1].end(), [&](int a, int b) {
            return p[a] < p[b];
            });
    int pid = 0;
    for(auto x: id[0]) q[x] = ++pid;
    for(auto x: id[1]) q[x] = ++pid;
    for(int i = 1; i <= n; ++i) print(q[i], i == n ? '\n' : ' ');
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

