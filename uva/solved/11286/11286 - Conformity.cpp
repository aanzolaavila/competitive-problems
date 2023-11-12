#include <bits/stdc++.h>
#define loop(i, a, b) for(i = a; i < b; i++)
#define F first
#define S second

using namespace std;

typedef unsigned long long large;
map<large, int> memo;
typedef map<large, int>::iterator it;


int main() {
    int n, tmp, i;
    int tmparr[5];
    
    while(scanf("%d", &n), n) {
	// puts("");
	memo.clear();
	int max_reps = 0;
	while(n--) {
	    loop(i, 0, 5) {
		scanf("%d", &tmparr[i]);
	    }
	    
	    large k = 0;
	    sort(tmparr, tmparr +5);
	    loop(i, 0, 5) {
		k += pow(100, 5-i-1) * tmparr[i];
	    }

	    max_reps = max(max_reps, ++memo[k]);
	}

	int reps = 0;
	for(it i = memo.begin(); i != memo.end(); i++) {
	    // printf("%llu -> %d\n", i->F, i->S);
	    if (i->S == max_reps)
		reps++;
	}

	printf("%d\n", reps * max_reps);
    }
    
    return 0;
}
