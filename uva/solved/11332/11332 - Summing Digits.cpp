#include <bits/stdc++.h>
#define SZ 2000000010
using namespace std;

int calc(int n) {
    int sum = 0;
    int c = n;
    do {
	sum = 0;
	while(c) {
	    sum += c % 10;
	    c /= 10;
	}
	c = sum;
    } while(sum >= 10);
    
    return sum;
}

int main() {
    int n;
    while(scanf("%d", &n), n) {
	printf("%d\n", calc(n));
    }

    return 0;
}
