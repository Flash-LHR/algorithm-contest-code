#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::pair<ll, ll> PLL;
#define x first
#define y second
#define pb push_back
#define mkp make_pair
#define endl "\n"
using namespace std;
const int N = 1e5 + 10, M = 40;
int son[N * 40][2], pos[N];
map<ll, int> mp;
int n, idx;

void insert(ll x, int lv){
	int p = 0;
	for(ll i = M; i >= 0; i--){
		int u = (x >> i) & 1ll;
		if(!son[p][u]) son[p][u] = ++ idx;
		p = son[p][u];
	}
	if(!mp.count(p)){
		mp[p] = lv;
		// cout << p << " " << mp[p] << endl;
	}
}

PLL query(ll x){
	int p = 0;
	ll res = 0;
	for(ll i = M; i >= 0; i--){
		int u = (x >> i) & 1ll;
		if(son[p][u ^ 1]){
			p = son[p][u ^ 1];
			res += 1ll << i;
		}
		else p = son[p][u];
	}
	// cout << "res:" << res << endl;
	return {res, mp[p]};
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	vector<ll> v(n + 1, 0);
	ll sum = 0, ans = 0;
	for(int i = 0, x; i < n ;i++){
		cin >> x;
		sum ^= x;
		v[i + 1] = sum;
		insert(sum, i + 1);
	}
	PII pos;
	for(int i = 0; i <= n; i++){
		ll st = i + 1;
		PLL res = query(v[i]);
		if(res.y < st) swap(res.y, st);
		if(res.x > ans){
			pos = {st, res.y};
			ans = res.x;
		}
		else if(res.x == ans){
			if(res.y < pos.y)
				pos = {st, res.y};
			else if(res.y == pos.y && res.y - st < pos.y - pos.x)
				pos = {st, res.y};
		}
	}
	if(pos.y == pos.x && pos.x == 0){
		cout << "0 1 1" << endl;
		return 0;
	}
	cout << ans << " " << pos.x << " " << pos.y << endl;
    return 0;
}
