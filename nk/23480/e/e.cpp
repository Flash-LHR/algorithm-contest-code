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
const ll mod = (ll)998244353;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int inv2 = 499122177;

int n, m;
char s[M + 5];

struct Matrix {
	int D[3][3];
	Matrix operator*(const Matrix& B) const {
		Matrix C; memset(C.D, 0, sizeof(C.D));
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				for(int k = 0; k < 3; ++k) {
					(C.D[i][j] += (ll)D[i][k] * B.D[k][j] % mod) %= mod;
				}
			}
		}
		return C;
	}

	void nmsl() {
		printf("-------------------\n");
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				printf("%d ", D[i][j]);
			}
			printf("\n");
		}
	}
};

Matrix ANS;

struct segT {
	Matrix a[M * 4 + 5];

	int lc(int k) {return k<<1;}
	int rc(int k) {return k<<1|1;}

	void push_up(int k) {
		a[k] = a[rc(k)] * a[lc(k)];
	}

	void build(int k, int l, int r) {
		if(l == r) {
			if(s[l] == '1') {
				a[k].D[0][0] = 1, a[k].D[0][1] = inv2, a[k].D[0][2] = inv2;
				a[k].D[1][0] = 0, a[k].D[1][1] = inv2, a[k].D[1][2] = 0;
				a[k].D[2][0] = 0, a[k].D[2][1] = 0, a[k].D[2][2] = inv2;
			} else if(s[l] == '2') {
				a[k].D[0][0] = inv2, a[k].D[0][1] = 0, a[k].D[0][2] = 0;
				a[k].D[1][0] = inv2, a[k].D[1][1] = 1, a[k].D[1][2] = inv2;
				a[k].D[2][0] = 0, a[k].D[2][1] = 0, a[k].D[2][2] = inv2;
			} else {
				a[k].D[0][0] = inv2, a[k].D[0][1] = 0, a[k].D[0][2] = 0;
				a[k].D[1][0] = 0, a[k].D[1][1] = inv2, a[k].D[1][2] = 0;
				a[k].D[2][0] = inv2, a[k].D[2][1] = inv2, a[k].D[2][2] = 1;
			}
			return;
		}
		int mid = (l + r) >> 1;
		build(lc(k), l, mid);
		build(rc(k), mid + 1, r);
		push_up(k);
	}

	void update(int k, int l, int r, int x, int b) {
		if(l == r) {
			if(b == 1) {
				a[k].D[0][0] = 1, a[k].D[0][1] = inv2, a[k].D[0][2] = inv2;
				a[k].D[1][0] = 0, a[k].D[1][1] = inv2, a[k].D[1][2] = 0;
				a[k].D[2][0] = 0, a[k].D[2][1] = 0, a[k].D[2][2] = inv2;
			} else if(b == 2) {
				a[k].D[0][0] = inv2, a[k].D[0][1] = 0, a[k].D[0][2] = 0;
				a[k].D[1][0] = inv2, a[k].D[1][1] = 1, a[k].D[1][2] = inv2;
				a[k].D[2][0] = 0, a[k].D[2][1] = 0, a[k].D[2][2] = inv2;
			} else {
				a[k].D[0][0] = inv2, a[k].D[0][1] = 0, a[k].D[0][2] = 0;
				a[k].D[1][0] = 0, a[k].D[1][1] = inv2, a[k].D[1][2] = 0;
				a[k].D[2][0] = inv2, a[k].D[2][1] = inv2, a[k].D[2][2] = 1;
			}
			return;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) update(lc(k), l, mid, x, b);
		else update(rc(k), mid + 1, r, x, b);
		push_up(k);
	}

	void query(int k, int l, int r, int x, int y) {
		if(l >= x && r <= y) return ANS = a[k] * ANS, void();
		int mid = (l + r) >> 1;
		if(x <= mid) query(lc(k), l, mid, x, y);
		if(mid < y)  query(rc(k), mid + 1, r, x, y);
	}
} tr;

void work() {
	scan(n), scan(m);
	scanf("%s", s + 1);
	tr.build(1, 1, n);
	Matrix INI;
	for(int i = 0; i < 3; ++i) for(int j = 0; j < 3; ++j) INI.D[i][j] = (j == 0);
	for(int i = 1, op, x, y, l, r; i <= m; ++i) {
		scan(op);
		if(op == 1) {
			scan(x), scan(y);
			tr.update(1, 1, n, x, y);
		} else if(op == 2) {
			scan(l), scan(r);
			for(int j = 0; j < 3; ++j) for(int k = 0; k < 3; ++k) ANS.D[j][k] = (j == k);
			tr.query(1, 1, n, l, r);
			ANS = ANS * INI;
			print(ANS.D[0][0], ' '), print(ANS.D[1][0], ' '), print(ANS.D[2][0], '\n');
		}
	}
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

