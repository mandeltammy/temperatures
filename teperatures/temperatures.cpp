#include <iostream>
using namespace std;

class Celsius {
	double m_c;
public:
	Celsius(double c)
	{
		m_c = c;
	}
	double celsiusToFahrenheit()
	{
		return m_c * 9.0 / 5.0 + 32.0;
	}
	friend ostream &operator<<(ostream & out, Celsius const& c)
	{
		out << "temperature in celsius: " << c.m_c;
		return out;
	}
};

class Fahrenheit {
	double m_f;
public:
	Fahrenheit(double f)
	{
		m_f = f;
	}
	Fahrenheit& operator= (const Celsius& x) 
	{ 
		return Fahrenheit((5.0 / 9)*(m_f - 32));
	}
	double fahrenheitToCelsius()
	{
		return (5.0 / 9)*(m_f - 32);
	}
	friend ostream &operator<<(ostream & out, Fahrenheit const& f)
	{
		out << "temperature in fahrenheit: " << f.m_f;
		return out;
	}
};

int main()
{
	/*Celsius c(38);
	Fahrenheit f(100);
	cout << c.celsiusToFahrenheit() << endl;
	cout << c;
	cout << f.fahrenheitToCelsius() << endl;*/

	Fahrenheit f(100);
	Celsius boil(100);
	Celsius freeze(0);
//	Celsius absoluteZero(−273.15);

//	f = c;

	cout << "\t\tcelsius:\tfahrenheit:\n----------------------------------------------\n";
	cout << "boil temperature:" << boil<<"\t" << boil.celsiusToFahrenheit() << endl;
	cout << "freeze temperature:" << freeze <<"\t"<< freeze.celsiusToFahrenheit() << endl;

	return 0;
}