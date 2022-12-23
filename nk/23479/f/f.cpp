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

int getID(char ch) {
    if(ch == 'C') return 1;
    if(ch == 'D') return 2;
    if(ch == 'E') return 3;
    if(ch == 'F') return 4;
    if(ch == 'G') return 5;
    if(ch == 'A') return 6;
    if(ch == 'B') return 7;
    assert(0);
}

char s[M + 5];
vector<pair<int, int>> num;

void work() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for(int i = 1, j = 0; i <= n; ++i) {
        if(s[i] == '<') --j;
        else if(s[i] == '>') ++j;
        else num.push_back(make_pair(getID(s[i]), j));
    }
    for(auto [a, b]: num) {
        print(a);
        while(b < 0) putchar('.'), ++b;
        while(b > 0) putchar('*'), --b;
    }
    putchar('\n');
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
