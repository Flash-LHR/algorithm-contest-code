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
tuple<int, int, int> t[M + 5];
set<tuple<int, int, int>> st;

bool better(tuple<int, int, int> t1, tuple<int, int, int> t2)
{
    return get<0>(t1) > get<0>(t2) || (get<0>(t1) == get<0>(t2) && get<1>(t1) > get<1>(t2));
}

void work()
{
    read(n), read(m);
    for(int i = 1; i <= n; ++i) get<0>(t[i]) = 0, get<1>(t[i]) = 0, get<2>(t[i]) = i;
    for(int i = 1, a, b; i <= m; ++i)
    {
        read(a), read(b);
        if(a == 1)
        {
            get<0>(t[a])++, get<1>(t[a]) -= b;
            while(!st.empty())
            {
                if(better(*st.begin(), t[1])) break;
                st.erase(st.begin());
            }
        }
        else
        {
           if(better(t[a], t[1])) st.erase(t[a]);
           get<0>(t[a])++, get<1>(t[a]) -= b;
           if(better(t[a], t[1])) st.insert(t[a]);
        }
        print(st.size() + 1, '\n');
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


