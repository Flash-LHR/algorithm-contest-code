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

int randint(int l, int r) {
    return rand() * rand() % (r - l + 1) + l;
}

void work() {
    srand(time(NULL));
    int n = randint((int)8e4, (int)8e4), q = randint((int)5e5, (int)5e5);
    printf("%d %d\n", n, q);
    for(int i = 1; i <= n; ++i) printf("%c", randint(0, 2) + 'a');
    printf("\n");
    while(q--) {
        int l = randint(1, n), r = randint(1, n);
        if(l > r) swap(l, r);
        printf("%d %d ", l, r);
        for(int i = 1; i <= 3; ++i) printf("%c", randint(0, 2) + 'a');
        printf("\n");
    }
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
	freopen("big.out", "w", stdout);
	int T = 1; //scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}
