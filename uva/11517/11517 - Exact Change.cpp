#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 110
#define INF 1000000000

using namespace std;

int nums[SZ];
int n, price;

typedef pair<int, int> pii;

int mem[100][10001][2];

pii calc(int i, int target) {
    if (mem[i][target][0] != -1) {
	return make_pair(mem[i][target][0], mem[i][target][1]);
    }

    if (i < n && target > 0) {
	return target <= nums[i] ? make_pair( (mem[i][target][0] = nums[i]) , (mem[i][target][1] = 1)) : make_pair(INF, 0);
    }

    if (target <= 0) {
	return make_pair(0, 0);
    }

    if (i == n) {
	return make_pair(INF, INF);
    }

    pii a, b;
    a = calc(i+1, target - nums[i]);
    a.first += nums[i];
    b = calc(i+1, target);

    int c;
    if (a.first < b.first) {
	c = a.second +1;
    } else if (a.first > b.first) {
	c = b.second;
    } else {
	c = a.second < b.second ? a.second +1 : b.second;
    }

    mem[i][target][0] = min(a.first, b.first);
    mem[i][target][1] = c;
    return make_pair( mem[i][target][0], mem[i][target][1]);
}

int main() {
    int t;
    int i, j;
    scanf("%d", &t);

    while(t--) {
	scanf("%d%d", &price, &n);

	loop(i, 0, n) {
	    scanf("%d", nums+i);
	}

	loop(i, 0, 100) {
	    loop(j, 0, 10001) {
		mem[i][j][0] = mem[i][j][1] = -1;
	    }
	}

	pii r = calc(0, price);

	printf("%d %d\n", r.first, r.second);
    }

    return 0;
}
