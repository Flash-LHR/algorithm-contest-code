#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void scan(T& x) {
	x = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
	x *= f;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

template <typename T>
void print(T x, char ch) {
	print(x), putchar(ch);
}

typedef double db;
typedef long long ll;
typedef unsigned long long ull;

const db eps = 1e-6;
const int M = (int)1e5;
const int N = (int)1e5;
const ll mod = (ll)1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = (int)differences.size();
		vector<ll> hidden(n + 1);
		for(int i = 1; i < n + 1; ++i) hidden[i] = hidden[i - 1] + differences[i - 1];
		ll l = lower, r = upper;
		for(int i = 0; i < n + 1; ++i) {
			l = max(l, lower - hidden[i]);
			r = min(r, upper - hidden[i]);
		}
    	return max(0, int(r - l + 1));
	}
};

/*int main() {
	Solution A;
	vector<int> v{4,-7,2};
	cout << A.numberOfArrays(v, 3, 6) << "\n";
	return 0;
}*/
