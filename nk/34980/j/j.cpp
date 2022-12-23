#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;

template <typename T>
inline void scan(T &n) {
	n = 0; int f = 1; char ch = getchar();
	while(!isdigit(ch)) {if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)) {n = n * 10 + ch - '0'; ch = getchar();}
	if(f == -1) n = -n;
}

const int M = (int)2e3;
const int mod = (int)998244353;
const db pi = acos(-1.0);

bool flag = 0;
db ang, ax, ay, rt;

struct point {
	db x, y;
	point(db _x = .0, db _y = .0) {
		x = _x, y = _y;
	}
	void print() {
		if(flag) {
			printf(" ");
		}
		flag = 1;
		db xx = x * rt, yy = y * rt;
		db xxx = xx * cos(ang) - yy * sin(ang), 
		   yyy = yy * cos(ang) + xx * sin(ang);
		db xxxx = xxx + ax, yyyy = yyy + ay;
		printf("%.12Lf %.12Lf", xxxx, yyyy);
	}
} p[100];

#if 1

db sin18 = sin(18.0 / 180 * pi), 
   cos18 = cos(18.0 / 180 * pi), 
   tan36 = tan(36.0 / 180 * pi), 
   sin72 = sin(72.0 / 180 * pi), 
   cos72 = cos(72.0 / 180 * pi),
   sin54 = sin(54.0 / 180 * pi), 
   cos54 = cos(54.0 / 180 * pi),
   x = 6 / (sin18 / tan36 + cos18);

void work() {
	flag = 0;
	point a, b;
	a.x = 0, a.y = 0;
	b.x = 0, b.y = 20;
	db ny = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	db mx = 30.0 / 20 * ny, r = 6.0 / 30 * mx;
	point o(a.x + mx / 2, a.y + ny / 2);
	point f(o.x + x * sin18, o.y + r - x * cos18);
	point n(o.x - x * sin18, o.y + r - x * cos18);
	db oh = x / 2 / cos18;
	point h(o.x + oh * sin72, o.y - oh * cos72);
	point l(o.x - oh * sin72, o.y - oh * cos72);
	point j(o.x, o.y - oh);
	point e(o.x, o.y + r);
	point g(f.x + x, f.y);
	point m(n.x - x, f.y);
	point i(j.x + x * sin54, j.y - x * cos54);
	point k(j.x - x * sin54, i.y);
	point c(a.x + mx, b.y);
	point d(c.x, a.y);


	scanf("%Lf%Lf%Lf%Lf", &a.x, &a.y, &b.x, &b.y);
	rt = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) / 20;

	ang = ((b.x - a.x) * 0 + (b.y - a.y) * 1) / sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	//printf("ang=%Lf\n", ang);
	ang = acos((ang));
	//printf("ang=%Lf\n", ang);

	ax = a.x, ay = a.y;

	c.print();
	d.print();
	e.print();
	f.print();
	g.print();
	h.print();
	i.print();
	j.print();
	k.print();
	l.print();
	m.print();
	n.print();
	printf("\n");
}

#else

void work() {
	db sin18 = sin(18.0 / 180 * pi), 
	   cos18 = cos(18.0 / 180 * pi), 
	   tan36 = tan(36.0 / 180 * pi);
	db x = 6 / (sin18 / tan36 + cos18);
	cout << 15 + x * sin18 << "\n";
	cout << 16 - x * cos18 << "\n";
}

#endif

int main() {
	int T; scanf("%d", &T);
	while(T--) work();
	return 0;
}
