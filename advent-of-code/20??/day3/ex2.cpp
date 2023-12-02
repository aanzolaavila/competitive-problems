#include <bits/stdc++.h>
#define loopd(i, ii, ff) for(i = int( ii ); i >= int( ff ); i--)
#define loop(i, ii, ff) for(i = int( ii ); i < int( ff ); i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define F first
#define S second
#define PB push_back
#define SZ 100
#define INF 1000000000

using namespace std;

typedef map<int, int> mii;
typedef vector<int> vi;

char buff[SZ];

int reps(const vi &v, int k) {
	int c = 0;
	const int pos = (1 << k);

	int i;
	loop(i, 0, v.size()) {
		bool a = ( v[i] & pos ) > 0;
		c += a ? 1 : 0;

		// printf("reps: %d; k: %d, a: %d\n", v[i], k, a);
	}

	return c;
}

vi reduce_oxygen(vi &v, const int bits) {
	// printf("v = {");
	// for(int i = 0; i < int(v.size()); i++) {
		// printf("%d ", v[i]);
	// }
	// printf("}; |v| = %d ; bits = %d\n", int( v.size() ), bits);
	if (bits < 0) {
		return v;
	}

	if(v.size() == 1) {
		return v;
	}

	vi n;
	const int sz = v.size();
	const int c = reps(v, bits);
	// printf("c: %d\n", c);
	if (c >= (sz-c)) {
		int j;
		loop(j, 0, sz) {
			if ( v[j] & (1 << bits) ) {
				n.PB(v[j]);
			}
		}
	} else {
		int j;
		loop(j, 0, sz) {
			if ( ~v[j] & (1 << bits) ) {
				n.PB(v[j]);
			}
		}
	}

	return reduce_oxygen(n, bits-1);
}

vi reduce_co2(vi &v, const int bits) {
	// printf("v = {");
	// for(int i = 0; i < int(v.size()); i++) {
		// printf("%d ", v[i]);
	// }
	// printf("}; |v| = %d ; bits = %d\n", int( v.size() ), bits);
	if (bits < 0) {
		return v;
	}

	if(v.size() == 1) {
		return v;
	}

	vi n;
	const int sz = v.size();
	const int c = reps(v, bits);
	// printf("c: %d\n", c);
	if (c >= (sz-c)) {
		int j;
		loop(j, 0, sz) {
			// printf("~%d ", v[j]);
			if ( ~v[j] & (1 << bits) ) {
				n.PB(v[j]);
			}
		}
	} else {
		int j;
		loop(j, 0, sz) {
			// printf("%d ", v[j]);
			if ( v[j] & (1 << bits) ) {
				n.PB(v[j]);
			}
		}
	}
	// printf("\n");

	return reduce_co2(n, bits-1);
}

int main() {
	uint n;
	int len = 0;
	int mx_bits = 0;
	vi v;

	while(fgets(buff, SZ, stdin) != NULL) {
		n = 0;
		char * ptr = buff;
		int bits = 0;
		while(*ptr != '\n' && *ptr != '\0') {
			char c = *ptr;
			n <<= 1;
			if(c == '1') {
				n |= 1;
			}
			ptr++;
			bits++;
		}

		mx_bits = MAX(bits, mx_bits);
		// printf("%d\n", n);

		v.PB(n);
		len++;
	}

	vi ox = reduce_oxygen(v, mx_bits-1);
	assert(ox.size() == 1);
	printf("oxygen: %d\n", ox[0]);

	vi co = reduce_co2(v, mx_bits-1);
	assert(co.size() == 1);
	printf("co2: %d\n", co[0]);

	printf("answer: %d\n", ox[0] * co[0]);

	return 0;
}
