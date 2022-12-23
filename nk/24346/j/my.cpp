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

typedef tuple<int, int, int, int> T;

queue<T> q;
map<T, int> mp;

void init()
{
    T s(0, 0, 0, 0), u, v;
    q.emplace(s), mp[s] = 0;
    while(!q.empty())
    {
        u = q.front(); q.pop();
        auto [w, x, y, z] = u;
        int a[4] = {w, x, y, z};
        for(int k = -1; k <= 1; k += 2)
        {
            for(int i = 0; i < 4; ++i)
            {
                for(int j = i; j < 4; ++j)
                {
                    (a[j] += k) %= 10, (a[j] += 10) %= 10;
                    v = T(a[0], a[1], a[2], a[3]);
                    if(!mp.count(v))
                    {
                        mp[v] = mp[u] + 1;
                        q.push(v);
                    }
                }
                for(int j = i; j < 4; ++j) (a[j] -= k) %= 10, (a[j] += 10) %= 10;
            }
        }
    }
}

int a[4], b[4];

void work()
{
    for(int i = 0; i < 4; ++i) scanf("%1d", &a[i]);
    for(int i = 0; i < 4; ++i) scanf("%1d", &b[i]), (b[i] -= a[i]) %= 10, (b[i] += 10) %= 10;
    T v(b[0], b[1], b[2], b[3]);
    print(mp[v], '\n');
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    init();
    int T; read(T);
    for(int ca = 1; ca <= T; ++ca)
    {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


