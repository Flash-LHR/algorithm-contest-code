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
const int M = (int)1e3;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m;
string s[M + 5];
map<string, int> mid; int idcnt;
int a[M + 5][M + 5];
vector<int> v;
int id[M + 5];

void work() {
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> s[i];
		mid[s[i]] = ++idcnt;
	}
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= m; ++j) cin >> a[i][j];
	string sql;
	cin.ignore();
	getline(cin, sql);
	int len = (int)sql.size();
	int p = 0; for(int i = 0; i < len; ++i) if(sql[i] == 'B') {p = i; break;}
	for(int i = p + 3, l = p + 3; i < len; ++i) {
		if(sql[i] == ',' || sql[i] == ';') {
			v.push_back(mid[sql.substr(l, i - l)]);
			l = i + 1;
		}
	}
	iota(id + 1, id + n + 1, 1);
	sort(id + 1, id + n + 1, [&](int x, int y) {
		for(const int& i: v) {
			if(a[x][i] != a[y][i]) return a[x][i] < a[y][i];
		}
		return false;
	});
	auto cmp = [&](int x, int y) {
		for(const int& i: v) {
			if(a[x][i] != a[y][i]) return false;
		}
		return true;
	};
	vector<int> ans;
	for(int l = 1, r = 0; l <= n; l = r + 1) {
		while(r + 1 <= n && cmp(id[l], id[r + 1])) ++r;
		ans.push_back(r - l + 1);
	}
	cout << ans.size() << "\n";
	for(auto x: ans) cout << x << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; //scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

