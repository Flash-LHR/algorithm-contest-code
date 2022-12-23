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
typedef __int128 ll;

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

set<int> s1;
set<pair<int, int>> s2;
queue<pair<int, int>> q;

void bfs(int a, int b)
{
    s1.clear(), s2.clear();
    s2.insert(make_pair(a, b));
    q.push(make_pair(a, b));
    while(!q.empty())
    {
        auto [a, b] = q.front(); q.pop();
        s1.insert(a), s1.insert(b);
        int c = a, d = abs(a - b);
        if(!s2.count(make_pair(c, d)))
        {
            s2.insert(make_pair(c, d));
            q.push(make_pair(c, d));
        }

        c = abs(a - b), d = b;
        if(!s2.count(make_pair(c, d)))
        {
            s2.insert(make_pair(c, d));
            q.push(make_pair(c, d));
        }
    }
}

bool work(ll a = 1, ll b = 1, ll x = 1)
{
    /*printf("a,b,c=");
    print(a,' '), print(b, ' '), print(x, '\n');*/
    //printf("a=%lld b=%lld x=%lld\n", a, b, x);
    /*for(int a = 1; a <= 100; ++a)
    {
        for(int b = 1; b <= 100; ++b)
        {
            bfs(a, b);
            vector<int> v; for(const int& x: s1) v.push_back(x);
            printf("a=%d b=%d [", a ,b);
            //for(int i = 1; i < v.size(); ++i) printf(" %d", v[i] - v[i - 1]);
            for(const int& x: s1) printf(" %d", x);
            printf("]\n");
        }
        //printf("\n");
    }
    return 0;*/
    read(a), read(b), read(x);
    if(x == 0 || a == x || b == x)
    {
        printf("YES\n");
        return 1;
    }
    if(max(a, b) < x)
    {
        printf("NO\n");
        return 0;
    }
    int TLE= 0;
    while(max(a, b) >= x && (a != 0) && (b != 0))
    {
        //printf("a=%lld b=%lld x=%lld\n", a, b, x);
        if(a > b) swap(a, b);
        ll k = (b - x) / a;
        //printf("k=%lld\n", k);
        if((b - x) % a == 0 && b - k * a >= a)
        {
            printf("YES\n");
            return 1;
        }
        k = (b - a) / a;
        b -= k * a;
        if(a > b) swap(a, b);
        b -= a;
        if(a == x || b == x)
        {
           printf("YES\n");
            return 1;
        }
        //printf("a=%lld b=%lld\n",a ,b);
    }
    if(a == x || b == x)
    {
       printf("YES\n");
        return 1;
    }
    printf("NO\n");
    return 0;
}

int main()
{
    /*work();
    return 0;*/
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    /*for(int a = 1; a <= 100; ++a)
    {
        for(int b = 1; b <= 100; ++b)
        {
            printf("a=%d b=%d [", a, b);
            for(int x = 0; x <= max(a, b); ++x)
            {
                if(work(a, b, x))
                {
                    printf(" %d", x);
                }
            }
            printf("]\n");
        }
    }
    return 0;*/
    int T; read(T);
    for(int ca = 1; ca <= T; ++ca)
    {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


