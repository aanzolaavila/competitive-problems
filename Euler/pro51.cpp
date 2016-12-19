/*Mediante la sustitución del 1er caracter de *3, resulta que seis de los nueve valores posibles: 13, 23, 43, 53, 73 y 83, son primos.

Sustituyendo el 3ery 4º caracter de 56**3 con los mismos dígitos, vemos que este número de 5 cifras es el primero que forma siete primos de los diez números generados, creando la familia: 56003, 56113, 56333, 56443, 56663, 56773, y 56993. Por lo tanto 56003, siendo el primer miembro de esta familia, es el menor primo con esta propiedad.

Hallar el menor primo para el cual, reemplazando parte del número (no necesariamente cifras consecutivos) con el mismo dígito, es parte de una familia de ocho primos.*/
#include <iostream>
using std::cout;
using std::endl;
#include "extras\primo.h"
#include "extras\nDigitos.h"

typedef unsigned int uint;

uint prims( int );
void descomp( int, uint*, int );
void recomp( int, uint*, int );

int main()
{       
    for ( int i = 3; true ; i++ )
    {
          if ( ! primo( i ) )
             continue;
             
          if ( prims(i) == 8 )
          {   
              cout << "Encontrado: " << i << endl;
              break;
          }
    }
    
    return 0;
}

void descomp( int num, uint* arreglo, int n )
{
     for ( uint i = n-1; i >= 0; i-- )
     {    
          *(arreglo+i) = static_cast<uint>( num % 10 );
          num /= 10;
     }
}

uint prims( int num )
{
     int n = nDigitos( num );
     int cant = 0;
     
     uint numD[ n ];
     descomp( num, numD, n );
     
     cout << numD;
     
     return 8;
}
