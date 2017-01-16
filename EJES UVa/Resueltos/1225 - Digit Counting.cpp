#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 2000000
#define N 10
#define INF 1000000000

typedef long long int ll;

using namespace std;

int nums[N];

void count(int n) {
    int i;
    while(n) {
	i = n;
	while(i){
	    ++nums[i%10];
	    i /= 10;
	}
	--n;
    }
}

int main() {
    int t, n, i;
    scanf("%d", &t);
    while(t--) {
	scanf("%d", &n);
	memset(nums, 0, sizeof(nums));
	
	count(n);
	printf("%d", nums[0]);
	loop(i, 1, N) {
	    printf(" %d", nums[i]);
	}
	printf("\n");
    }

    return 0;
}
