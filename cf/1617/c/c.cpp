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
bool vis[M + 5];
multiset<int> st;

void work() {
    /*for(int n = 1; n <= 1000; ++n) {
        int mx = 0;
        for(int i = 1; i <= n; ++i) mx = max(mx, n % i);
        assert(mx == (n - 1) / 2);
    }*/
    scan(n); st.clear();
    for(int i = 1, a; i <= n; ++i) {
        scan(a);
        st.insert(a);
        vis[i] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        if(st.count(i)) {
            vis[i] = 1;
            st.erase(st.find(i));
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(vis[i]) continue;
        auto it = st.lower_bound(2 * i + 1);
        if(it == st.end()) {
            print(-1, '\n');
            return;
        } else st.erase(it), ++cnt;
    }
    printf("%d\n", cnt);
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

