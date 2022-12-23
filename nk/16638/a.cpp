#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)1e6;
const int inf = 0x3f3f3f3f;

int n, m;
int nx[M + 5];
int cnt[M + 5];
string s[M + 5];
vector<int> w[M + 5];
vector<int> d[M + 5];
int qu[M + 5], ql, qr;

int getR() {
	memset(cnt, 0, sizeof(int) * m);
	for(int i = 0; i < n; ++i) {
		nx[0] = -1;
		for(int j = 1; j < m; ++j) {
			nx[j] = nx[j - 1];
			while(~nx[j] && s[i][nx[j] + 1] != s[i][j]) nx[j] = nx[nx[j]];
			if(s[i][nx[j] + 1] == s[i][j]) ++nx[j];
		}
		int p = nx[m - 1];
		while(~p) {
			++cnt[m - p - 1];
			p = nx[p];
		}
	}
	int mi = m;
	for(int i = 0; i < m; ++i) if(cnt[i] == n) mi = min(mi, i);
	return mi;
}

int getC() {
	memset(cnt, 0, sizeof(int) * n);
	for(int i = 0; i < m; ++i) {
		nx[0] = -1;
		for(int j = 1; j < n; ++j) {
			nx[j] = nx[j - 1];
			while(~nx[j] && s[nx[j] + 1][i] != s[j][i]) nx[j] = nx[nx[j]];
			if(s[nx[j] + 1][i] == s[j][i]) ++nx[j];
		}
		int p = nx[n - 1];
		while(~p) {
			++cnt[n - p - 1];
			p = nx[p];
		}
	}
	int mi = n;
	for(int i = 0; i < n; ++i) if(cnt[i] == m) mi = min(mi, i);
	return mi;
}

int gao(int p, int q) {
	for(int i = 0; i < n; ++i) {
		ql = 1, qr = 0;
		for(int j = 0; j < m; ++j) {
			while(ql <= qr && j - qu[ql] + 1 > q) ++ql;
			while(ql <= qr && w[i][qu[qr]] <= w[i][j]) --qr;
			qu[++qr] = j;
			d[i][j] = w[i][qu[ql]];
		}
	}
	int mi = inf;
	for(int i = 0; i < m; ++i) {
		ql = 1, qr = 0;
		for(int j = 0; j < n; ++j) {
			while(ql <= qr && j - qu[ql] + 1 > p) ++ql;
			while(ql <= qr && d[qu[qr]][i] <= d[j][i]) --qr;
			qu[++qr] = j;
			if(i >= q - 1 && j >= p - 1) mi = min(mi, d[qu[ql]][i]);
		}
	}
	return mi;
}

void work() {
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> s[i];
	for(int i = 0; i < n; ++i) {
		w[i].resize(m), d[i].resize(m);
		for(int j = 0; j < m; ++j) cin >> w[i][j];
	}
	int p = getC(), q = getR();
	printf("p=%d q=%d\n", p, q);
	int mx = gao(p, q);
	cout << (ll)mx * (p + 1) * (q + 1) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	work();
	return 0;
}
