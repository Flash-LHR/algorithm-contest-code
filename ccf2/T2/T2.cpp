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

int n, m;
ll a[5][5] = {{0, 127, 255, 255, 255},
              {0, 191, 255, 255, 255},
              {0, 223, 255, 255, 255}, 
              {0, 239, 255, 255, 255},
              {0, 255, 255, 255, 254}};
char s[M + 5];
vector<ll> v[5][50];

void parse()
{
    int n = strlen(s); ll x = 0, y = 0;
    for(int i = 0; i < n; ++i)
    {
        if(isdigit(s[i])) y = y * 10 + s[i] - '0';
        else x = x * 256 + y, y = 0;
    }
    x = x * 256 + y;
    int p = -1; for(int i = 0; i < 5; ++i) if(x <= a[i][0]) {p = i; break;}
    assert(~p);
    for(int i = 1; i <= 32; ++i) v[p][i].push_back(x>>(32-i));
}

void work()
{
    for(int i = 0; i < 5; ++i) for(int j = 0; j < 5; ++j) a[i][0] = a[i][0] * 256 + a[i][j];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%s", s), parse();
    for(int i = 0; i < 5; ++i) for(int j = 1; j <= 32; ++j) sort(v[i][j].begin(), v[i][j].end());
    for(int i = 0, k, l, r; i < m; ++i)
    {
        scanf("%d %d %d", &k, &l, &r);
        for(int j = 0; j < 5; ++j) printf("%d%c", upper_bound(v[j][k].begin(), v[j][k].end(), r) - lower_bound(v[j][k].begin(), v[j][k].end(), l), 
                                                  j == 4 ? '\n' : ' ');
    }
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


