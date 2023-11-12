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
#define SZ 110
#define INF 1000000000

using namespace std;

typedef vector<int> vi;

int n, m;
char grid[SZ][SZ];

int count(int x, int y) {
	int i, j, c = 0;
	loop(i, x-1, x+2) {
		loop(j, y-1, y+2) {
			if(INRANGE(i, 0, n-1) && INRANGE(j, 0, m-1)) {
				if (grid[i][j] == '*') {
					c++;
				}
			}
		}
	}

	return c;
}

void calc() {
	int i, j, c;
	loop(i, 0, n) {
		loop(j, 0, m) {
			if (grid[i][j] == '*') {
				continue;
			}
			c = count(i, j);
			grid[i][j] = c + '0';
		}
	}

	loop(i, 0, n) {
		printf("%s\n", grid[i]);
	}
}

int main() {
	int c = 1;
	bool fc = true;
	while(scanf("%d%d\n", &n, &m), (n | m) != 0) {
		if (!fc) {
			printf("\n");
		}
		fc = false;

		int i;
		loop(i, 0, n) {
			scanf("%s\n", grid[i]);
			assert(((int) strlen(grid[i] )) == m);
		}

		printf("Field #%d:\n", c++);
		calc();
	}

	return 0;
}
