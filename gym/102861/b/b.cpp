#include <bits/stdc++.h>

#define rep(i, x) for (int i = 0; i < (x); i++)
#define endl '\n'
const int Ma = 110;
bool mz[Ma][Ma];

int xz[] = {1, 0},
	yz[] = {0, 1};

int main() {
	int n; std::cin >> n;
	rep (i, n) {
		int d, l, r, c;
		std::cin >> d >> l >> r >> c;
		rep (j, l) {
			if (mz[r][c] or r <= 0 or r > 10 or c <= 0 or c > 10) {
				while (std::cin >> l);
				std::cout << "N" << endl;
				return 0;
			}
			mz[r][c] = true;
			r += yz[d]; c += xz[d];
		}
	}
	std::cout << "Y" << endl;
}
