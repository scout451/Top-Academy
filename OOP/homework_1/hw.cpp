#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Fraction 
{
private:
    int Integer;
    int Numerator;
    int Denominator;

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
    Fraction Sum(Fraction& other) 
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
    Fraction Diff(Fraction& other) 
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
    Fraction Mult(Fraction& other) 
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
    Fraction Div(Fraction& other) 
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
