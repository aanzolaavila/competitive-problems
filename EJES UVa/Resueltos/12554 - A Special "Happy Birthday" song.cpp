#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x) MAX((x), -(x))
#define SZ 110

using namespace std;

const char *str = "Happy birthday to you! Happy birthday to you! Happy birthday to Rujia! Happy birthday to you!!!";

int main() {
    int i, n;
    scanf("%d\n", &n);
    char p[n][SZ];

    loop(i, 0, n) {
	scanf("%s", p[i]);
    }

    const char * sep = " !";
    char *s = new char[strlen(str)+10];
    i = 0;
    bool c = false;
    strcpy(s, str);
    char * w = strtok(s, sep);
    while(w != NULL) {
	printf("%s: %s\n", p[i], w);
	i = (i+1) % n;
	w = strtok(NULL, sep);
	c = c || i == 0;
	if (!c && w == NULL) {
	    strcpy(s, str);
	    w = strtok(s, sep);
	}
    }

    return 0;
}
