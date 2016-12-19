#include <cstdio>
#include <cstring>
#include <vector>

#define SZ 1000

using namespace std;

void proc(char * d, char * o) {
    vector<char> sum(strlen(d)+strlen(o));
    
}

int main() {
    int n;
    scanf("%d\n", &n);

    vector<char *> seqs(n, NULL);

    for(int i = 0; i < n; ++i) {
	seqs[i] = new char[SZ];
	scanf("%s\n", seqs[i]);
    }

    char salida[SZ*SZ];
    strcpy(salida, "");
    
    for(int i = 0; i < n; ++i)
	proc(salida, seqs[i] );

    printf("%s\n", salida);

    return 0;
}
