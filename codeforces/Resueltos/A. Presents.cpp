#include <cstdio>
#include <vector>

using namespace std;


int main() {
    int n;
    scanf("%d", &n);

    vector<int> v(n, 0);
    
    for(int i = 0; i < n; ++i) {
	int c;
	scanf("%d", &c);
	v[c-1] = i+1;
    }

    for(int i = 0; i < n; ++i) {
	printf("%d ", v[i]);
    }

    printf("\n");

    return 0;
}
