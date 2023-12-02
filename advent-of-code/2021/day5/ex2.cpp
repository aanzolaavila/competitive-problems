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
#define SZ 5
#define BUFFSZ 5000
#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef map<ii, int> inter;

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

int dir(int p1, int p2) {
	return sgn(p2 - p1);
}

ii add(ii a, ii b) {
	return MP(a.X + b.X, a.Y + b.Y);
}

int main() {
	int x1, y1;
	int x2, y2;

	inter ins;

	while(scanf("%d,%d -> %d,%d", &x1, &y1, &x2, &y2) != EOF) {
		// printf("%d,%d -> %d,%d\n", x1, y1, x2, y2);
		ii p1 = MP(x1, y1);
		ii p2 = MP(x2, y2);

		ii d = MP( dir(p1.X, p2.X), dir(p1.Y, p2.Y) );
		// printf("dir: (%d, %d)\n", d.X, d.Y);

		for(ii i = p1; i != add( p2, d ); i = add(i, d)) {
			// printf("dir: (%d, %d)\n", i.X, i.Y);
			ins[i] += 1;
		}
	}

	int c = 0;
	for(inter::iterator i = ins.begin(); i != ins.end(); i++) {
		if(i->S > 1) {
			c++;
		}
	}

	printf("%d\n", c);

	return 0;
}
