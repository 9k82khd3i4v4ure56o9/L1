#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

double f(double x)
{
	return 0.1 * pow(x, 2) - x * log(x);
}

double a = 1, b = 2;
double e = 0.000001;

int main()
{
	setlocale(LC_ALL, "RUS");
	cout.precision(8);

	double fa = f(a);

	if (fa * f(b) >= 0)
	{
		cout << "Решения нет на отрезке ab." << endl;
		return 0;
	}

	double x = (a + b) / 2;
	cout << "x1 = " << x << endl;

	double previous_x = a;
	for (int n = 2; abs(x - previous_x) >= e; n++)
	{
		if (fa * f(x) > 0)
		{
			a = x;
		}
		else
		{
			b = x;
		}

		previous_x = x;
		x = (a + b) / 2;
		cout << 'x' << n << " = " << x << endl;

	}

	cout << "Корень: x = " << x << endl;
	return 0;

}