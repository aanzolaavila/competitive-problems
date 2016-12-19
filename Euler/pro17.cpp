/*If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.*/

#include <iostream>
using std::cout;
using std::endl;
using std::string;

int determine( int );
int oneNUMBER( int );
int twoNUMBER( int );
int threeNUMBER( int );

enum littleNums { ONE = 1, TWO = 3, THREE = 5, FOUR = 4, FIVE = 4, SIX = 3, SEVEN = 5, EIGHT = 5, NINE = 4, TEN = 3, ELEVEN = 6, TWELVE = 6, THIRTEEN = 8, FOURTEEN = 8, FIFTEEN = 7, SIXTEEN = 7, SEVENTEEN = 9, EIGHTEEN = 8, NINETEEN = 8 };

enum bigNums { TWENTY = 6, THIRTY = 6, FORTY = 5, FIFTY = 5, SIXTY = 5, SEVENTY = 7, EIGHTY = 6, NINETY = 6, HUNDRED = 7, THOUSAND = 8 };

int main()
{
   unsigned long long sum = 0; // Resultado del programa
   
   const int limit = 5;
   for( int i = 1; i <= limit; i++ )
   {
       sum += determine( i );
   }
   
   cout << sum << endl;
   
   return 0;
}

int determine( int n )
{
      if( n < 20 )
      return oneNUMBER( n );
      
      if(20 <= n < 100 )
      return twoNUMBER( (n - (n%10)) /10 ) + oneNUMBER( n % 10 );
      
      if( 100 <= n < 1000 )
      return threeNUMBER( (n - (n%100)) / 100) + twoNUMBER( (n - (n%10)) /10 ) + oneNUMBER( n % 10 ) + 3/*AND*/;
      if ( n == 1000)
      return ONE + THOUSAND;
}

int oneNUMBER( int n )
{
   switch(n)
   {
      case 1:
      return ONE;
      
      case 2:
      return TWO;
      
      case 3:
      return THREE;
      
      case 4:
      return FOUR;
      
      case 5:
      return FIVE;
      
      case 6:
      return SIX;
      
      case 7:
      return SEVEN;
      
      case 8:
      return EIGHT;
      
      case 9:
      return NINE;
      
      case 10:
      return TEN;
      
      case 11:
      return ELEVEN;
      
      case 12:
      return TWELVE;
      
      case 13:
      return THIRTEEN;
      
      case 14:
      return FOURTEEN;
      
      case 15:
      return FIFTEEN;
      
      case 16:
      return SIXTEEN;
      
      case 17:
      return SEVENTEEN;
      
      case 18:
      return EIGHTEEN;
      
      case 19:
      return NINETEEN;
   }
}

int twoNUMBER( int n )
{
   switch(n)
   {
      case 2:
      return TWENTY;
      
      case 3:
      return THIRTY;
      
      case 4:
      return FORTY;
      
      case 5:
      return FIFTY;
      
      case 6:
      return SIXTY;
      
      case 7:
      return SEVENTY;
      
      case 8:
      return EIGHTY;
      
      case 9:
      return NINETY;
   }
}

int threeNUMBER( int n )
{
   int num = 0;
   switch(n)
   {
      case 1:
      num = ONE;
      
      case 2:
      num = TWO;
      
      case 3:
      num = THREE;
      
      case 4:
      num = FOUR;
      
      case 5:
      num = FIVE;
      
      case 6:
      num = SIX;
      
      case 7:
      num = SEVEN;
      
      case 8:
      num = EIGHT;
      
      case 9:
      num = NINE;
   }
   
   return num + HUNDRED;
}
