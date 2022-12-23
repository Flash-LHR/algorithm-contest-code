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
const int M = (int)3e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m;
struct node {
	int l, r;
	bool operator<(const node& b) const {
		return l < b.l;
	}
} s[M + 5];

struct TA
{
    int n; int tree[M + 5];
    void init(int _n) {n = _n; for(int i = 0; i <= n; ++i) tree[i] = 0;}
    inline int lowbit(int n) {return n&-n;}
    void add(int a, int b) {for(int i = a; i <= n; i += lowbit(i)) tree[i] += b;}
    int ask(int r) {int s = 0; for(int i = r; i; i -= lowbit(i)) s += tree[i]; return s;}
    int ask(int l, int r) {return ask(r) - ask(l - 1);}
} tr;

bool check(int mid) {
	tr.init(n);
	for(int i = 1, j = 0; i + mid - 1 <= n; ++i) {
		while(j + 1 <= m && s[j + 1].l <= i) tr.add(s[++j].r, 1);
		if(tr.ask(i + mid - 1, n) >= mid) return 1;
	}
	return 0;
}

void work() {
	scan(n), scan(m);
	for(int i = 1; i <= m; ++i) scan(s[i].l), scan(s[i].r);
	sort(s + 1, s + m + 1);
	int l = 0, r = n, mid;
	while(l < r) {
		mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	print(r, '\n');
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

