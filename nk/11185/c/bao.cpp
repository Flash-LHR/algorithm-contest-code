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

int n, k;
int a[M + 5];
int b[M + 5];

void nmsl(vector<int> v) {
	printf("vvv: ");
	for(auto x: v) printf("%d ", x); printf("\n");
}

int bfs() {
	vector<int> v(n);
	map<vector<int>, int> mp;
	for(int i = 0; i < n; ++i) v[i] = a[i + 1];
	mp[v] = 0;
	queue<vector<int>> q;
	q.push(v);
	while(!q.empty()) {
		vector<int> v = q.front(); q.pop();
		//printf("v:"); for(auto x: v) printf(" %d", x); printf("\n");
		if(accumulate(v.begin(), v.end(), 0) == 0) return mp[v];
		for(int i = 0; i < n; ++i) {
			vector<int> vv(v);
			for(int j = i; j < n; ++j) {
				if(vv[j] == 0) break;
				--vv[j];
				if(j - i + 1 < k) continue;
				vector<int> vvv(vv);
				//nmsl(vvv);
				if(!mp.count(vvv)) {
					mp[vvv] = mp[v] + 1;
					q.push(vvv);
				}
			}
		}
	}
	return -1;
}

void work() {
	scan(n), scan(k);
	auto cal = [](ll x) {
		int c = 0;
		while(x > 1) ++c, x >>= 1;
		return c;
	};
	for(int i = 1; i <= n; ++i) {
		ll x; scan(x);
		a[i] = cal(x);
	}
	print(bfs(), '\n');
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

