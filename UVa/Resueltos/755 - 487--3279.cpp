#include <bits/stdc++.h>
#define loop(i, a, b) for(i = a; i < b; i++)
#define INRANGE(v, mn, mx) ((mn) <= (v) && (v) <= (mx))
#define SZ 1000
#define F first
#define S second

using namespace std;

char in[SZ];
map<int, int> reps;

inline int let(char c) {
  switch(c) {
  case 'A':
  case 'B':
  case 'C':
    return 2;
  case 'D':
  case 'E':
  case 'F':
    return 3;
  case 'G':
  case 'H':
  case 'I':
    return 4;
  case 'J':
  case 'K':
  case 'L':
    return 5;
  case 'M':
  case 'N':
  case 'O':
    return 6;
  case 'P':
  case 'R':
  case 'S':
    return 7;
  case 'T':
  case 'U':
  case 'V':
    return 8;
  case 'W':
  case 'X':
  case 'Y':
    return 9;
  }
}

int conv() {
  char *ptr = in;
  int s = 0;
  while(*ptr != '\0') {
    if (INRANGE(*ptr, 'A', 'Y') && *ptr != 'Q') {
      *ptr = let(*ptr) + '0';
    }
    
    if (INRANGE(*ptr, '0', '9')) {
      s *= 10;
      s += *ptr - '0';
    }
    ptr++;
  }

  return s;
}

inline void read() {
  while(fgets(in, SZ, stdin), strlen(in) < 7);
}

char tmp[SZ];

void print(int n) {
  sprintf(tmp, "%3d-%4d", n / 10000, n % 10000);
  char * ptr = tmp;
  while(*ptr != '\0') {
    if (*ptr == ' ') *ptr = '0';
    ptr++;
  }
  printf("%s", tmp);
}

int main() {
  int t, n, i;
  scanf("%d", &t);

  while(t--) {
    reps.clear();
    scanf("%d\n", &n);
    loop(i, 0, n) {
      read();
      //printf("%s\n", in);
      reps[conv()]++;
    }
    //fgets(in, SZ, stdin);

    bool r = false;
    for(map<int,int>::iterator i = reps.begin(); i != reps.end() ; i++) {
      if (i->S > 1) {
	r = true;
	print(i->F);
	printf(" %d\n", i->S);
      }
    }

    if (!r) puts("No duplicates.");

    if (t != 0) puts("");
  }

  return 0;
}
