#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;

char s[M + 5];

void work() {
	scanf("%s", s + 1);
	for(int i = 1; s[i]; ++i) {
		printf("%c", s[i]);
		if(i >= 3 && s[i - 2] == 'c' &&
				     s[i - 1] == 'j' && 
					 s[i] == 'b') printf(",");
	}
	printf("\n");
}

int main() {
	int T = 1; //scanf("%d", &T);
	while(T--) work();
	return 0;
}
