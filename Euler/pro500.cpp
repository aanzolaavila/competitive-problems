/* The number of divisors of 120 is 16.
In fact 120 is the smallest number having 16 divisors.

Find the smallest number with 2^500500 divisors.
Give your answer modulo 500500507.*/

#include <cstdio>
#include <cmath>
#include <algorithm>
#include "extras\primo.h"
#include "extras\prod.h"
using namespace std;

const long modulo = 500500507;
const int n = 4;

unsigned int PRIMOS[n];
int EXPONENTES[n];

int main()
{
	for(int i = 0, actual = 2 ; i < n ; actual++)
		if(primo(actual))
			PRIMOS[i++] = actual;
	
	fill_n(EXPONENTES, n, 1);
	
	
}