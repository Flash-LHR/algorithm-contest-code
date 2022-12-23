/*************************************************************************
  > File Name: solve.cpp
  > Author: XeroxAuto
  > Mail: lanzongwei@gmail.com
  > Created Time: 2021-11-22 20:21:13
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

using cp = complex<double>;

#define endl '\n'

template<int r, int c, typename val_type=cp>
struct mat {
    array<array<val_type, c>, r> res;
    const static int cr=r, cc=c;
    void fill(const array<val_type, r * c>& val) {
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) res[i][j] = val[i * c + j];
    }
    void fill() {
        for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) res[i][j] = i == j;
    }
    array<val_type, c>& operator [] (const int& pos) {
        return res[pos];
    }
    const array<val_type, c>& operator [] (const int& pos) const {
        return res[pos];
    }
	void gauss() {
		for (int i = 0, j = 0; i < r and j < c; ++j, ++i) {
			int k = i;
			for (int t = i; t < r; ++t) if (res[t][j] != 0.) {k = t; break;}
			if (res[k][j] == 0.) {--i; continue;}
			if (k != i) {
				for (int t = 0; t < c; ++t) swap(res[i][t], res[k][t]);
			}
			for (int t = c - 1; t >= j; --t) res[i][t] /= res[i][j];
			for (int t = 0; t < r; ++t) if (t != i)
				for (int s = 0; s < c; ++s) res[t][s] -= res[i][s] * res[t][j];
		}
	}
	void print() const {
		cout << "=== matrix ===" << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) cout << res[i][j] << ' ';
			cout << endl;
		}
		cout << "==============" << endl;
	}
};

constexpr double eps = 1e-9;

int sign(double x) {
	return x < -eps ? -1 : x > eps;
}

int cmp(double a, double b) {return sign(a - b);}

bool operator == (const cp& a, const cp& b) {
	return cmp(a.real(), b.real()) == 0 and 
		   cmp(a.imag(), b.imag()) == 0;
}


void solve() {
	auto read = [] (cp& t) {
		int k1, k2; cin >> k1 >> k2; t = cp(k1, k2);
	};
	cp z[4], w[4];
	for (int i = 1; i < 4; i++) {
		read(z[i]), read(w[i]);
	}
	read(z[0]);
	cp a = (w[1] - w[2]) / (z[1] - z[2]), b = w[1] - a * z[1];
	if (a * z[3] + b == w[3]) {
		w[0] = z[0] * a + b;
	} else {
		mat<3, 4> mz; mz.fill({z[1], 1, w[1], z[1] * w[1],
							   z[2], 1, w[2], z[2] * w[2],
							   z[3], 1, w[3], z[3] * w[3],
				               });
		mz.gauss();
        cout << "nmsl\n";
		w[0] = (mz[0][3] * z[0] + mz[1][3]) / (z[0] + mz[2][3]);
	}
	cout << w[0].real() << ' ' << w[0].imag() << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout<<fixed<<setprecision(12);
	int t; cin >> t;
	while (t--) solve();

	return 0;
}

