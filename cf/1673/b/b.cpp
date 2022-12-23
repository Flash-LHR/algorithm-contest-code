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
const int M = (int)2e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

char s[M + 5];
int cnt[M + 5][26];

void work() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; ++i) for(int j = 0; j < 26; ++j) cnt[i][j] = 0;
	vector<int> pos[26];
	for(int i = 1; i <= n; ++i) {
		pos[s[i] - 'a'].push_back(i);
		if(i) {
			for(int j = 0; j < 26; ++j) cnt[i][j] = cnt[i - 1][j];
		}
		++cnt[i][s[i] - 'a'];
	}
	for(int i = 0; i < 26; ++i) if(pos[i].size()) {
		for(int j = 0; j < (int)pos[i].size(); ++j) {
			if(j == 0) {
				for(int k = 0; k < 26; ++k) if(i != k) {
					if(cnt[pos[i][j] - 1][k] >= 2) return printf("NO\n"), void();
				}
			} else {
				for(int k = 0; k < 26; ++k) if(i != k) {
					if(cnt[pos[i][j]][k] - cnt[pos[i][j - 1]][k] >= 2) return printf("NO\n"), void();
				}
			}
		}
		for(int k = 0; k < 26; ++k) if(i != k) {
			if(cnt[n][k] - cnt[pos[i].back()][k] >= 2) return printf("NO\n"), void();
		}
	}
	printf("YES\n");
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

