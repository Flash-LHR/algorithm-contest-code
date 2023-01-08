#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T &n)
{
    n = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {n = n * 10 + ch - '0'; ch = getchar();}
    if (f == -1) n = -n;
}

template <typename T, typename... A>
inline void scan(T &n, A&... a)
{
    scan(n), scan(a...);
}

template <typename T>
void print(T n)
{
    if (n < 0) putchar('-'), n = -n;
    if (n > 9) print(n / 10);
    putchar(n % 10 + '0');
}

template <typename T>
void print(T n, char ch)
{
    print(n), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const int M = (int)1e5;
const int N = (int)1e5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = (int)1e9 + 7;

void work()
{
    int n, l; scan(n, l);
    vector<int> p(n), d(n), vl, vr, id(n);
    for (int i = 0; i < n; i++) {
        scan(p[i], d[i]);
        id[i] = i;
        if (d[i] == 0) vl.push_back(p[i]);
        else vr.push_back(l - p[i]);
    }
    sort(id.begin(), id.end(), [&](int a, int b) {return p[a] < p[b];});
    sort(vl.begin(), vl.end(), [](int a, int b) {return a > b;});
    sort(vr.begin(), vr.end(), [](int a, int b) {return a > b;});
    for (int i = 0, l = 0, r = n - 1; i < n; i++) {
        if (vl.size() && vr.size()) {
            if (vl.back() < vr.back()) print(id[l++] + 1, " \n"[i == n - 1]), vl.pop_back();
            else if (vl.back() > vr.back()) print(id[r--] + 1, " \n"[i == n - 1]), vr.pop_back();
            else if (id[l] < id[r]) print(id[l++] + 1, " \n"[i == n - 1]), vl.pop_back();
            else if (id[l] > id[r]) print(id[r--] + 1, " \n"[i == n - 1]), vr.pop_back();
        } else if (vl.size()) print(id[l++] + 1, " \n"[i == n - 1]), vl.pop_back();
        else print(id[r--] + 1, " \n"[i == n - 1]), vr.pop_back();
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);
    int T = 1; scan(T);
    for (int ca = 1; ca <= T; ++ca) {
        printf("Case #%d: ", ca);
        work();
    }
    // cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}