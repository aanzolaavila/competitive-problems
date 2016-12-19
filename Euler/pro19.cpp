/*Se te da la siguiente información, pero quizá prefieras investigar por tí mismo.

*El 1 de enero de 1900 fue lunes.
*Treinta días trae noviembre, 
 con abril, junio y septiembre. 
 Los demás treinta y uno, 
 Salvo febrero, solo uno, 
 con veintiocho, lluvia y nieve. 
 Y en bisiestos, veintinueve.
*Un año bisiesto sucede en cualquier año divisible entre 4, pero no si es divisible entre 100, a menos que ese año sea divisible entre 400.
¿Cuántos domingos cayeron en el primer día del mes durante el siglo XX (del 1 de enero de 1901 hasta el 31 de diciembre del 2000)?*/

#include <iostream>
using std::cout;
using std::endl;
using std::fixed;
#include <ctime>
using std::clock;

bool leapYear( int );

int main()
{
    enum meses { ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE };
    
    enum dias { LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO };
    
    unsigned int sum = 0; // Resultado del programa...
    
    int actualDate = MARTES;
    
    for( int year = 1901; year <= 2000; year++ )
    {
        for( int month = ENERO; month <= DICIEMBRE; month++ )
        {
            int monthLimit;
            switch(month)
            {
               case SEPTIEMBRE:
               case ABRIL:
               case JUNIO:
               case NOVIEMBRE:
               monthLimit = 30; break;
               
               case FEBRERO:
               if ( ! leapYear(year) ) monthLimit = 28; else monthLimit = 29;
               break;
               
               default:
               monthLimit = 31; break;
            }
            
            
            for( int day = 1; day <= monthLimit; day++ )
            {
               if( day == 1 && actualDate == DOMINGO ) sum++;
               
               if( actualDate < DOMINGO ) actualDate++; else actualDate = LUNES;
            }
            
        }
    }
    
    cout << sum << endl;
    
    cout << fixed << ((float)clock()) / CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}

bool leapYear( int year )
{
   if ( ( (year%1000) % 100 ) == 0) return ( year % 400 == 0 );
   else 
   if ( year % 4 == 0 ) return true;
   
   return false;
}
