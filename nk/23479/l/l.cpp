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
const int M = (int)8e4;
const int N = (int)3e2;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int n, m, block;
char s[M + 5];
int id[M + 5];
int f[N + 5][26][26][26];
int sum[N + 5][26][26][26];
int g[N + 5][26][26];
int h[N + 5][26];
int L[N + 5], R[N + 5];

void parse() {
    for(int i = 1; i <= n; ++i) id[i] = (i - 1) / block + 1;
    for(int l = 1, r = 0; l <= n; l = r + 1) {
        while(r + 1 <= n && id[l] == id[r + 1]) ++r;
        L[id[l]] = l, R[id[l]] = r;
        for(int i = l; i <= r; ++i) {
            for(int j = 0; j < 26; ++j) {
                for(int k = 0; k < 26; ++k) {
                    f[id[l]][j][k][s[i] - 'a'] += g[id[l]][j][k];
                }
                g[id[l]][j][s[i] - 'a'] += h[id[l]][j];
            }
            h[id[l]][s[i] - 'a']++;
        }
    }
    for(int i = 0; i < 26; ++i) {
        for(int j = 0; j < 26; ++j) {
            for(int k = 0; k < 26; ++k) {
                for(int l = 1; l <= id[n]; ++l) sum[l][i][j][k] = sum[l - 1][i][j][k] + f[l][i][j][k];
            }
        }
    }
}

ll bao(int l, int r, char t[]) {
    int pre = (s[l] == t[1]), suf = 0;
    for(int i = l + 2; i <= r; ++i) if(s[i] == t[3]) ++suf;
    ll ans = 0;
    for(int i = l + 1; i + 1 <= r; ++i) {
        if(s[i] == t[2]) ans += (ll)pre * suf;
        if(s[i] == t[1]) ++pre;
        if(s[i + 1] == t[3]) --suf;
    }
    return ans;
}

ll cal_abc(int l, int r, char t[]) {
    ll ans = bao(l, R[id[l]], t) + bao(L[id[r]], r, t);
    ans += sum[id[r] - 1][t[1] - 'a'][t[2] - 'a'][t[3] - 'a'] - sum[id[l]][t[1] - 'a'][t[2] - 'a'][t[3] - 'a'];
    return ans;
}

ll cal_ab_c(int l, int r, char t[]) {
    int pre = 0, suf = 0, cnt = 0;
    ll ans = 0;
    for(int i = L[id[r]]; i <= r; ++i) if(s[i] == t[3]) ++suf;
    for(int i = id[l] + 1; i < id[r]; ++i) suf += h[i][t[3] - 'a'];
    for(int i = l; i <= R[id[l]]; ++i) {
        if(s[i] == t[2]) cnt += pre;
        if(s[i] == t[1]) pre++;
    }
    ans += (ll)cnt * suf;
    for(int i = id[l] + 1; i < id[r]; ++i) {
        suf -= h[i][t[3] - 'a'];
        ans += (ll)g[i][t[1] - 'a'][t[2] - 'a'] * suf;
    }
//    printf("ab_c: %lld\n", ans);
    return ans;
}

ll cal_a_bc(int l, int r, char t[]) {
    int pre = 0, suf = 0, cnt = 0;
    ll ans = 0;
    for(int i = L[id[r]]; i <= r; ++i) {
        if(s[i] == t[3]) cnt += pre;
        if(s[i] == t[2]) pre++;
    }
    pre = 0;
    for(int i = l; i <= R[id[l]]; ++i) if(s[i] == t[1]) ++pre;
    for(int i = id[l] + 1; i < id[r]; ++i) pre += h[i][t[1] - 'a'];
    ans += (ll)pre * cnt;
    for(int i = id[r] - 1; i > id[l]; --i) {
        pre -= h[i][t[1] - 'a'];
        ans += (ll)pre * g[i][t[2] - 'a'][t[3] - 'a'];
    }
//    printf("a_bc: %lld\n", ans);
    return ans;
}

ll cal_a_b_c(int l, int r, char t[]) {
    int pre = 0, suf = 0;
    ll ans = 0;
    for(int i = l; i <= R[id[l]]; ++i) if(s[i] == t[1]) ++pre;
    for(int i = L[id[r]]; i <= r; ++i) if(s[i] == t[3]) ++suf;
    for(int i = id[l] + 2; i < id[r]; ++i) suf += h[i][t[3] - 'a'];
    for(int i = id[l] + 1; i < id[r]; ++i) {
        ans += (ll)pre * h[i][t[2] - 'a'] * suf;
        pre += h[i][t[1] - 'a'];
        suf -= h[i + 1][t[3] - 'a'];
    }
//    printf("a_b_c: %lld\n", ans);
    return ans;
}

ll cal(int l, int r, char t[]) {
    return cal_abc(l, r, t)
         + cal_ab_c(l, r, t)
         + cal_a_bc(l, r, t)
         + cal_a_b_c(l, r, t);
}

void work() {
    scan(n), scan(m); block = (int)sqrt(n);
    scanf("%s", s + 1);
    parse();
    char t[5]; int l, r;
    for(int _ = 1; _ <= m; ++_) {
        scan(l), scan(r), scanf("%s", t + 1);
        if(id[r] - id[l] + 1 <= 2) {
            print(bao(l, r, t), '\n');
        } else {
            print(cal(l, r, t), '\n');
        }
    }
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("big.out", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; //scan(T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}
