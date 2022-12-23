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

const int M = (int)1e5;

int n, q;
ll a[M + 5];
ll d[M + 5];

void work() {
	scan(n), scan(q);
	for(int i = 1; i <= n; ++i) scan(a[i]);
	for(int i = 1, l, r, c; i <= q; ++i) {
		scan(l), scan(r), scan(c);
		d[l] += c, d[r + 1] -= c;
		/*
		   前缀和后相当于：
			d[l..n] += c, d[r+1..n] -= c
				-> d[l,r] += c
		  */
	}
	for(int i = 1; i <= n; ++i) print(a[i] += d[i] += d[i - 1], i == n ? '\n' : ' ');
}

int main() {
	work();
	return 0;
}
