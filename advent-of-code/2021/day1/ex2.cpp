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
#define SZ 100000
#define INF 1000000000

using namespace std;

int main() {
	int n, s = 0;
	queue<int> q;

	int a = -1, b, c = 0;

	while(scanf("%d", &n) != EOF) {
		q.push(n);
		s += n;

		if(q.size() == 3) {
			b = s;
			if (a != -1) {
				c += b > a ? 1 : 0;
			}
			a = b;

			int u = q.front(); q.pop();
			s -= u;
		}
	}

	assert(q.size() == 2);

	printf("%d\n", c);

	return 0;
}
