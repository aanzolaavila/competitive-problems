#include <cstdio>

using namespace std;

int main() {
    int k, n, w;

    scanf("%d %d %d", &k, &n, &w);

    int r = (k*w*(w+1))/2 - n;
    
    printf("%d\n", r > 0? r : 0 );

    return 0;
}
