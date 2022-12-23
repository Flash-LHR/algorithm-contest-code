#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T& x) {
	x = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
	x *= f;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch) {
	print(x), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const db eps = 1e-6;
const int M = (int)2e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, k;
char s[M + 5];
int pre[2][M + 5];

bool check(int l, int r) {
    return pre[0][r] - pre[0][l - 1] >= k &&
           pre[1][r] - pre[1][l - 1] == 0;
}

int calL(int p) {
    int l = p, r = n + 1, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(pre[0][mid] - pre[0][p - 1] >= k) r = mid;
        else l = mid + 1;
    }
    return r;
}

int calR(int p) {
    int l = p, r = n, mid;
    while(l < r) {
        mid = (l + r + 1) >> 1;
        if(pre[1][mid] - pre[1][p - 1] == 0) l = mid;
        else r = mid - 1;
    }
    return r;
}

int cal(int p) {
    int l = calL(p);
    if(l == n + 1 || pre[1][l] - pre[1][p - 1]) return 0;
    int r = calR(l);
    return r - l + 1;
}

void work() {
    scan(n), scan(k);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; ++i) {
        pre[0][i] = pre[0][i - 1] + (s[i] == 'R');
        pre[1][i] = pre[1][i - 1] + (s[i] == 'P');
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += cal(i);
    }
    print(ans, '\n');
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; //scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}
