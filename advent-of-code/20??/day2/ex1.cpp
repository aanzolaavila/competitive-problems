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
#define SZ 100
#define INF 1000000000

using namespace std;

char buff[SZ];

int main() {
	char act[SZ];
	int n;

	int x, y;
	x = y = 0;

	while(fgets(buff, SZ, stdin) != NULL) {
		sscanf(buff, "%s %d", act, &n);

		// printf("%s %d\n", act, n);
		if(strcmp(act, "forward") == 0) {
			x += n;
		} else if (strcmp(act, "down") == 0) {
			y += n;
		} else if (strcmp(act, "up") == 0) {
			y -= n;
		}

		// printf("%d %d\n", x, y);
	}

	printf("%d\n", x*y);

	return 0;
}
