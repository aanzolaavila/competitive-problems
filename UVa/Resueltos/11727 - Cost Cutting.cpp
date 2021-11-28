#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
#include <cstring>
using std::string;
using std::to_string;

int main()
{
	string SALIDA = "";

	while( true )
	{
		int duration, n_dep_records;
		float down_payment, loan_amount;
		cin >> duration >> down_payment >> loan_amount >> n_dep_records;
		if( duration < 0 || (n_dep_records < 0 && n_dep_records <= duration) || down_payment < 0.0 || loan_amount < 0.0 )
		{
			SALIDA += "\0";
			break;
		}

		double actual_value = loan_amount + down_payment;
		float dep_records[duration+1];
		dep_records[0] = 0.0;
		for(int i = 1; i <= duration ; i++)
			dep_records[i] = -1.0;

		for(int i = 1 ; i <= n_dep_records ; i++)
		{
			int pos;
			float temp;
			cin >> pos >> temp;
			if( (0 <= pos <= duration) && (temp >= 0.0) )
				dep_records[pos] = temp;
		}

		int months = 0;

		float last = dep_records[0];
		for (int i = 0; /*actual_value >= loan_amount*/ true ;)
		{
			cout << actual_value << " ";
			if( (dep_records[i] != -1.0) )
			{
				actual_value -= actual_value * dep_records[i];
				last = dep_records[i];
			}
			else
				actual_value -= actual_value * last;

			cout << loan_amount << " ";
			
			if(i > 0)
				loan_amount -= down_payment;

			cout << months << "\n";

			months++;

			if( actual_value > loan_amount )
				break;

			if( i == duration )
				continue;
			else
				i++;
		}
		SALIDA += to_string(months);
		if( months != 1 )
			SALIDA += " months\n";
		else
			SALIDA += " month\n";
	}
	cout << SALIDA << endl;
	return 0;
}