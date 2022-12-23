#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
typedef __int128 i128;

i128 ar[N];
inline void print(__int128 x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9)
        print(x/10);
    putchar(x%10+'0');
}
template <typename T>
inline void cin_(T& x) {
	x = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch))  {x = x * 10 + ch - '0', ch = getchar();}
	x *= f;
}
signed main(){
	i128 n;
	cin_ (n);
	map<i128,i128> ma;
	for (int i = 0; i < n; i ++ ) {
		cin_ (ar[i]);
		ma[ar[i]]++;
	} 
	if((int)ma.size() == 1) {
		cout << "-1" << "\n";
		return 0;
	}
	map<i128, pair<i128, i128>> mp;
	for(auto &i :ma) { 
		i128 x = i.first;
		i128 num = i.second;
		if(mp.find(num) == mp.end()) {
			mp[num] = {x, -1};
			continue;
		} else {
			auto t = mp[num];
			i128 xx = t.first;
			i128 yy = t.second;
			if(xx > yy) {
				mp[num].second = max(yy, x);
			} else {
				mp[num].first = max(xx, x);
			}
		}
	}
	__int128  ans = 0;
	for (auto i : mp) {
		for (auto j : mp) {
			auto iy = i.second;
			auto jy = j.second;	
			auto ix = i.first;
			auto jx = j.first;
			if(jx == ix) {
				ans = max(ans, (__int128)((iy.first + iy.second) * 2 * ix * ix));
			} else {
				auto w1 = max(iy.second, iy.first);
				auto w2 = max(jy.second, jy.first);
				ans = max(ans, (__int128)(ix * ix + jx * jx) * (w1 + w2));
			}
		}
	}					
	print(ans);
	cout << '\n';
	return 0;
}

