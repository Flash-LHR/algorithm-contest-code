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

int n, t;
char s[M + 5];
int a[M + 5];
int id[M + 5];

struct qnode {
    int en; char ch;
    qnode(int _en, char _ch): en(_en), ch(_ch){}
    bool operator<(const qnode& b) const {
        return en > b.en;
    }
};
priority_queue<qnode> q;

void work() {
    scan(n), scan(t);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; ++i) scan(a[i]), id[i] = i;
    sort(id + 1, id + n + 1, [&](int x, int y) {
         return a[x] < a[y];
    });
    int bc = 0, rc = 0, ans = 0;
    for(int i = 1, j = 1; i <= 2 * M; ++i) {
        while(!q.empty() && q.top().en == i) {
            if(q.top().ch == 'B') --bc;
            else --rc;
            q.pop();
        }
        while(j <= n && a[id[j]] == i) {
            if(s[id[j]] == 'B') ++bc;
            else ++rc;
            q.push(qnode(a[id[j]] + t, s[id[j]]));
            ++j;
        }
        if(bc && !rc) ++ans;
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
