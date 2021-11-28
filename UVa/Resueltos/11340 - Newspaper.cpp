#include <bits/stdc++.h>
#define SZ 10500
#define CHARS 512
#define loop(i, a, b) for(i = a; i < b; i++)

using namespace std;

typedef unsigned int uint;

uint chars[CHARS];
char in[SZ];

uint value() {
    char * ptr = in;
    uint sum = 0;
    while(*ptr != '\0') {
	sum += chars[*ptr+128];
	ptr++;
    }

    return sum;
}

int main() {
    int N;
    scanf("%d", &N);

    int K, M, i, temp;
    uint sum;
    char c;
    while(N--) {
	scanf("%d\n", &K);
	memset(chars, 0, sizeof chars);
	loop(i, 0, K) {
	    scanf("%c%d\n", &c, &temp);
	    // printf("%c %d\n", c, temp);
	    chars[c+128] = temp;
	}

	scanf("%d\n", &M);
	sum = 0;
	loop(i, 0, M) {
	    fgets(in, SZ, stdin);
	    sum += value();
	}

	printf("%.2lf$\n", ((double)sum) / 100.0);
    }
    
    return 0;
}
