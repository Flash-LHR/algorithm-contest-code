#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n = 2021041820210418ll;

map<int, int> mp;

/**
pair<int, int>
 **/

void work() {
	for(int i = 2; (ll)i * i <= n; ++i) if(n % i == 0) {
		int c = 0;
		while(n % i == 0) {
			++c;
			n /= i;
		}
		mp[i] = c;
	}
	if(n > 1) mp[n] = 1;
	for(pair<int, int> p: mp) {
		cout << p.first << " " << p.second << "\n";
	}
	//for(auto x: mp) cout << x.first << " " << x.second << "\n";
}

int main() {
	work();
	return 0;
}
