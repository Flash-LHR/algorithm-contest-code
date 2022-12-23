#include <bits/stdc++.h>
using namespace std;

typedef double db;

const int M = (int)1e3;

vector<vector<string>> v;

void init() {
	vector<string> u;

	u.clear();
	u.push_back("#################");
	u.push_back("#################");
	u.push_back("#################");
	u.push_back("####..#####..####");
	u.push_back("###....###....###");
	u.push_back("###....###....###");
	u.push_back("####..#####..####");
	u.push_back("#################");
	u.push_back("#################");
	u.push_back("#################");
	v.push_back(u);


	u.clear();
	u.push_back("#########");
	u.push_back("#########");
	u.push_back("#########");
	u.push_back("####..###");
	u.push_back("###....##");
	u.push_back("###....##");
	u.push_back("####..###");
	u.push_back("#########");
	u.push_back("#########");
	u.push_back("#########");
	u.push_back("####..###");
	u.push_back("###....##");
	u.push_back("###....##");
	u.push_back("####..###");
	u.push_back("#########");
	u.push_back("#########");
	u.push_back("#########");
	v.push_back(u);

	u.clear();
	u.push_back("#############");
	u.push_back("#############");
	u.push_back("#############");
	u.push_back("#############");
	u.push_back("####..####...");
	u.push_back("###....###...");
	u.push_back("###....###...");
	u.push_back("####..####...");
	u.push_back("##########...");
	u.push_back("##########...");
	u.push_back("##########...");
	u.push_back("##########...");
	v.push_back(u);

	u.clear();
	u.push_back("##########");
	u.push_back("##########");
	u.push_back("##########");
	u.push_back("####..####");
	u.push_back("###....###");
	u.push_back("###....###");
	u.push_back("####..####");
	u.push_back("##########");
	u.push_back("##########");
	u.push_back("##########");
	u.push_back("###.......");
	u.push_back("###.......");
	u.push_back("###.......");
	u.push_back("###.......");
	v.push_back(u);

	u.clear();
	u.push_back("");
	u.push_back("");
	u.push_back("");
	u.push_back("");
	u.push_back("");
	u.push_back("");
	u.push_back("");
	u.push_back("");
	u.push_back("");
	u.push_back("");
	u.push_back("");
	u.push_back("");
	u.push_back("");
	u.push_back("");
}

int n, m;
char s[M + 5][M + 5];
bool vis[M + 5][M + 5];



int calc() {
	for(int i = )
}

void work() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	int c = calc();
	int s = cals();
	printf("%d %d\n", c, s);
}

int main() {
	init();
	int T = 1; //scanf("%d", &T);
	while(T--) work();
	return 0;
}
