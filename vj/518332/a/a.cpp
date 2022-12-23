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

char s[M + 5];
char v[] = "aeiou";

bool check(char ch)
{
	for(int i = 0; i < 5; ++i) if(ch == v[i]) return true;
	return false;
}

void work() {
	scanf("%s", s + 1);
	int n = strlen(s + 1), m = 0;
	for(int i = 1; i <= n; ++i) if(check(s[i])) ++m;
	if(m == 0) return print(1, '\n');
	if(!check(s[1])) return print(0, '\n');
	if(m == 1) return print(n, '\n');
	for(int i = 1, cnt = 0; i <= n; ++i) if(check(s[i])) {
		++cnt;
		if(cnt == (m + 1) / 2) {
			int l = i + 1;
			int r = i;
			while(r + 1 <= n && !check(s[r + 1])) ++r;
			print(r - l + 2, '\n');
			break;
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

