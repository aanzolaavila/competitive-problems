#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

bool is_distinct(int n) {
    set<int> c;

    while(n) {
	if ( c.count(n % 10) != 0 )
	    return false;
	c.insert(n % 10);
	n /= 10;
    }

    return true;
}

inline int next(int n) {
    while(! is_distinct(++n));

    return n;
}
	
int main() {
    int y;
    scanf("%d", &y);

    printf("%d\n", next(y));

    return 0;
}
