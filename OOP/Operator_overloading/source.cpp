#include <iostream>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

//Задача 1

/*class Fraction
{
    int Integer;
    int Numerator;
    int Denominator;

    // Наибольший общий делитель
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

    // Наименьшее общее кратное
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
    // Конструктор
    Fraction(int i, int n, int d) : Integer(i), Numerator(n), Denominator(d)
    {
    }

    // Перевести дробь в неправильный вид
    void Improper()
    {
        bool isNegative = Integer < 0;

        Numerator += abs(Integer) * Denominator;
        Integer = 0;

        if (isNegative)
            Numerator *= -1;
    }

    // Перевести дробь в правильный вид
    void Correct()
    {
        Integer += Numerator / Denominator;
        Numerator = abs(Numerator) % Denominator;
    }

    // Сократить дробь
    void Reduce()
    {
        int reduceBy = GreatestCommonDivisor(Numerator, Denominator);

        Numerator /= reduceBy;
        Denominator /= reduceBy;
    }

    // Перевести дробь в строку
    string ToString()
    {
        return to_string(Integer) + ":" +
            to_string(Numerator) + "/" +
            to_string(Denominator);
    }

    // Сумма дробей
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

    // Разность дробей
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

    // Произведение дробей
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

    // Деление дробей
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

int main()
{
    // Пример использования класса Fraction
    setlocale(LC_ALL, "");
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

    return 0;
}
*/

//Задача 2

class Complex
{
    double realPart;
    double imaginaryPart;

public:
    // Конструктор по умолчанию
    Complex() : realPart(0), imaginaryPart(0) {}

    // Конструктор с параметрами
    Complex(double real, double imag) : realPart(real), imaginaryPart(imag) {}

    // Методы для работы с комплексными числами
    string ToString() const
    {
        if (imaginaryPart >= 0)
        {
            return to_string(realPart) + "+" + to_string(imaginaryPart) + "i";
        }
        else
        {
            return to_string(realPart) + to_string(imaginaryPart) + "i";
        }
    }

    Complex Sum(const Complex& other) const
    {
        return Complex(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    Complex operator+(const Complex& other) const
    {
        return Sum(other);
    }

    Complex operator+(const int integer) const
    {
        return Complex(realPart + integer, imaginaryPart);
    }

    friend Complex operator+(const int integer, const Complex& other)
    {
        return Complex(other.realPart + integer, other.imaginaryPart);
    }

    Complex Diff(const Complex& other) const
    {
        return Complex(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }

    Complex operator-(const Complex& other) const
    {
        return Diff(other);
    }

    Complex operator-(const int integer) const
    {
        return Complex(realPart - integer, imaginaryPart);
    }

    friend Complex operator-(const int integer, const Complex& other)
    {
        return Complex(integer - other.realPart, -other.imaginaryPart);
    }

    Complex Mult(const Complex& other) const
    {
        return Complex(
            (realPart * other.realPart) - (imaginaryPart * other.imaginaryPart),
            (imaginaryPart * other.realPart) + (realPart * other.imaginaryPart)
        );
    }

    Complex operator*(const Complex& other) const
    {
        return Mult(other);
    }

    Complex operator*(const int integer) const
    {
        return Complex(realPart * integer, imaginaryPart * integer);
    }

    friend Complex operator*(const int integer, const Complex& other)
    {
        return Complex(other.realPart * integer, other.imaginaryPart * integer);
    }

    Complex Div(const Complex& other) const
    {
        double denominator = pow(other.realPart, 2) + pow(other.imaginaryPart, 2);
        return Complex(
            ((realPart * other.realPart) + (imaginaryPart * other.imaginaryPart)) / denominator,
            ((imaginaryPart * other.realPart) - (realPart * other.imaginaryPart)) / denominator
        );
    }

    Complex operator/(const Complex& other) const
    {
        return Div(other);
    }

    Complex operator/(const int integer) const
    {
        return Complex(realPart / integer, imaginaryPart / integer);
    }

    friend Complex operator/(const int integer, const Complex& other)
    {
        double denominator = pow(other.realPart, 2) + pow(other.imaginaryPart, 2);
        return Complex(
            (integer * other.realPart) / denominator,
            (-integer * other.imaginaryPart) / denominator
        );
    }
};

void main()
{
    Complex a(3, 4);
    Complex b(1, -2);
    Complex c = a + b;
    Complex d = a - b;
    Complex e = a * b;
    Complex f = a / b;

    Complex g = a + 2;
    Complex h = a - 2;
    Complex i = a * 2;
    Complex j = a / 2;

    Complex k = 2 + a;
    Complex l = 2 - a;
    Complex m = 2 * a;
    Complex n = 2 / a;

    cout << "a: " << a.ToString() << endl;
    cout << "b: " << b.ToString() << endl;
    cout << "a + b: " << c.ToString() << endl;
    cout << "a - b: " << d.ToString() << endl;
    cout << "a * b: " << e.ToString() << endl;
    cout << "a / b: " << f.ToString() << endl;

    cout << "a + 2: " << g.ToString() << endl;
    cout << "a - 2: " << h.ToString() << endl;
    cout << "a * 2: " << i.ToString() << endl;
    cout << "a / 2: " << j.ToString() << endl; 
    cout << "2 + a: " << k.ToString() << endl;
    cout << "2 - a: " << l.ToString() << endl;
    cout << "2 * a: " << m.ToString() << endl;
    cout << "2 / a: " << n.ToString() << endl;

    system("pause");
}