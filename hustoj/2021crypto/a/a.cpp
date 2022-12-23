#include <cstdio>
using namespace std;

inline bool ishex(char ch) {
	return ('0' <= ch && ch <= '9') ||
		('a' <= ch && ch <= 'f') || 
		('A' <= ch && ch <= 'F');
}

inline int chrToHex(char ch) {
	if('0' <= ch && ch <= '9') return ch - '0';
	if('a' <= ch && ch <= 'f') return ch - 'a' + 10;
	if('A' <= ch && ch <= 'F') return ch - 'A' + 10;
	return -1;
}

inline char hexToChr(int n) {
	if(0 <= n && n <= 9) return n + '0';
	if(10 <= n && n <= 15) return n - 10 + 'a';
	return -1;
}

inline void scan(unsigned int& x) {
	x = 0; char ch = getchar();
	while(!ishex(ch)) ch = getchar();
	while(ishex(ch))  {(x <<= 4) |= chrToHex(ch), ch = getchar();}
}

inline void print(const unsigned int &x, const char &ch) {
	for(int i = 0; i < 4; ++i) putchar(hexToChr((x >> (12 - 4 * i)) & 0xf));
	putchar(ch);
}

struct SPN {
	const int Nr = 4;
	unsigned int S[16] = {0xe, 0x4, 0xd, 0x1, 0x2, 0xf, 0xb, 0x8, 0x3, 0xa, 0x6, 0xc, 0x5, 0x9, 0x0, 0x7};
	unsigned int SInv[16] = {0xe, 0x3, 0x4, 0x8, 0x1, 0xc, 0xa, 0xf, 0x7, 0xd, 0x9, 0x6, 0xb, 0x2, 0x0, 0x5};

	void set_encrypt_round_key(unsigned int *round_key, const unsigned int &key) {
		round_key[0] = (key >> 16) & 0xffff;
		round_key[1] = (key >> 12) & 0xffff;
		round_key[2] = (key >> 8) & 0xffff;
		round_key[3] = (key >> 4) & 0xffff;
		round_key[4] = key & 0xffff;
	}

	void useP(unsigned int &n, const unsigned int &m) {
		n = 0;
		if((m >> 15) & 1) n |= (1<<15);
		if((m >> 11) & 1) n |= (1<<14);
		if((m >> 7) & 1) n |= (1<<13);
		if((m >> 3) & 1) n |= (1<<12);
		if((m >> 14) & 1) n |= (1<<11);
		if((m >> 10) & 1) n |= (1<<10);
		if((m >> 6) & 1) n |= (1<<9);
		if((m >> 2) & 1) n |= (1<<8);
		if((m >> 13) & 1) n |= (1<<7);
		if((m >> 9) & 1) n |= (1<<6);
		if((m >> 5) & 1) n |= (1<<5);
		if((m >> 1) & 1) n |= (1<<4);
		if((m >> 12) & 1) n |= (1<<3);
		if((m >> 8) & 1) n |= (1<<2);
		if((m >> 4) & 1) n |= (1<<1);
		if((m >> 0) & 1) n |= (1<<0);
	}

	void set_decrypt_round_key(unsigned int *round_key, const unsigned int &key) {
		round_key[0] = key & 0xffff;
		useP(round_key[1], (key >> 4) & 0xffff);
		useP(round_key[2], (key >> 8) & 0xffff);
		useP(round_key[3], (key >> 12) & 0xffff);
		round_key[4] = (key >> 16);
	}

	void encrypt(const unsigned int &in, unsigned int &out, const unsigned int *round_key, 
			const unsigned int *S) {
		unsigned int w = in, u, v;
		for(int i = 0; i < Nr - 1; ++i) {
			u = w^round_key[i];
			v = 0;
			(v <<= 4) |= S[(u >> 12) & 0xf];
			(v <<= 4) |= S[(u >> 8) & 0xf];
			(v <<= 4) |= S[(u >> 4) & 0xf];
			(v <<= 4) |= S[u & 0xf];
			useP(w, v);
		}
		u = w^round_key[Nr - 1];
		v = 0;
		(v <<= 4) |= S[(u >> 12) & 0xf];
		(v <<= 4) |= S[(u >> 8) & 0xf];
		(v <<= 4) |= S[(u >> 4) & 0xf];
		(v <<= 4) |= S[u & 0xf];
		out = v ^ round_key[Nr];
	}

	void SPN_Encrypt(const unsigned int &in, unsigned int &out, const unsigned int &key, unsigned int mode) {
		unsigned int round_key[5];
		if(mode == 0) {
			set_encrypt_round_key(round_key, key);
			encrypt(in, out, round_key, S);
		} else {
			set_decrypt_round_key(round_key, key);
			encrypt(in, out, round_key, SInv);
		}
	}
} spn;

void work() {
	unsigned in, out, key;
	scan(key), scan(in);
	spn.SPN_Encrypt(in, out, key, 0);
	print(out, ' ');
	in = out^1;
	spn.SPN_Encrypt(in, out, key, 1);
	print(out, '\n');
}

int main() {
	/*ios::sync_with_stdio(0);
	  cin.tie(0); cout.tie(0);*/
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
	int T = 1; scanf("%d", &T);
	for(int ca = 1; ca <= T; ++ca) {
		work();
	}
//	cerr << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
	return 0;
}

