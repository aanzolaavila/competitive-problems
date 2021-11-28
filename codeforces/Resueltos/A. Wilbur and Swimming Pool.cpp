#include <cstdio>

using namespace std;

struct point {
    int x;
    int y;
};

int main() {
    int n;
    scanf("%d", &n);
    point v[4];
    for(int i = 0; i < n; ++i) {
	scanf("%d %d", &v[i].x, &v[i].y);
    }

    int area;

    bool found = false;
    for(int i = 0; i < n && !found; ++i) {
	for(int j = i+1 ; j < n && !found; ++j) {
	    if(v[i].x != v[j].x && v[i].y != v[j].y) {
		found = true;
		area = (v[i].x - v[j].x) * (v[i].y - v[j].y);
		area = area < 0 ? -area : area;
	    }
	}
    }

    if (!found)
	area = -1;

    printf("%d\n", area);

    return 0;
}
