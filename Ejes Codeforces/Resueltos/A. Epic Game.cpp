#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);

    int actual = a;
    int cd;
    bool simon = false;
    bool finished = false;
    do {
	cd = gcd(actual, n);
	if (n >= cd) {
	    simon = !simon;
	    n -= cd;
	} else {
	    finished = true;
	}
	
	actual = actual == a ? b : a;
    } while(!finished);

    printf("%d\n", simon ? 0 : 1);

    return 0;
}
