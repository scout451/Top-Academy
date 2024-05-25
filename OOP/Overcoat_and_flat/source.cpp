#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Задача 1

class Overcoat
{
	string type;
	string title;
	double price;

public:
	
	Overcoat() : Overcoat("\0", "\0", 0) {}

	Overcoat(string type, string title, double price) : type(type), title(title), price(price) {}
	
    Overcoat operator=(Overcoat& other)
    {
        if (this == &other)
        {
            return *this;
        }

        type = other.type;
        title = other.title;
        price = other.price;
        return *this;
    }

	bool operator<(const Overcoat& other) const 
	{
		return price < other.price;
	}

	bool operator>(const Overcoat& other) const 
	{
		return price > other.price;
	}

	bool operator==(const Overcoat& other) const 
	{
		return type == other.type;
	}
};

//Задача 2

class Flat 
{
    double area;
    double price;

public:

    Flat() : area(0), price(0) {}
    Flat(double a, double p) : area(a), price(p) {}

    bool operator==(const Flat& other) const 
    {
        return area == other.area;
    }

    Flat& operator=(const Flat& other) 
    {
        if (this == &other) 
        {
            return *this;
        }

        area = other.area;
        price = other.price;
        return *this;
    }

    bool operator>(const Flat& other) const 
    {
        return price > other.price;
    }

    bool operator<(const Flat& other) const 
    {
        return price < other.price;
    }

};

void main()
{
	Overcoat Shapka("hat","my_shapka", 41.99);
	Overcoat Sharf;
	Overcoat Kurtka("outerwear","my_kurtka",74.98);
	Sharf = Shapka;
	Shapka = Kurtka;
	Shapka == Sharf;
	Shapka > Sharf;
	Shapka < Sharf;
	Shapka = Sharf;

    Flat flat1(70.5, 100000);
    Flat flat2(85.0, 120000);
    Flat flat3 = flat1;
    flat1 > flat2;
    flat1 < flat2;
    flat1 == flat2;

	system("pause");
}