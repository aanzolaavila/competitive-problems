#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 1010
#define N 30
#define INF 1000000000

using namespace std;

int nums[SZ];

int f(int n, int sz) {
    int lim = lower_bound(nums, nums+sz, n) - nums;
    lim = RANGE(lim, 1, sz);


    int sum = abs(nums[0] + nums[1]);
    int r = sum;
    int min = abs(r-n);
    for(int i = 0; i < lim; i++) {
	for(int j = i+1; j < lim+1; j++) {
	    sum = nums[i] + nums[j];
	    if (abs(sum-n) < min) {
		min = abs(sum-n);
		r = sum;
	    }
	}
    }

    return r;
}

int main() {
    int t = 1;
    int n, m, i, q;
    while(scanf("%d", &n), n) {
	printf("Case %d:\n", t++);
	memset(nums, INF, sizeof(nums));
	loop(i, 0, n) {
	    scanf("%d", nums+i);
	}

	sort(nums, nums+n);

	scanf("%d", &m);
	loop(i, 0, m) {
	    scanf("%d", &q);
	    printf("Closest sum to %d is %d.\n", q, f(q, n));
	}
    }

    return 0;
}    
