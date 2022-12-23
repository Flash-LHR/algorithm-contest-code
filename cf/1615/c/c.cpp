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

int n;
char s[2][M + 5];

void work() {
    string s; cin >> s;
    map<string, int> mp;
    queue<string> q;
    q.push(s);
    mp[s] = 0;
    while(!q.empty()) {
        string u = q.front(); q.pop();
        for(int i = 0; i < (int)u.size(); ++i) {
            if(u[i] == '0') continue;
            string v = u;
            for(int j = 0; j < (int)v.size(); ++j) {
                if(i == j) continue;
                v[j] ^= 1;
            }
            if(!mp.count(v)) {
                mp[v] = mp[u] + 1;
                q.push(v);
            }
        }
    }
    for(const auto x: mp) {
        cout << x.first << " " << x.second << "\n";
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
