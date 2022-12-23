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

int n;
vector<pair<int, int>> v;

bool pall(int a, int b, int c)
{
    pair<int, int> ad = make_pair(v[a].first + v[b].first, v[a].second + v[b].second);
    return ad.first * v[c].second == ad.second * v[c].first;
}

void work()
{
    read(n);
    v.push_back(make_pair(-1, -1));
    for(int i = 1, a, b, c, d; i <= n + 1; ++i)
    {
        read(a), read(b), read(c), read(d);
        v.push_back(make_pair(c - a, d - b));
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            if(pall(i, j, n + 1))
            {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    int T; read(T);
//    for(int ca = 1; ca <= T; ++ca)
//    {
//        work();
//    }
    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


