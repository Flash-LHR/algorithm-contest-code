#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 5 * 1e5 + 19;
ll ar[N];
int main(){
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    //init();
 	int n;
 	cin >> n;
 	for (int i = 0; i < n; i ++ ) {
 		cin >> ar[i];
 	}   
 	ll ans = 0;
 	for (int i = 0; i < n ; i ++ ) {
 		int cnt1 = 0, cnt2 = 0;
 		
 		int mx1 = ar[i], mx2, mi1 = ar[i], mi2;
 		for (int j = i + 1; j < n; j ++ ) {

 			if(ar[j] >= mx1) {
 				cnt1++;
 				if(cnt1 == 2) {
 					ans += (n - j);
 					break;
 				}
 				mx2 = mx1;
 				mx1 = ar[j];
 			} else {
 				if(ar[j] >= mx2 && cnt1 == 1) {
 					mx1 = ar[j];
 				} else {
 					mx2 = ar[j];
 				}
 			}

 			if(ar[j] <= mi1) {
 				cnt2++;
 				if(cnt2 == 2) {
 					ans += (n - j);
 					break;
 				}
 				mi2 = mi1;
 				mi1 = ar[j];
 			}else {
 				if(ar[j] <= mi2 && cnt2 == 1) {
 					mi1 = ar[j];
 				} else {
 					mi2 = ar[j];
 				}
 			}
 		}
 	}
 	cout << ans << '\n';
	return 0;
}

