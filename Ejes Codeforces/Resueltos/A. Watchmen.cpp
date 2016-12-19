#include <cstdio>
#include <vector>
#include <cmath> //sqrt
#include <utility> // pair
#include <map>

using namespace std;

typedef map< int, int > mii;
typedef map< pair<int, int>, int > mpii;

int main() {
    int n;
    scanf("%d", &n);
    int x, y;

    mii xs;
    mii ys;

    mpii pairs;
    long long int nps = 0; 
    for(int i = 0; i < n; ++i ) {
	scanf("%d %d", &x, &y);
	nps+=(xs[x]++);
	nps+=(ys[y]++);
	nps-=(pairs[make_pair(x, y)]++);
    }
    printf("%lld\n", nps);

    return 0;
}
