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
char s[M + 5];

int randint(int l, int r) {
    return rand() * rand() % (r - l + 1) + l;
}

void work() {
    srand(time(NULL));
    int n = randint(1, 10), q = randint(1, 5);
    printf("%d %d\n", n, q);
    for(int i = 1; i <= n; ++i) {
        printf("%d", randint(0, 9));
    }
    printf("\n");
    while(q--) {
        int op = randint(1, 2);
        if(op == 1) {
            printf("1 %d %d\n", randint(1, n), randint(0, 9));
        } else {
            int x = randint(1, n);
            int y = randint(1, n);
            if(x > y) swap(x, y);
            printf("2 %d %d\n", x, y);
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
