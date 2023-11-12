#include <iostream>
using std::cout;
using std::cin;
#include <cstring>
using std::string;

int main()
{
	string SALIDA = "";
	int k, n, m;
	while (0 < k <= 1000)
	{
		cin >> k;
		if( ! ( 0 < k <= 1000 ) || k == 0 )
		{
			SALIDA += "\0";
			cout << SALIDA;
			return 0;
		}
		
		cin >> n >> m;
		
		if ( ! ( (-10000 < n < 10000) && (-10000 < m < 10000) ) )
			return 1;
		
		int xy[k][2];
		
		for( int i = 0 ; i < k ; i++ )
		{
			cin >> xy[i][0] >> xy[i][1];
			int x = xy[i][0];
			int y = xy[i][1];
			if ( ! ( (-10000 < x < 10000) && (-10000 < y < 10000) ) )
				return 1;
		}
		
		for( int i = 0 ; i < k ; i++ )
		{
			if( xy[i][0] == n || xy[i][1] == m )
			{
				SALIDA += "divisa\n";
				continue;
			}

			int cuadrante = 1;

			if( xy[i][0] < n )
				cuadrante = 2;
			if ( xy[i][1] < m )
				if( cuadrante == 2 )
					cuadrante = 3;
				else
					cuadrante = 4;

			switch( cuadrante )
			{
				case 1:
					SALIDA += "NE\n";
					break;
				case 2:
					SALIDA += "NO\n";
					break;
				case 3:
					SALIDA += "SO\n";
					break;
				case 4:
					SALIDA += "SE\n";
					break;
			}
		}

	}
	
	return 0;	
}