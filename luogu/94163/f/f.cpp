#include <bits/stdc++.h>
using namespace std;

void work()
{
	int n; cin >> n;
	string name, loca; int num;
	map<string, map<string, int>> mp;
	for (int i = 1; i <= n; ++i) {
		cin >> name >> loca >> num;
		mp[loca][name] += num;
	}
	for (const auto &x: mp) {
		cout << x.first << "\n";
		cout << "--------------------\n";
		for (const auto &y: x.second) {
			cout << "    " << y.first << "(" << y.second << ")\n";
		}
		cout << "--------------------\n";
	}
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) work();
	return 0;
}
