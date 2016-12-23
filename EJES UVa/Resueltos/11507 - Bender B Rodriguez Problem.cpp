#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define INRANGE(v, min, max) ((min) <= (v) && (v) <= (max))
#define RANGE(v, min, max) MAX(MIN((v), (max)), (min))
#define SZ 200020
#define INF 1000000000

struct vec {
    int x, y, z;
    vec(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
    }

    void set(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
    }

    vec * inv() {
	return new vec(-x, -y, -z);
    }

    double norm() {
	return sqrt(x*x + y*y + z*z);
    }

    bool neg() {
	return x < 0 || y < 0 || z < 0;
    }

    vec * cross(vec b) {
	return new vec( y*b.z - z*b.y,
			z*b.x - x*b.z,
			x*b.y - y*b.x);
    }

    void print() {
	printf("[x=%d, y=%d, z=%d]\n", x, y, z);
    }
};

vec y(0,0,1);
vec z(0,-1,0);
vec null(0,0,0);

inline void rem(char * s, char * d) {
    *d = '\0';
    char * tmp = strtok(s, " \n");
    while(tmp != NULL) {
	strcat(d, tmp);
	tmp = strtok(NULL, " \n");
    }
}

int main() {
    int n;
    int i;
    char s, eje;
    char str[SZ];
    char parse[SZ];
    char * tmp;
    vec v(1, 0, 0);
    vec * u = NULL;
    while(scanf("%d\n", &n), n) {
	v.set(1,0,0);
	fgets(str, SZ, stdin);
	rem(str, parse);
	tmp = parse;
	loop(i, 0, n-1) {
	    sscanf(tmp, "%c%c", &s, &eje);
	    tmp += 2;
	    switch(eje) {
	    case 'y':
		u = &y;
		break;
	    case 'z':
		u = &z;
		break;
	    default:
		u = &null;
	    }

	    //printf("<<%c%c>>\n", s, eje);

	    vec * c;
	    if (s == '+') {
		c = u;
	    } else {
		c = u->inv();
	    }

	    c = c->cross(v);
	    if (c->norm() != 0) {
		//v.print();
		v = *c;
		//v.print();
	    }

	    delete c;
	    //tmp = strtok(NULL, " ");
	}

	//v.print();
	
	printf("%c", v.neg() ? '-' : '+');
	char r;
	if (v.x != 0) {
	    r = 'x';
	} else if (v.y != 0) {
	    r = 'y';
	} else {
	    r = 'z';
	}
	printf("%c\n", r);
    }

    // y.print();
    // z.print();
    // null.print();

    return 0;
}
