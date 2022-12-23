#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = (int)998244353;

struct Matrix
{
	int d[2][2];
	
	Matrix()
	{
		memset(d, 0, sizeof(d));
	}

	Matrix operator* (const Matrix &b)
	{
		Matrix c;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					c.d[i][j] = (c.d[i][j] + (ll)d[i][k] * b.d[k][j] % mod) % mod;
		return c;
	}
};

Matrix quick(Matrix a, ll b)
{
	Matrix s;
	s.d[0][0] = s.d[1][1] = 1;
	while (b) {
		if (b & 1) s = s * a;
		a = a * a;
		b >>= 1;
	}
	return s;
}

int fib(ll n)
{
	if (n == 0) return 0;
	Matrix a, b;
	a.d[0][0] = 1, b.d[0][0] = 1, b.d[0][1] = 1, b.d[1][0] = 1;
	Matrix c = a * quick(b, n - 1);
	return c.d[0][0];
}

void work()
{
	ll p, q; scanf("%lld %lld", &p, &q);
	p *= 1e8, q *= 1e8;
	int a = fib(p), b = fib(q);
	int ans = (b - a + mod) % mod;
	printf("%d\n", ans);
}

int main()
{
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}
