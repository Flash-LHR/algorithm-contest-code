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

int l[M + 5], r[M + 5], c[M + 5];

int cal(int L, int R) {
    return L == R ? c[L] : c[L] + c[R];
}

void work() {
   int n; scan(n);
   for(int i = 1; i <= n; ++i) scan(l[i]), scan(r[i]), scan(c[i]);
   int L = 1, R = 1;
   print(cal(L, R), '\n');
   for(int i = 2; i <= n; ++i) {
       int a[2] = {L, i}, b[2] = {R, i}, d[2] = {L, R};
       for(int j = 0; j < 2; ++j) {
           for(int k = 0; k < 2; ++k) {
               if((l[a[j]] <= l[d[0]] && r[b[k]] >= r[d[1]] && (l[a[j]] != l[d[0]] || r[b[k]] != r[d[1]])) ||
                  (l[a[j]] == l[d[0]] && r[b[k]] == r[d[1]] && cal(a[j], b[k]) < cal(d[0], d[1])))
                   d[0] = a[j], d[1] = b[k];
           }
       }
       L = d[0], R = d[1];
       print(cal(L, R), '\n');
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

