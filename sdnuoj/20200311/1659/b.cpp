#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T& x)
{
    x = 0; int f = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
    x *= f;
}

template <typename T>
void print(T x)
{
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch)
{
    print(x), putchar(ch);
}

typedef long long ll;

const int M = (int)1e3;

int n, m, q;
ll s[M + 5][M + 5];

void work() {
	scan(n), scan(m), scan(q);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			scan(s[i][j]);
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	for(int i = 1, x, y; i <= q; ++i) {
		scan(x), scan(y);
		print(s[x][y], '\n');
	}
}

int main() {
	work();
	return 0;
}
