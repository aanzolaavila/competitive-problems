#include <bits/stdc++.h>

using namespace std;

inline int calc(int n, int k) {
    return ( (k >> 1)^k ) & ((1<<(n+1)) -1);
}

int main() {
    int N;
    scanf("%d", &N);

    int n, k;
    while(N--) {
	scanf("%d%d", &n, &k);
	printf("%d\n", calc(n, k));
    }
    
    return 0;
}
