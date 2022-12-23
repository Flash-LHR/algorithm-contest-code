#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
const int N = 1e6 + 7;
int n, m, prime[N], cnt;
bool isprime[N], vis[N];
LL ans;
void ListofPrime ()
{
    for (int i = 2; i <= 1000000; ++i) isprime[i] = true;
    for (int i = 2; i <= 1000000; ++i)
    {
        if (!isprime[i]) continue;
        prime[++cnt] = i;
        for (int j = 2 * i; j <= 1000000; j += i) isprime[j] = false;
    }
}
 
int main ()
{
    scanf ("%d%d", &n, &m);
    if (n == m) {
        puts("0");
        return 0;
    }
    if (n == 1) {
        printf ("%lld\n", (LL)(1 + m) * m / 2 - 1);
        return 0;
    }
    ListofPrime();
    for (int i = n; i <= m; ++i)
    {
        if (vis[i]) continue;  
        int flag = 0;
        for (int j = 2 * i; j <= m; j += i)
        {
            if (!vis[i] || !vis[j])
            {
                if (vis[j]) flag = 1;
                vis[i] = vis[j] = true;
                ans = ans + j;
            }
        }
        if (vis[i] && i != n && !flag) ans = ans + i * n;
    }
    for (int i = n; i <= m; ++i)
    {
        if (vis[i]) continue;
        if (isprime[i]) ans = ans + i * n;
        else
        {
            for (int j = 2; j <= cnt; ++j)
            {
                if (i % prime[j] != 0) continue;
                for (int k = 1; k < j; ++k)
                {
                    int xi = i / prime[j] * prime[k];
                    if (xi >= n && xi <= m)
                    {
                        ans = ans + i * prime[k];
                        break;
                    }
                }
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
