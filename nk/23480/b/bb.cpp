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

void work() {
	int x, y; scan(x), scan(y);
	bool f = 0;
	if(x > y) swap(x, y), f = 1;
	vector<pair<int, int>> ans;
	if(y >= 11 && y - x <= 2) {
		ans.push_back(make_pair(x, y));
	} else if(x <= 18) {
		if(y < 22) return printf("NO\n"), void();
		else {
			
		}
	} else {
		if(y >= x + 4) {
			;
		} else return printf("NO\n"), void();
	}
	printf("YES\n");
	print(ans.size());
	for(auto x: ans) {
		if(f) print(x.second, ' '), print(x.first, '\n');
		else print(x.first, ' '), print(x.second, '\n');
	}
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

