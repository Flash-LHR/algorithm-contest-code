#include <bits/stdc++.h>
using namespace std;

void work()
{
	string s, t = "Yes";
	cin >> s;
	int offset = -1;
	if (s[0] == 'Y') offset = 0;
	else if (s[0] == 'e') offset = 1;
	else if (s[0] == 's') offset = 2;
	if (offset == -1) return puts("NO"), void();
	for (size_t i = 0; i < s.size(); ++i)
		if (s[i] != t[(i + offset) % 3])
			return puts("NO"), void();
	puts("YES");
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
