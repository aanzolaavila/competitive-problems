#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define loopd(i, ii, ff) for(i = ii; i >= ff; i--)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 10000000
#define N 110
#define M 10010
#define INF 1000000000

using namespace std;

map<int, int> mem;
vector<int> nums;

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
	if (mem.count(n) > 0) {
	    ++mem[n];
	} else {
	    mem[n] = 1;
	    nums.push_back(n);
	}
	//printf("----%d %d\n", nums.back(), mem[n] );
    }

    int i;
    loop(i, 0, nums.size()) {
	printf("%d %d\n", nums[i], mem[nums[i]]);
    }

    return 0;
}
