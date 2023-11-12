#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff ; i++)
#define SZ 1500

using namespace std;

typedef pair< pair<int, int> , string> is;
typedef vector< is > vii;

vii seq;

void f() {
  int i, j;
  const char *p, *q;
  loop(i, 0, seq.size()) {
    p = seq[i].second.c_str();
    while(*(p+1) != '\0') {
      q = p+1;
      while(*q != '\0') {
	if (*p > *q) {
	  seq[i].first.second++;
	}
	q++;
      }
      ++p;
    }
  }
}

bool c(const is &a, const is &b) {
  return a.first.second < b.first.second ||
			  (a.first.second == b.first.second &&
			   a.first.first < b.first.first);
}

int main() {
  int M;
  int n, m, i;
  char in[SZ];
  bool first = true;

  scanf("%d", &M);
  while(M--) {
    if(!first) {
      printf("\n");
    }
    first = false;
    seq.clear();
    scanf("%d%d", &n, &m);
    loop(i, 0, m) {
      scanf("%s\n", in);
      seq.push_back(make_pair( make_pair(i, 0) , string(in)));
    }

    f();
    sort(seq.begin(), seq.end(), c);

    loop(i, 0, m) {
      //printf("%d ", seq[i].first);
      puts(seq[i].second.c_str());
    }
  }

  return 0;
}
