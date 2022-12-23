#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::pair<ll, ll> PLL;
//#pragma GCC optimize(3,"Ofast","inline")
#define x first
#define y second
#define pb push_back
#define mkp make_pair
#define endl "\n"
using namespace std;
const int N = 1e6 + 100;
string s[N];
int mp[N];
int q[N];
int n, m;
int ne[N];

void get_ne(string s){
	int len = s.size() - 1;
	ne[1] = 0;
	for(int i = 2, j = 0; i <= len; i++){
		while(j && s[j + 1] != s[i]) j = ne[j];
		if(s[i] == s[j + 1]) j++;
		ne[i] = j;
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = " " + s[i];
	}
	vector<vector<int>> c(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>> val(n + 1, vector<int>(m + 1, 0));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c[i][j];
	int x = n, y = m;
	for(int i = 1; i <= n; i++){
		get_ne(s[i]);
		int t = m;
		while(ne[t]){
			mp[m - ne[t]] ++;
			if(mp[m - ne[t]] == n){
				y = min(m - ne[t], y);
			}
			t = ne[t];
		}
	}
	memset(mp, 0, sizeof mp);
	for(int i = 1; i <= m; i++){
		string t(n + 1, 0);
		for(int j = 1; j <= n; j++)
			t[j] = s[j][i];
		get_ne(t);
		int tmp = n;
		while(ne[tmp]){
			mp[n - ne[tmp]] ++;
			if(mp[n - ne[tmp]] == m)
				x = min(n - ne[tmp], x);
			tmp = ne[tmp];
		}
	}
	for(int i = 1; i <= n; i++){
		int hh = 0, tt = -1;
		for(int j = 1; j < y; j++){
			while(hh <= tt && c[i][q[tt]] <= c[i][j]) tt--;
			q[++tt] = j;
		}
		for(int j = y; j <= m; j++){
			if(hh <= tt && j - q[hh] >= y) hh++;
			while(hh <= tt && c[i][q[tt]] <= c[i][j]) tt--;
			q[++tt] = j; 
			val[i][j] = c[i][q[hh]];
		}
	}
	ll ans = 2e9;
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= m; j++)
	// 		cout << val[i][j] << " ";
	// 	cout << endl;
	// }

	for(int i = y; i <= m; i++){
		int hh = 0, tt = -1;
		for(int j = 1; j < x; j++){
			while(hh <= tt && val[q[tt]][i] <= val[j][i]) tt--;
			q[++tt] = j;
		}
		for(int j = x; j <= n; j++){
			if(hh <= tt && j - q[hh] >= x) hh++;
			while(hh <= tt && val[q[tt]][i] <= val[j][i]) tt--;
			q[++tt] = j;
			ans = min(ans, 1ll * val[q[hh]][i]);
		}
	}
	cout << 1ll * (x + 1) * (y + 1) * ans << endl;
    return 0;
}

