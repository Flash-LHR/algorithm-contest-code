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
const int M = (int)4e4;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

vector<int> v;
char buf[1024];
char buf2[1024];
int f[M + 5];

bool check(int n) {
	sprintf(buf, "%d", n);
	int m = strlen(buf);
	strcpy(buf2, buf);
	reverse(buf2, buf2 + m);
	return !strcmp(buf, buf2);
}

void init() {
	for(int i = 1; i <= M; ++i)
		if(check(i)) v.push_back(i);
	f[0] = 1;
	for(const int &x: v) {
		for(int i = x; i <= M; ++i) (f[i] += f[i - x]) %= mod;
	}
}

void work() {
	int n; scan(n);
	printf("%d\n", f[n]);
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	init();
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

