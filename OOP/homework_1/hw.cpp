#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Fraction 
{
private:
    int integer;
    int numerator;
    int denominator;

    // Наибольший общий делитель
    int GreatestCommonDivisor(int a, int b)
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
    int LeastCommonMultiple(int a, int b)
    {
        return a * b / GreatestCommonDivisor(a, b);
    }

public:
    // Конструктор
    Fraction(int i, int n, int d) : integer(i), numerator(n), denominator(d)
    {
    }

    // Перевести дробь в неправильный вид
    void Improper() 
    {
        bool isNegative = integer < 0;

        numerator += abs(integer) * denominator;
        integer = 0;

        if (isNegative)
            numerator *= -1;
    }

    // Перевести дробь в правильный вид
    void Correct() 
    {
        integer += numerator / denominator;
        numerator = abs(numerator) % denominator;
    }

    // Сократить дробь
    void Reduce() 
    {
        int reduceBy = GreatestCommonDivisor(numerator, denominator);

        numerator /= reduceBy;
        denominator /= reduceBy;
    }

    // Перевести дробь в строку
    string ToString() 
    {
        return to_string(integer) + ":" +
            to_string(numerator) + "/" +
            to_string(denominator);
    }

    // Сумма дробей
    Fraction Sum(Fraction& other) 
    {
        Fraction tempA = *this;
        Fraction tempB = other;

        tempA.Improper();
        tempB.Improper();

        int commonDenominator = LeastCommonMultiple(denominator, other.denominator);

        tempA.numerator *= commonDenominator / tempA.denominator;
        tempA.denominator = commonDenominator;

        tempB.numerator *= commonDenominator / tempB.denominator;
        tempB.denominator = commonDenominator;

        tempA.numerator += tempB.numerator;

        tempA.Reduce();
        tempA.Correct();

        return tempA;
    }

    // Разность дробей
    Fraction Diff(Fraction& other) 
    {
        Fraction tempA = *this;
        Fraction tempB = other;

        tempA.Improper();
        tempB.Improper();

        int commonDenominator = LeastCommonMultiple(denominator, other.denominator);

        tempA.numerator *= commonDenominator / tempA.denominator;
        tempA.denominator = commonDenominator;

        tempB.numerator *= commonDenominator / tempB.denominator;
        tempB.denominator = commonDenominator;

        tempA.numerator -= tempB.numerator;

        tempA.Reduce();
        tempA.Correct();

        return tempA;
    }

    // Произведение дробей
    Fraction Mult(Fraction& other) 
    {
        Fraction tempA = *this;
        Fraction tempB = other;

        tempA.Improper();
        tempB.Improper();

        tempA.numerator *= tempB.numerator;
        tempA.denominator *= tempB.denominator;

        tempA.Reduce();
        tempA.Correct();

        return tempA;
    }

    // Деление дробей
    Fraction Div(Fraction& other) 
    {
        Fraction tempA = *this;
        Fraction tempB = other;

        tempA.Improper();
        tempB.Improper();

        tempA.numerator *= tempB.denominator;
        tempA.denominator *= tempB.numerator;

        tempA.Reduce();
        tempA.Correct();

        return tempA;
    }
};

int main() 
{
    // Пример использования класса Fraction
    setlocale(LC_ALL, "");
    Fraction f1(2, 2, 3);
    Fraction f2(4, 3, 4);

    Fraction result = f1.Sum(f2);
    cout << "Сумма: " << result.ToString() << endl;

    result = f1.Diff(f2);
    cout << "Разность: " << result.ToString() << endl;

    result = f1.Mult(f2);
    cout << "Произведение: " << result.ToString() << endl;

    result = f1.Div(f2);
    cout << "Деление: " << result.ToString() << endl;

    return 0;
}
