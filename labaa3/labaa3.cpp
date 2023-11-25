#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

void checkValidFile(const ofstream& file)
{

	if (!file.is_open())
	{
		throw "File not open";
	}
}
void checkValidInput()
{
	if (cin.fail())
	{
		throw "Incorrect input";
	}
}

void checkValidParams(int n, double a, double b, double h)
{
	if (b < a || n <= 1)
	{
		throw "Incorrect data";
	}
}
double calculate(double x, double n) {

	double res = 0;

	if (x >= 0) {

		for (int i = 0; i <= n - 1; i++) {

			for (int j = 0; j <= n - 1; j++) {

				res += (x + i + j * j);

			}

		}

	}

	else if (x < 0) {

		for (int j = 2; j <= n - 2; j++) {

			res *= (j + 1);

		}

	}

	return res;

}

int main() {

	char choice;

	double a, b, h, n, y;

	try

	{

		cout << "If you want to write the results to a file, press Q, otherwise press W:";

		cin >> choice;
		checkValidInput();
		cout << "Write a: ";
		cin >> a;
		checkValidInput();
		cout << "Write b: ";
		cin >> b;
		checkValidInput();
		cout << "Write n: ";
		cin >> n;
		checkValidInput();
		cout << "Write h: ";
		cin >> h;
		checkValidInput();
		checkValidParams(n, a, b, h);
		ofstream fout;
		if (choice == 'Q')
		{
			fout.open("test.txt");
			checkValidFile(fout);
		}

		int x = a;
		while (x <= b) {

			y = calculate(x, n);

			cout << "x=" << x << endl;

			cout << "y=" << y << endl;

			cout << "n=" << n << endl;

			x += h;

		}
		if (fout.is_open())

		{
			fout << "X= " << x << std::endl;

			fout << "Y= " << y << std::endl;

			fout << "N= " << n << std::endl;

			fout.close();

		}

	}
	catch (const char* ex)
	{
		cout << ex << std::endl;

		return -1;

	}

	catch (...)

	{
		cout << "Unknown error";
		return -1;
	}
	return 0;

}