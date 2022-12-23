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

int n, k;
int x[M + 5];

bool check(int mid)
{
    int cat = 0, l = mid, r = mid;
    while(r <= k)
    {
        while(r < k && x[r] == x[r + 1]) ++r;
        int need = x[r + 1] - x[r];
        int cnt = min(r - l + 1, (x[r] - cat) / need);
        if(cnt < r - l + 1) l += (r - l + 1) - cnt;
        ++r;
        cat += need * cnt;
        //printf("l = %d r = %d ned=%d cnt=%d cat=%d\n", l, r, need, cnt, cat);
    }
    return l == mid;
}


void work()
{
    read(n), read(k);
    for(int i = 1; i <= k; ++i) read(x[i]);
    sort(x + 1, x + k + 1); x[k + 1] = n;
    int ans = 0;
    for(int i = k; i >= 1; --i)
    {
        if(n > x[k + 1] - x[i]) n -= x[k + 1] - x[i], ++ans;
        else break;
    }
    print(ans, '\n');
    return;
    int l = 1, r = k, mid;
   // printf("check(%d) = %d\n", 5, check(5));
    //return;
    while(l < r)
    {
        mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else    l = mid + 1;
        //printf("l=%d mid=%d r=%d\n", l, mid, r);
    }
    print(k - r + 1, '\n');
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int T; read(T);
    for(int ca = 1; ca <= T; ++ca)
    {
        work();
    }
//    work();
//    cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


