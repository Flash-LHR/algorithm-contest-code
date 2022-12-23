#include <bits/stdc++.h>
using namespace std;

string f(string a) {
	string s = "";
	for(int i = 1; i < (int)a.size(); ++i) {
		if(a[i] % 2 == a[i - 1] % 2) s += max(a[i], a[i - 1]);
	}
	return s;
}

void work() {
	string a, b;
	cin >> a >> b;
	a = f(a), b = f(b);
	cout << a << "\n";
	if(a != b) cout << b << "\n";

}	

int main() {
	work();
	return 0;
}
