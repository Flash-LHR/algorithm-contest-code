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

int cal(string n, string a)
{
    int p1 = n.size() - 1; while(p1 >= 0 && n[p1] != a[1]) --p1;
    if(p1 == -1) return inf;
    int p2 = p1 - 1; while(p2 >= 0 && n[p2] != a[0]) --p2;
    if(p2 == -1) return inf;
    return n.size() - p1 - 1 + p1 - p2 - 1;
}

void work()
{
    string n; cin >> n;
    int ans = min(cal(n, "00"), cal(n, "25"));
    ans = min(ans, cal(n, "50"));
    ans = min(ans, cal(n, "75"));
    cout << ans << "\n";
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T; cin >> T;
    for(int ca = 1; ca <= T; ++ca)
    {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


