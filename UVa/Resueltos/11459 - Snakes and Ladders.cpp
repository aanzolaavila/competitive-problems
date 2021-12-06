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
#define PB push_back
#define INF 1000000000

using namespace std;

typedef vector<int> vi;

int a, b, c;
map<int, int> snakes;
map<int, int> pos;

void print_pos() {
	int i;
	loop(i, 0, a) {
		printf("Position of player %d is %d.\n", i+1, pos[i]+1);
	}
}

void calc() {
	int rolls, player = 0;
	int new_pos;
	while(c-- > 0) {
		scanf("%d", &rolls);

		new_pos = RANGE(pos[player] + rolls, 0, 99);

		if(snakes.count(new_pos)) {
			new_pos = snakes[new_pos];
		}

		pos[player] = new_pos;

		if(new_pos == 99) {
			// game is over
			break;
		}

		player = INC(player, a);
	}

	while(c-- > 0) {
		scanf("%*d");
	}

	print_pos();
}

int main() {
	int n;
	scanf("%d", &n);

	while(n--) {
		snakes.clear();
		pos.clear();
		scanf("%d%d%d", &a, &b, &c);

		while(b--) {
			int u, v;
			scanf("%d%d", &u, &v);
			snakes[u-1] = v-1;
		}

		calc();
	}

	return 0;
}
