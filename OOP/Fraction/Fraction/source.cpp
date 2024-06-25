#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

namespace MyFraction
{
	class Fraction
	{
		int Integer;
		int Numerator;
		int Denominator;

		int GreatestCommonDivisor(int a, int b) const
		{
			if (a < b)
				swap(a, b);

			while (a % b != 0)
			{
				a = a % b;
				swap(a, b);
			}

			return abs(b);
		}


		int LeastCommonMultiple(int a, int b) const
		{
			return a * b / GreatestCommonDivisor(a, b);
		}

	public:
		Fraction()
		{
			Integer = 0;
			Numerator = 0;
			Denominator = 0;
		}

		Fraction(int i, int n, int d) : Integer(i), Numerator(n), Denominator(d)
		{
		}

		void Improper()
		{
			bool isNegative = Integer < 0;

			Numerator += abs(Integer) * Denominator;
			Integer = 0;

			if (isNegative)
				Numerator *= -1;
		}

		void Correct()
		{
			Integer += Numerator / Denominator;
			Numerator = abs(Numerator) % Denominator;
		}

		void Reduce()
		{
			int reduceBy = GreatestCommonDivisor(Numerator, Denominator);

			Numerator /= reduceBy;
			Denominator /= reduceBy;
		}


		string ToString()
		{
			return to_string(Integer) + ":" +
				to_string(Numerator) + "/" +
				to_string(Denominator);
		}


		Fraction Sum(const Fraction& other) const
		{
			Fraction tempA = *this;
			Fraction tempB = other;

			tempA.Improper();
			tempB.Improper();

			int commonDenominator = LeastCommonMultiple(Denominator, other.Denominator);

			tempA.Numerator *= commonDenominator / tempA.Denominator;
			tempA.Denominator = commonDenominator;

			tempB.Numerator *= commonDenominator / tempB.Denominator;
			tempB.Denominator = commonDenominator;

			tempA.Numerator += tempB.Numerator;

			tempA.Reduce();
			tempA.Correct();

			return tempA;
		}


		Fraction Diff(const Fraction& other) const
		{
			Fraction tempA = *this;
			Fraction tempB = other;

			tempA.Improper();
			tempB.Improper();

			int commonDenominator = LeastCommonMultiple(Denominator, other.Denominator);

			tempA.Numerator *= commonDenominator / tempA.Denominator;
			tempA.Denominator = commonDenominator;

			tempB.Numerator *= commonDenominator / tempB.Denominator;
			tempB.Denominator = commonDenominator;

			tempA.Numerator -= tempB.Numerator;

			tempA.Reduce();
			tempA.Correct();

			return tempA;
		}


		Fraction Mult(const Fraction& other) const
		{
			Fraction tempA = *this;
			Fraction tempB = other;

			tempA.Improper();
			tempB.Improper();

			tempA.Numerator *= tempB.Numerator;
			tempA.Denominator *= tempB.Denominator;

			tempA.Reduce();
			tempA.Correct();

			return tempA;
		}


		Fraction Div(const Fraction& other) const
		{
			Fraction tempA = *this;
			Fraction tempB = other;

			tempA.Improper();
			tempB.Improper();

			tempA.Numerator *= tempB.Denominator;
			tempA.Denominator *= tempB.Numerator;

			tempA.Reduce();
			tempA.Correct();

			return tempA;
		}

		Fraction operator+(const Fraction& other) const
		{
			Fraction temp(*this);

			return temp.Sum(other);
		}

		friend Fraction operator+(const int integer, const Fraction& other)
		{
			Fraction temp(other);
			temp.Integer += integer;

			return temp;
		}

		Fraction operator+(const int integer) const
		{
			Fraction temp(*this);
			temp.Integer += integer;

			return temp;
		}

		Fraction operator-(const Fraction& other) const
		{
			Fraction temp(*this);

			return temp.Diff(other);
		}

		friend Fraction operator-(const int integer, const Fraction& other)
		{
			Fraction temp(other);
			temp.Integer -= integer;

			return temp;
		}

		Fraction operator-(const int integer) const
		{
			Fraction temp(*this);
			temp.Integer -= integer;

			return temp;
		}

		Fraction operator*(const Fraction& other) const
		{
			Fraction temp(*this);

			return temp.Mult(other);
		}

		friend Fraction operator*(const int integer, const Fraction& other)
		{
			Fraction temp(other);
			temp.Integer *= integer;
			temp.Numerator *= integer;
			if (temp.Numerator > temp.Denominator)
			{
				temp.Numerator = temp.Numerator - temp.Denominator;
				temp.Integer++;
			}

			return temp;
		}

		Fraction operator*(const int integer) const
		{
			Fraction temp(*this);
			temp.Integer *= integer;
			temp.Numerator *= integer;
			if (temp.Numerator > temp.Denominator)
			{
				temp.Numerator = temp.Numerator - temp.Denominator;
				temp.Integer++;
			}

			return temp;
		}

		Fraction operator/(const Fraction& other) const
		{
			Fraction temp(*this);

			return temp.Div(other);
		}

		friend Fraction operator/(const int integer, const Fraction& other)
		{
			Fraction temp(other);
			temp.Integer /= integer;
			temp.Numerator /= integer;
			if (temp.Numerator > temp.Denominator)
			{
				temp.Numerator = temp.Numerator - temp.Denominator;
				temp.Integer++;
			}

			return temp;
		}

		Fraction operator/(const int integer) const
		{
			Fraction temp(*this);
			temp.Integer /= integer;
			temp.Numerator /= integer;
			if (temp.Numerator > temp.Denominator)
			{
				temp.Numerator = temp.Numerator - temp.Denominator;
				temp.Integer++;
			}

			return temp;
		}
	};
}

using namespace MyFraction;

void TestFraction()
{
	Fraction f1(2, 2, 3);
	Fraction f2(4, 3, 4);

	Fraction result = f1 + f2;
	cout << "Сумма дробей: " << result.ToString() << endl;
	result = result + 1;
	cout << "Сумма + 1: " << result.ToString() << endl;
	result = 1 + result;
	cout << "1 + Сумма: " << result.ToString() << endl << endl;

	result = f1.Diff(f2);
	cout << "Разность дробей: " << result.ToString() << endl;
	result = result - 1;
	cout << "Разность дробей: " << result.ToString() << endl;
	result = 1 - result;
	cout << "Разность дробей: " << result.ToString() << endl << endl;

	result = f1.Mult(f2);
	cout << "Произведение дробей: " << result.ToString() << endl;
	result = result * 2;
	cout << "Произведение дробей: " << result.ToString() << endl;
	result = 2 * result;
	cout << "Произведение дробей: " << result.ToString() << endl << endl;

	result = f1.Div(f2);
	cout << "Деление дробей: " << result.ToString() << endl;
	result = result / 2;
	cout << "Деление дробей: " << result.ToString() << endl;
	result = 2 / result;
	cout << "Деление дробей: " << result.ToString() << endl;
}

void main()
{
	setlocale(LC_ALL, "");
	TestFraction();

	system("pause");
}
