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

bool check(int a, int b) {
	if(a > b) swap(a, b);
	if(b == 11) return a <= 9;
	if(b > 11 && b - a == 2) return 1;
	return 0;
}

void work() {
	int N = 40;
	vector<pair<int, int>> v;
	for(int i = 1; i <= N; ++i) {
		for(int j = i; j <= N; ++j) {
			if(!check(i, j)) continue;
			v.push_back(make_pair(i, j));
		}
	}
	vector<pair<int, int>> ans;
	for(auto x: v) {
		for(auto y: v) {
			ans.push_back(make_pair(x.first + y.first, x.second + y.second));
			ans.push_back(make_pair(x.first + y.second, x.second + y.first));
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	vector<int> buk[M + 5];
	for(auto x: ans) {
		buk[x.first].push_back(x.second);
	//	printf("%d %d\n", x.first, x.second);
	}
	for(int i = 2; i <= N; ++i) {
		printf("%d: ", i);
		printf("%d %d\n", buk[i][0], buk[i].back());
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

