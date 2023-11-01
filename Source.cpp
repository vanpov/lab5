//lab 5, task 1
#include "Header.h"
int main()
{
	//first method
	double a = 0.8;
	double b = 1.762;
	double x0 = func(a);
	double xn = func(b);
	int n = 0;
	double h = 0;
	double xi = 0;
	double NormalResult = 2;
	double HalfResult = 1;
	while (abs(HalfResult - NormalResult)>0.0003)
	{
		n++;
		//For h=h
		h = (b - a) / n;
		for (double i = a + h; i < b; i = i + h)
		{
			xi = xi + func(i);
		}
		NormalResult = (0.5 * h) * (x0 + 2 * xi + xn);
		xi = 0;
		//For h=h/2
		h = h / 2;
		for (double i = a + h; i < b; i = i + h)
		{
			xi = xi + func(i);
		}
		HalfResult = (0.5 * h) * (x0 + 2 * xi + xn);
		xi = 0;
	}
	cout << NormalResult << endl;
	//second method
	double res2 = 0;
	int m = 1;
	while (m % 2 != 0)
	{
		cout << "m?\n";
		cin >> m;
	}
	h = (b - a) / m;
	x0 = func(a);
	xn = func(b);
	//нечетные
	double xnech = 0;
	for (double i = a + h; i < b; i = i + 2 * h)
	{
		xnech = xnech + func(i);
	}
	//четные
	double xch = 0;
	for (double i = a + 2 * h; i < b; i = i + 2 * h)
	{
		xch = xch + func(i);

	}
	res2 = (h / 3) * (x0 + xn + 4 * xnech + 2 * xch);
	cout << res2 << endl;
}