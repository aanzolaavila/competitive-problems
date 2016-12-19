/*Starting in the top left corner of a 22 grid, there are 6 routes (without backtracking) to the bottom right corner.


How many routes are there through a 2020 grid?*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <iomanip>
using std::setprecision;
#include <cmath>
using std::pow;
#include <ctime>
using std::clock;

double fact( int n )
{
    double resultado = 1.0;
 
    for ( int i = 1 ; i <= n ; ++i ) resultado = resultado * static_cast <double>( i );
 
    return resultado;
 
}

int main()
{
    int n = 20; // n * n grid
    
    double r = fact( 2*n ) / ( pow( fact( n ), 2 ) ) ;
    
    cout << fixed << setprecision(0) << r << endl;
    
    cout << setprecision(6) << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}
