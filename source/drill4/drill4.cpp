#include "std_lib_facilities.h"

constexpr double cm_to_m = 0.01 ;
constexpr double in_to_m = 2.54 * cm_to_m ;
constexpr double ft_to_m = 12.0 * in_to_m ;
const vector<string> legal_units{"cm", "m", "in", "ft" } ;

bool legalUnit(string unit)
{
	bool legal = false ;
	for (auto legal_unit : legal_units)
	{
		if (unit == legal_unit)
		{
			legal = true ; 
		}
	}
	return legal ;

}


double convertometer(double val, string unit)
{
	if ("cm" == unit)
	{
		return val * cm_to_m ;
	}
	else if ("in" == unit)
	{
		return val * in_to_m ;
	}
	else if ("ft" == unit)
	{
		return val * ft_to_m ;
	}
	else	
		return val ;
}

int main(){
	
	cout << "Enter a double values followed by a unit!(Enter a character to exit!)" << "\n";
	double val;
	double valmeter;
	double smallest ;
	double largest;
	string unit=" ";
	double sum;
	int number;
	vector<double>values(0);

	while(cin>> val >>unit){

		if (legalUnit(unit))
		{
			valmeter = convertometer(val, unit);
			cout << val << unit;
			if (unit != "m")
			{
				cout << "(" << valmeter << "m)";
			}
		
			if (number== 0)
			{
				
				smallest= val;
				largest=val;
				cout << "The first value"<<"\n";
			}
			else if(valmeter < smallest)
			{
				cout <<"the smallest so far"<< "\n";
				smallest= valmeter;
			}
			else if (valmeter > largest)
			{
				cout << "the largest so far" << "\n";
				largest = valmeter;
			}
		
			else{
				cout <<"\n";
			}
			values.push_back(valmeter);
			sum+=valmeter;
			number++;
		}
		else{
			cout << "Error: no legal unit! \n";
		}
		
		

	}
	cout << "the smallest: "           << smallest  << "m\n";
	cout << "the largest: "            << largest   << "m\n";
	cout << "the number of values: "   << number    << " \n";
	cout << "the sum of values: "      << sum       << "m\n"; 

	sort(values);
	cout << "the values: \n";
	for (int i = 0; i < values.size(); ++i)	{
		cout << values[i] << ", ";
	}

	return 0;
		
}