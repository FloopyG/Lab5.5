
#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
	return sin( x ) - cos( x );
}



double calcX(double a, double b, const double eps, double m, double i) {
	double x;
	i++;
	m = (a + b) / 2;
	if (func(m) == 0) {
		return x = m;
	} else
		if (func(a) * func(m) < 0) {
			b = m;
			if (abs(b - a) <= abs(eps))
				cout << a << " <=" << " x " << "<= " << b << " " << i << endl;
			else
				return calcX(a, b, eps, b, i);
		}
		else {
			a = m;
			if (abs(b - a) <= abs(eps))
				cout << a << " <= " << " x " << " <= " << b << " " << i <<  endl;
			else
				return calcX(a, b, eps, a, i);
			}
}

int main()
{
	double a, b, eps;


	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	cout << "eps = "; cin >> eps;

	if (a > b || func(a) * func(b) > 0) {
		cout << "error" << endl;
		system("pause");
		cin.get();
		return 0;
	}

	calcX(a, b, eps, 0, 0);

	system("pause");
	cin.get();
	return 0;
}

