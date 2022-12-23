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

int n, q;
char s[M + 5], t[M + 5];

void work() {
    scan(n), scan(q);
    scanf("%s", s + 1);
    for(int _ = 1; _ <= q; ++_) {
        int l, r; scan(l), scan(r);
        scanf("%s", t + 1);
        int ans = 0;
        for(int i = l; i <= r; ++i) {
            if(s[i] != t[1]) continue;
            for(int j = i + 1; j <= r; ++j) {
                if(s[j] != t[2]) continue;
                for(int k = j + 1; k <= r; ++k) {
                    if(s[k] != t[3]) continue;
                    ++ans;
                }
            }
        }
        print(ans, '\n');
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
