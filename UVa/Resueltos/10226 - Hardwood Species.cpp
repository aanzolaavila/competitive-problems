#include <bits/stdc++.h>
#define SZ 60

using namespace std;

unordered_map<string, int> memo;
set<string> names;
char in[SZ];

typedef set<string>::iterator it;

int main() {
    int t;
    scanf("%d\n", &t);

    bool f = false;
    while(t--) {
	if (f) puts("");
	f = true;
	memo.clear();
	bool flag = false;
	int sz = 0;
	do {
	    fgets(in, SZ, stdin);
	    // printf("DEB %s\n", in);
	    int len = strlen(in);
	    if (len == 0 || in[0] == '\n' || feof(stdin)){
		// printf("FIN\n");
		break;
	    }
	    in[--len] = '\0';
	    names.insert(in);
	    memo[in]++;
	    sz++;
	} while(!flag);

	for(it i = names.begin(); i != names.end(); i++){
	    if (memo[*i] > 0) {
		printf("%s %.4lf\n", (*i).c_str(), memo[*i] / (double)sz * 100.0);
	    }
	}
    }
    
    return 0;
}
