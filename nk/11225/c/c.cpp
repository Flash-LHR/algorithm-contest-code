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
const int M = (int)5e6;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int cnt[M * 2 + 5];
ll id[M * 2 + 5];

void work() {
	int n, len; scan(n), scan(len);
	for(int i = 1, l, r; i <= n; ++i) {
		scan(l), scan(r);
		cnt[l]++, cnt[r + 1]--;
		id[l] += i, id[r + 1] -= i;
	}
	for(int i = 1; i <= 2 * M; ++i) cnt[i] += cnt[i - 1], id[i] += id[i - 1];
	for(int i = 1; i <= 10; ++i) printf("%d\n", nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn)
	int mxa = 0; ll mxb = 0; int ans = 0;
	for(int i = 1; i <= M; ++i) {
		if(cnt[i + len - 1] - cnt[i - 1]) {
			printf("%d: %d %lld\n", i, cnt[i + len - 1] - cnt[i - 1], 
					id[i + len - 1] - id[i - 1]);
		}
		if(cnt[i + len - 1] - cnt[i - 1] > mxa || 
				(cnt[i + len - 1] - cnt[i - 1] == mxa && 
				 id[i + len - 1] - id[i - 1] > mxb)) {
			mxa = cnt[i + len - 1] - cnt[i - 1];
			mxb = id[i + len - 1] - id[i - 1];
			ans = 1;
		} else if(cnt[i + len - 1] - cnt[i - 1] == mxa &&
				  id[i + len - 1] - id[i - 1] == mxb) {
			++ans;
		}
	}
	print(ans, '\n');
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

