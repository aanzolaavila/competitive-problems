/*A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <ctime>
using std::clock;

int main()
{
   for(int c=1; c < 1000; c++)
   {
      for(int b=1; b < 1000; b++)
      {
         for(int a=1; a < 1000; a++)
         {
            if( (a+b+c) == 1000)
            if( a < b < c )
            if( ((a*a) + (b*b)) == (c*c) )
            {cout << a*b*c << endl; 
            cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
            return 0;}
         }
      }
   }
}
