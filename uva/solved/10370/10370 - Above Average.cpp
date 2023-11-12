#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; ++i)
#define SZ 1010

using namespace std;

int cals[SZ];

inline double avg(const int &n) {
    int i;
    double a = 0.0;
    loop(i, 0, n) a += (double)cals[i];
    return a / (double)n;
}

inline double calc(const int &n) {
    double a = avg(n), c = 0.0;
    int i;
    loop(i, 0, n) c += cals[i] > a ? 1.0 : 0.0;
    return c*100.0/(double)n;
}

int main() {
    int c, n, i, j;
    
    scanf("%d", &c);
    loop(i, 0, c) {
	scanf("%d", &n);
	loop(j, 0, n){
	    scanf("%d", cals+j);
	}

	printf("%.3f%%\n", calc(n));
    }

    return 0;
}
