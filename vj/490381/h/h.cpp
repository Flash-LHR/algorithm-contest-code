#include <bits/stdc++.h>
using namespace std;

void work() {
	string s; cin >> s;
	if(s.size() >= 7 && s.substr(s.size() - 7) == "chimasu")
		cout << s.substr(0, s.size() - 7) + "tte\n";
	if(s.size() >= 6 && s.substr(s.size() - 6) == "rimasu")
		cout << s.substr(0, s.size() - 6) + "tte\n";
	if(s.size() >= 6 && s.substr(s.size() - 6) == "mimasu")
		cout << s.substr(0, s.size() - 6) + "nde\n";
	if(s.size() >= 6 && s.substr(s.size() - 6) == "bimasu")
		cout << s.substr(0, s.size() - 6) + "nde\n";
	if(s.size() >= 6 && s.substr(s.size() - 6) == "nimasu")
		cout << s.substr(0, s.size() - 6) + "nde\n";	
	if(s.size() == 7 && s.substr(s.size() - 7) == "ikimasu")
		cout << s.substr(0, s.size() - 7) + "itte\n";
	else if(s.size() >= 6 && s.substr(s.size() - 6) == "kimasu")
		cout << s.substr(0, s.size() - 6) + "ite\n";
	if(s.size() >= 6 && s.substr(s.size() - 6) == "gimasu")
		cout << s.substr(0, s.size() - 6) + "ide\n";
	if(s.size() >= 7 && s.substr(s.size() - 7) == "shimasu")
		cout << s.substr(0, s.size() - 7) + "shite\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) work();
	return 0;
}
