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
const int M = (int)1e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n;
struct {
	int lc[M + 5], rc[M + 5];
	int fa[M + 5];
} T1, T2, T3;

void rag(int a) {
	for(int i = 1; i <= n; ++i) T3.lc[i] = T2.lc[i], T3.rc[i] = T2.rc[i], T3.fa[i] = T2.fa[i];
	int beta = T3.rc[a], b = T3.fa[a], x = T3.fa[b];
	T3.lc[b] = beta, T3.rc[a] = b;
	if(x) {
		if(b == T3.lc[x]) T3.lc[x] = a;
		else if(b == T3.rc[x]) T3.rc[x] = a;
	}
}

void lag(int b) {
	for(int i = 1; i <= n; ++i) T3.lc[i] = T2.lc[i], T3.rc[i] = T2.rc[i], T3.fa[i] = T2.fa[i];
	int beta = T3.lc[b], a = T3.fa[b], x = T3.fa[a];
	T3.rc[a] = beta, T3.lc[b] = a;
	if(x) {
		if(a == T3.lc[x]) T3.lc[x] = b;
		else if(a == T3.rc[x]) T3.rc[x] = b;
	}
}

bool check() {
	for(int i = 1; i <= n; ++i) {
		if(T1.lc[i] != T3.lc[i]) return 0;
		if(T1.rc[i] != T3.rc[i]) return 0;
	}
	return 1;
}

void work() {
	scan(n);
	for(int i = 1; i <= n; ++i) scan(T1.lc[i]), scan(T1.rc[i]), T1.fa[T1.lc[i]] = T1.fa[T1.rc[i]] = i;
	for(int i = 1; i <= n; ++i) scan(T2.lc[i]), scan(T2.rc[i]), T2.fa[T2.lc[i]] = T2.fa[T2.rc[i]] = i;
	for(int i = 1; i <= n; ++i) {
		bool flag = 0;
		if(T2.fa[i] && T2.lc[T2.fa[i]] == i) rag(i), flag = 1;
		else if(T2.fa[i] && T2.rc[T2.fa[i]] == i) lag(i), flag = 1;
		if(flag && check()) {
			print(1, '\n');
			print(i, '\n');
			return;
		}
	}
	print(0, '\n');
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

