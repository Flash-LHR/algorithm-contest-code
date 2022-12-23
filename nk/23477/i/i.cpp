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

string str = "\"!'*+-.08:=^_WTYUIOAHXVM|";
vector<pair<char, char>> v;

void parse() {
	for(auto x: str) v.push_back(make_pair(x, x));
	cout << v.size() << "\n";
	v.push_back(make_pair('<', '>'));
	v.push_back(make_pair('\\', '/'));
	v.push_back(make_pair('[', ']'));
	v.push_back(make_pair('{', '}'));
	v.push_back(make_pair('(', ')'));
	cout << v.size() << "\n";
}

string s;

void work() {
	parse();
	int n, m; scan(n), scan(m);
	s.resize(n);
	if(n & 1) {
		if(m <= 25) {
			if(2 * m + 1 > n) return print(-1, '\n'), void();
			for(int i = 0, j = n - 1; i < m; ++i, --j) {
				s[i] = v[i].first, s[j] = v[i].second;
			}
			for(int i = m; i < n - m; ++i) s[i] = v[0].first;
		} else if(m <= 30) {
			if()
		}
	} else {
		if(m <= 25) {
			if(2 * m > n) return print(-1, '\n'), void();
			for(int i = 0, j = n - 1; i < m; ++i, --j) {
				s[i] = v[i].first, s[j] = v[i].second;
			}
			for(int i = m; i < n - m; ++i) s[i] = v[0].first;
			cout << s << "\n";
		} else if(m <= 30){
			if(m&1) return print(-1, '\n'), void();
			if(2 * m > n) return print(-1, '\n'), void();
			for(int i = 0, j = n - 1; i < m; ++i, --j) {
				s[i] = v[i].first, s[j] = v[i].second;
			}
			for(int i = m; i < n - m; ++i) s[i] = v[0].first;
			cout << s << "\n";
		} else return print(-1, '\n'), void();
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

