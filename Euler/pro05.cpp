/*2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <ctime>
using std::clock;

int main()
{
     int i;
     for( i = 10; true; i++)
     {
        if( !(i%2) )
        if( !(i%3) )
        if( !(i%4) )
        if( !(i%5) )
        if( !(i%6) )
        if( !(i%7) )
        if( !(i%8) )
        if( !(i%9) )
        if( !(i%10) )
        if( !(i%11) )
        if( !(i%12) )
        if( !(i%13) )
        if( !(i%14) )
        if( !(i%15) )
        if( !(i%16) )
        if( !(i%17) )
        if( !(i%18) )
        if( !(i%19) )
        if( !(i%20) )
        {
          cout << i << endl;
          break;
        }
     }
     
     cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
     
     return 0;
}
