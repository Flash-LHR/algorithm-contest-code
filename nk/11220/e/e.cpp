#include <bits/stdc++.h>
using namespace std;

template<typename T>
void scan(T& x) {
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

template<typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template<typename T>
void print(T x, char ch) {
    print(x), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const db eps = 1e-6;
const int M = (int)1e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int cnt[10];
int cat[10];
ll ans = 0;

void cal() {
	int s = 0;
	for(int i = 1; i <= 9; ++i) (s += i * cat[i] % 3) %= 3;
	if(s) return;
	for(int i = 1; i <= 9; ++i) if(cnt[i] < cat[i]) return;
	ll cur = 1;
	for(int i = 1; i <= 9; ++i) {
		cur *= (cnt[i] - cat[i]) / 3 + 1;
		cur %= mod;
	}
	ans += cur;
	ans %= mod;
}

void dfs(int u) {
	if(u == 10) {
		cal();
		return;
	}
	for(int i = 0; i < 3; ++i) {
		cat[u] = i;
		dfs(u + 1);
	}
}

void work() {
	for(int i = 1; i <= 9; ++i) scan(cnt[i]);
	dfs(1);
	print(ans, '\n');
}

int main() {
    /*ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);*/
    /*freopen("in", "r", stdin);
    freopen("out", "w", stdout);*/
    int T = 1;
    for(int ca = 1; ca <= T; ++ca) {
        work();
    }
    //cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
    return 0;
}


