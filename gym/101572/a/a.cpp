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

const int M = (int)5e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int a, b, t, r, n;
ll l, p[M + 5];
db f[M + 5];
int q2[M + 5], q2l, q2r;
int q3[M + 5], q3l, q3r;
int last[M + 5];

void work()
{
    read(l), read(a), read(b), read(t), read(r);
    read(n); for(int i = 1; i <= n; ++i) read(p[i]); p[++n] = l;
    for(int i = 1; i <= n; ++i) f[i] = 1e18;
    int l0 = t * a, l1 = t * a + r * b;
    int j1 = 0, j11 = 0; db mi1 = 1e18;
    q2l = 1, q2r = 0; int j2 = 0;
    q3l = 1, q3r = 0; int j3 = 0;
    for(int i = 1; i <= n; ++i)
    {
        f[i] = (db)p[i] / a;
        
        while(j1 + 1 < i && p[j1 + 1] <= p[i] - l1)
        {
            ++j1;
            if(mi1 > f[j1] - (db)p[j1] / a)
            {
                mi1 = f[j1] - (db)p[j1] / a;
                j11 = j1;
            }
        }
        if(f[i] > mi1 + (db)(p[i] - l1) / a + t + r)
        {
            f[i] = mi1 + (db)(p[i] - l1) / a + t + r;
            last[i] = j11;
        }
        
        while(j2 + 1 < i && p[j2 + 1] <= p[i] - l0)
        {
            ++j2;
            while(q2l <= q2r && f[q2[q2r]] - (db)p[q2[q2r]] / b >= f[j2] - (db)p[j2] / b) --q2r;
            q2[++q2r] = j2;
        }
        if(q2l <= q2r)
        {
            if(f[i] > f[q2[q2l]] - (db)p[q2[q2l]] / b + (db)(p[i] - l0) / b + t)
            {
                f[i] = f[q2[q2l]] - (db)p[q2[q2l]] / b + (db)(p[i] - l0) / b + t;
                last[i] = q2[q2l];
            }
        }
        while(q2l <= q2r && p[i] - l1 >= p[q2[q2l]]) ++q2l;
       
        while(q3l <= q3r && p[i] - l0 >= p[q3[q3l]]) ++q3l;
        while(j3 + 1 < i)
        {
            ++j3;
            while(q3l <= q3r && f[q3[q3r]] - (db)p[q3[q3r]] / a >= f[j3] - (db)p[j3] / a) --q3r;
            q3[++q3r] = j3;
        }
        if(q3l <= q3r)
        {
            if(f[i] > f[q3[q3l]] - (db)p[q3[q3l]] / a + (db)p[i] / a)
            {
                last[i] = q3[q3l];
                f[i] = f[q3[q3l]] - (db)p[q3[q3l]] / a + (db)p[i] / a;
            }
        }

        //printf("f[%d]=%f\n", i, f[i]);
    }
    printf("%f\n", f[n]);
    vector<int> v;
    int cur = n;
    while(cur)
    {
        cur = last[cur];
        if(cur) v.push_back(cur);
    }
    reverse(v.begin(), v.end());
    print(v.size(), '\n');
    for(const int& x: v) print(x - 1, ' ');
    putchar('\n');
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


