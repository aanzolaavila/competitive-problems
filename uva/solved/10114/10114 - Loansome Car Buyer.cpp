#include <bits/stdc++.h>
#define loop(i, ii, ff) for(i = ii; i < ff ; ++i)
#define SZ 110
using namespace std;

int m, n;
double dp, loan;
queue< pair<int, double> > q;

int calc() {
    int mon = 0;
    pair<int, double> ac = q.front();
    q.pop();
    double debt = loan;
    double car = (loan + dp)*(1.0-ac.second);
    
    while(debt >= car) {
	++mon;
	//printf("%d %lf ", ac.first, ac.second );
	//printf("%.3lf, %.3lf\n", debt, car);
	if (!q.empty() && q.front().first == mon) {
	    ac = q.front();
	    q.pop();
	}
	debt -= loan / m;
	car *= 1-ac.second;
    }
    //printf("%d %lf ", ac.first, ac.second );
    //printf("%.3lf, %.3lf\n", debt, car);
    
    return mon;
}

int main() {
    int i, r;
    int dm;
    double dr;
    while(scanf("%d %lf %lf %d", &m, &dp, &loan, &n), m > 0) {
	loop(i, 0, n) {
	    scanf("%d %lf",&dm, &dr);
	    q.push(make_pair(dm, dr));
	}
	r = calc();
	if (r == 1) printf("1 month\n");
	else printf("%d months\n", r);

	while(!q.empty()) q.pop();
    }

    return 0;
}
