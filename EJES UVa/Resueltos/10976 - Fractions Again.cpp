#include <bits/stdc++.h>

#define calc(k, x) (k*x / (x-k))
#define test(k, x, y) ( (x-k)*y == k*x )

using namespace std;

vector< pair< int, int> > values;

int k, x, y;

int main() {
    while (scanf("%d\n", &k) != EOF) {
	for(x = k+1 ; (y = calc(k, x)) >= x ; ++x) {
	    if (test(k, x, y))
		values.push_back( make_pair(x, y) );
	}

	printf("%li\n", values.size());
	for(int i = 0; i < values.size(); ++i) {
	    printf("1/%d = 1/%d + 1/%d\n", k, values[i].second, values[i].first);
	}

	values.clear();
    }

    return 0;
}
