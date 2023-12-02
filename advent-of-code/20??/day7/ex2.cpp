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
#define INF 1000000000

using namespace std;

typedef vector<int> vi;

char buff[SZ];

void read_nums(vi &v) {
	fgets(buff, SZ, stdin);
	char * tok = strtok(buff, ",");
	int val;
	while(tok != NULL) {
		sscanf(tok, "%d", &val);
		v.PB(val);
		tok = strtok(NULL, ",");
	}
}

int cost(int d) {
  d = abs(d);
  return d*(d+1)/2;
}

int main() {
	vi v;
	read_nums(v);

	pair <int, int> best = MP(-1, INF);

	int mn = INF, mx = -INF;

	int i;
	loop(i, 0, v.size()) {
		int &val = v[i];
		mn = min(mn, val);
		mx = max(mx, val);
	}


	int posi;
	loop(posi, mn, mx +1) {
		int s = 0;
		loop(i, 0, v.size()) {
			s += cost(posi - v[i]);
		}

		if (best.S > s) {
			best = MP(posi, s);
		}
	}

	printf("%d\n", best.S);

	return 0;
}
