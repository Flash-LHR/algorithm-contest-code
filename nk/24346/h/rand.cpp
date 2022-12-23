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

int randint(int l, int r)
{
    return rand() % (r - l + 1) + l;
}

void work()
{
   srand(time(NULL));
   int n = randint(3, 10);
   int p[n + 10]; for(int i = 1; i <= n; ++i) p[i] = i;
   random_shuffle(p + 1, p + n + 1);
   set<pair<int, int>> st;
   for(int i = 2; i <= n; ++i)
   {
       do
       {
           st.insert(make_pair(randint(1, i - 1), i));
       } while(randint(0, 4));
   }
   int m = (int)st.size();
   printf("%d %d\n", n, m);
   for(const auto [u, v]: st) printf("%d %d %d\n", p[u], p[v], randint(1, 1000000000));
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


