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
typedef __int128 ll;

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int dis[10][10];
ll fac[300];
queue<ll> q;
map<ll, int> mp;

void bfs(int a) {
   while(!q.empty()) q.pop();
   mp.clear();
   ll u = a, v;
   q.push(u), mp[u] = 0;
   dis[a][a] = 0;
   while(!q.empty()) {
       u = q.front(); q.pop();
       if(mp[u] > 7) continue;
       if(1 <= u && u <= 7 && dis[a][u] == -1) dis[a][u] = mp[u];
       if(u <= 33) {
           v = fac[u];
           if(!mp.count(v)) {
               mp[v] = mp[u] + 1;
               q.push(v);
           }
       }
       v = (ll)floor(pow(u, 0.5));
       if(!mp.count(v)) {
           mp[v] = mp[u] + 1;
           q.push(v);
       }
       v = (ll)ceil(pow(u, 0.5));
       if(!mp.count(v)) {
           mp[v] = mp[u] + 1;
           q.push(v);
       }
   }
}

void init() {
    fac[0] = 1;
    for(int i = 1; i <= 33; ++i) {
        fac[i] = fac[i - 1] * i;
        //print(i, ' '), print(fac[i], '\n');
    }
    memset(dis, -1, sizeof dis);
    for(int i = 1; i <= 7; ++i) {
        bfs(i);
        /*for(int j = 1; j <= 7; ++j) printf("%d ", dis[i][j]);
        printf("\n");*/
    }
}

void work() {
    int x, y; scan(x), scan(y);
    print(dis[x][y], '\n');
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
    //work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}

