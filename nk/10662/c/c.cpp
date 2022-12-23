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

void work()
{
   ll a1, a2, a3; read(a1), read(a2), read(a3);
   ll ans = 0;
   
   ll mi = min(a1, a2);
   a1 -= mi, a2 -= mi, ans += 2 * mi;

   if(a1)
   {
       if(a1 % 3 == 0) ans += a1;
       else if(a1 % 3 == 1) ans += a1 / 3 * 3;
       else if(a1 % 3 == 2) ans += a1 / 3 * 3 + 1;
   }
   else if(a2)
   {
        if(a2 % 3 == 0) ans += a2 * 2;
        else if(a2 % 3 == 1) ans += a2 / 3 * 3 * 2;
        else if(a2 % 3 == 2) ans += a2 / 3 * 3 * 2 + 4;
   }
   print(ans, '\n');
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


