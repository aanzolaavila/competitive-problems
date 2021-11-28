#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define loopd(i, ii, ff) for(i = ii; i >= ff; i--)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) < (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define DEC(v, n) (v = ((v) + (n) - 1) % (n))
#define INC(v, n) (v = ((v) +1) % (n))
#define SZ 2000
#define N 500100
#define INF 1000000000
#define EPS 1e-9

using namespace std;

typedef unsigned long long ll;

ll t[N];
ll a[N];
int n;
ll c;

void merge(ll *a, int low, int mid, int hi) {
    int i;
    loop(i, low, hi) {
	t[i] = a[i];
    }

    int l = low, r = mid;
    loop(i, low, hi) {
	if (l < mid && r < hi) {
	    if (t[l] <= t[r]) {
		a[i] = t[l++];
	    } else {
		a[i] = t[r++];
		c += mid - l;
	    }
	} else if (l == mid) {
	    a[i] = t[r++];
	} else {
	    a[i] = t[l++];
	}
    }
}

void merge_sort(ll *a, int low, int hi) {
    int mid;
    if (low+1 < hi) {
	mid = (hi+low)/2;
	merge_sort(a, low, mid);
	merge_sort(a, mid, hi);
	merge(a, low, mid, hi);
    }
}

int main() {
    ll n;

    int i;
    while(scanf("%ld", &n), n) {
	loop(i, 0, n) {
	    scanf("%ld", a+i);
	}

	c = 0;
	/*loop(i, 0, n) {
	    printf("%ld ", a[i]);
	}
	puts("");*/
	
	merge_sort(a, 0, n);
	
	/*loop(i, 0, n) {
	    printf("%ld ", a[i]);
	}
	puts("");*/
	
	printf("%ld\n", c);
    }

    return 0;
}
