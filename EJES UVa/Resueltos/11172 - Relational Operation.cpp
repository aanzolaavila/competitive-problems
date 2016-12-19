#include <iostream>
using std::cout;
using std::cin;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	int t;
	cin >> t;
	if( ! (t < 15) )
		return 1;
	double matriz[t][2];
	
	for( int i = 0; i < t ; i++)
	{
		cin >> matriz[i][0] >> matriz[i][1];
	}
	
	for( int i = 0 ; i < t ; i++)
	{
		if (matriz[i][0] == matriz[i][1])
			cout << "=";
		else
			if (matriz[i][0] < matriz [i][1])
				cout << "<";
			else
				cout << ">";
		cout << "\n";
	}
	
	return 0;
}
