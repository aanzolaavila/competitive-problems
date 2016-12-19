#include <cstdio>
#include <algorithm>

using namespace std;

void cycle(char * q, int n) {
    for(int i = 0; i < n-1; ++i) {
	if (q[i] == 'B' && q[i+1] == 'G') {
	    swap(q[i], q[i+1]);
	    ++i;
	}
    }
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    char queue[n+1];
    scanf("%s", queue);

    for(int i = 0; i < t; ++i)
	cycle(queue, n);

    printf("%s\n", queue);

    return 0;
}
