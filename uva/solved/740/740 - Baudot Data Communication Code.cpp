#include <bits/stdc++.h>

#define loop(it, x, y) for(it = x; it < y ; ++it)
#define SZ 40
#define DOWN 27
#define UP 31

using namespace std;

char up[SZ];
char down[SZ];
char message[81];
char tras[17];

int btoi(char * b, int l) {
    int n = 0, i;
    loop(i, 0, l) {
	n += (b[i] == '1'? 1 : 0) << (l-i-1);
    }
    return n;
}

void traslate() {
    bool d = true;
    int len = strlen(message);
    int i,j = 0,pos;
    for(i = 0; i < len; i += 5) {
	switch(pos = btoi(message + i, 5)) {
	case DOWN:
	    d = true;
	    break;
	case UP:
	    d = false;
	    break;
	default:
	    tras[j++] = d ? down[pos] : up[pos];
	}
    }

    tras[j] = '\0';
}

int main() {
    fgets(down, sizeof(down), stdin);
    fgets(up, sizeof(up), stdin);
    while(scanf("%s\n", message) != EOF) {
	traslate();
	printf("%s\n", tras );
    }

    return 0;
}
