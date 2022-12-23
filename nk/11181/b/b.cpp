#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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

const int M = (int)1e7;
const int N = (int)1e6;
const int inf = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;

int n, m;
char s[M + 5];
struct node
{
    int p, x;
    bool operator<(const node& b) const
    {
        return p < b.p;
    }
} g[2 * N + 5];
int cnt[200];
set<int> st;

void work()
{
    read(n), read(m);
    scanf("%s", s + 1);
    int l, r; char c;
    int len = 0;
    for(int i = 1; i <= m; ++i)
    {
        read(l), read(r); c = getchar();
        ++len, g[len].p = l, g[len].x = c;
        ++len, g[len].p = r + 1, g[len].x = -c;
    }
    sort(g + 1, g + len + 1);
    for(int i = 1, pre = 0, pos = 0; i <= n; ++i)
    {
        if(pos < len && g[pos + 1].p == i)
        {
            while(pos < len && g[pos + 1].p == i)
            {
                ++pos;
                if(g[pos].x > 0) {if(++cnt[g[pos].x] == 1) st.insert(-g[pos].x);}
                else {if(--cnt[-g[pos].x] == 0) st.erase(g[pos].x);}
            }
            if(st.empty()) pre = 0;
            else pre = -*(st.begin());
        }
        s[i] = max(s[i], (char)pre);
    }
    ll sum = 0; for(int i = 1; i <= n; ++i) sum += s[i];
    print(sum, '\n');
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
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


