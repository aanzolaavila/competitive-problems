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
#define X first
#define Y second
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SZ 5000
#define VSZ (1 << 30)
#define IT 256
#define INF 1000000000

using namespace std;

typedef char type;
typedef vector<type> vc;

void calc(vc &v) {
	size_t sz = v.size();
	// if ((sz << 1) >= v.capacity()) {
	// v.reserve(2*sz);
	// }

	int i;
	loop(i, 0, sz) {
		type &val = v[i];
		if (val == 0) {
			v.PB(8);
		}

		if (val > 6) {
			val--;
		} else {
			val = DEC(val, 7);
		}
	}

}

map<int, long long> mem;

long long f(int n) {
	if (mem.count(n) != 0) {
		return mem[n];
	}

	if (n < 0) {
		return 0L;
	}

	if (n <= 10) {
		switch (n) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			return 1L;
		case 7:
		case 8:
		case 9:
		case 10:
			return 2L;
		}
	}

	return mem[n] = f(n-7) + f(n-9);
}

char buff[SZ];

void print(vc &v) {
	// int i;
	// loop(i, 0, v.size()) {
	// printf("%d ", v[i]);
	// }
	printf("\n");
}

void read_fish(vc &fish) {
	fgets(buff, SZ, stdin);
	char * tok = strtok(buff, ",");
	int val;
	while(tok != NULL) {
		sscanf(tok, "%d", &val);
		fish.PB(val);
		tok = strtok(NULL, ",");
	}
}

int main() {
	vc fish;
	read_fish(fish);

	long long sf = f(IT);
	printf("single fish reproduction: %lld\n", sf);

	long long sum = 0L;

	int i;
	loop(i, 0, fish.size()) {
		type &v = fish[i];
		long long fish = f(IT + (6-v));
		sum += fish;
	}

	printf("total: %lld\n", sum);

	return 0;
}
