#include <bits/stdc++.h>
using namespace std;

const int M = (int)3e5;
const int N = 23;

template<typename T>
inline void scan(T &x) {
	x = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	if(f == -1) x = -x;
}

template<typename T>
inline void print(T x) {
	static char buf[20];
	int p = 0, f = x < 0;
	do {
		buf[p++] = x % 10 + '0';
		x /= 10;
	} while(x);
	if(f) buf[p++] = '-';
	for(int i = p - 1; i >= 0; --i) putchar(buf[i]);
}

template<typename T>
inline void print(T x, char ending) {
	print(x), putchar(ending);
}

struct trie {
	int cnt;
	int rt[M * 2], rtCnt;
	int nx[M * 2 + M * 2 * (N + 1)][2];
	int ls[M * 2 + M * 2 * (N + 1)];

	trie() {
		cnt = 0, rtCnt = -1;
		nx[0][0] = nx[0][1] = 0;
	}

	void insert(int x, int id) {
		int u0 = (~rtCnt ? rt[rtCnt] : 0), u1 = rt[++rtCnt] = ++cnt;
		nx[cnt][0] = nx[cnt][1] = 0;
		for(int i = N, v; i >= 0; --i) {
			v = (x>>i&1);
			nx[u1][v] = ++cnt, nx[cnt][0] = nx[cnt][1] = 0;
			if(nx[u0][!v]) nx[u1][!v] = nx[u0][!v];
			u0 = nx[u0][v], u1 = nx[u1][v];
			ls[u1] = id;
		}
	}

	int query(int l, int r, int x) {
		int u = rt[r], ans = 0;
		for(int i = N, v; i >= 0; --i) {
			v = (x>>i&1);
			if(nx[u][!v] && ls[nx[u][!v]] >= l) u = nx[u][!v], ans |= (1<<i);
			else u = nx[u][v];
		}
		return ans;
	}
} tr;

void work() {
	int n, m, s = 0; scan(n), scan(m);
	tr.insert(0, 0);
	for(int i = 1, a; i <= n; ++i) scan(a), tr.insert(s^=a, i);
	char op[5];
	for(int i = 1, x, l, r; i <= m; ++i) {
		scanf("%s", op);
		if(op[0] == 'A') {
			scan(x);
			tr.insert(s^=x, ++n);
		} else if(op[0] == 'Q') {
			scan(l), scan(r), scan(x);
			print(tr.query(l - 1, r - 1, s^x), '\n');
		}
	}
}

int main() {
	work();
	return 0;
}
