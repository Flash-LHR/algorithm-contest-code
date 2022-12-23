#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T& x)
{
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
    x *= f;
}

template <typename T>
void print(T x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch)
{
    print(x), putchar(ch);
}

typedef double db;
typedef long long ll;

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int v[M + 5];

void work()
{
    int n, a, b; read(n), read(a), read(b);
    set<int> st;
    for(int i = 1; i <= n; ++i) st.insert(i);
    v[1] = a, v[n] = b; st.erase(a), st.erase(b);
    for(int i = 2; i <= n / 2; ++i) st.erase(v[i] = *(--st.end()));
    for(int i = n - 1; i > n / 2; --i) st.erase(v[i] = *(st.begin()));
    int mi = inf; for(int i = 1; i <= n / 2; ++i) mi = min(v[i], mi);
    int mx = -1; for(int i = n; i > n / 2; --i) mx = max(v[i], mx);
    if(mi != a || mx != b)
    {
        printf("-1\n")
          ;
        return;
    }
    for(int i = 1; i <= n; ++i) printf("%d%c", v[i], 
            i == n ? '\n' : ' ');
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T; read(T);
    for(int ca = 1; ca <= T; ++ca)
    {
        work();
   }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


