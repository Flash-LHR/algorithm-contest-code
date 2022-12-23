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

typedef tuple<ll, ll, ll> T;

queue<T> q;
map<T, int> mp;

int bfs(ll a, ll b, ll c, ll n) {
    mp.clear(); while(!q.empty()) q.pop();
    T u(a, b, c), v;
    q.push(u), mp[u] = 0;
    ll vec[3];
    while(!q.empty()) {
        u = q.front(); q.pop();
        auto [a, b, c] = u;
        if(c >= n) return mp[u];
        ll aa = 2 * c - a, bb = 2 * c - b;
        vec[0] = aa, vec[1] = b, vec[2] = c; sort(vec, vec + 3);
        v = T(vec[0], vec[1], vec[2]);
        if(!mp.count(v)) {
            mp[v] = mp[u] + 1;
            q.push(v);
        }
        /*vec[0] = a, vec[1] = bb, vec[2] = c; sort(vec, vec + 3);
        v = T(vec[0], vec[1], vec[2]);
        if(!mp.count(v)) {
            mp[v] = mp[u] + 1;
            q.push(v);
        }*/
    }
    assert(0);
}

void work() {
    ll a, b, c, n; scan(a), scan(b), scan(c), scan(n);
    print(bfs(a, b, c, n), '\n');
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

