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
#define IT 80
#define INF 1000000000

using namespace std;

typedef char type;
typedef vector<type> vc;

void calc(vc &v) {
  int sz = v.size();
  v.reserve(2*sz);

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

char buff[SZ];

void print(vc &v) {
	// int i;
	// loop(i, 0, v.size()) {
		// printf("%d ", v[i]);
	// }
	printf("\n");
}

int main() {
	vc v;

	fgets(buff, SZ, stdin);
	char * tok = strtok(buff, ",");
	int val;
	while(tok != NULL) {
		sscanf(tok, "%d", &val);
		v.PB(val);
		tok = strtok(NULL, ",");
	}

	printf("%3d [%5d] ", 0, int(v.size()));
	print(v);
	int i;
	loop(i, 0, IT) {
		calc(v);
		printf("%3d [%5d] ", i+1, int(v.size()));
		print(v);
	}

	printf("%d\n", int( v.size() ));

	return 0;
}
