#include <bits/stdc++.h>
#define loopd(i, ii, ff) for(i = ii; i >= ff; i--)
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
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

char buff[SZ];
mii c;

int main() {
	uint n;
	int len = 0;
	int mx_bits = 0;

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

		int i = 0;
		while(n) {
			c[i++] += n & 1 ? 1 : 0;
			n >>= 1;
		}

		len++;
	}

	int gamma, epsilon;
	gamma = epsilon = 0;

	for(mii::iterator i = c.begin(); i != c.end(); i++) {
		int e = i->F;
		int v = i->S;

		if(v > (len-v)) {
			gamma |= (1 << e);
		}
	}

	epsilon = (1 << (mx_bits)) -1;
	epsilon &= ~gamma;

	printf("bits: %d\n", mx_bits);
	printf("gamma: %d\n", gamma);
	printf("epsilon: %d\n", epsilon);
	printf("answer: %d\n", epsilon * gamma);

	return 0;
}
