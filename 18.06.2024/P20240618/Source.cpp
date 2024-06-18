#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

class Figure
{
public:
	virtual double GetArea() = 0;
	virtual string ToString() = 0; // "Rectangle 4 5"
};

class Square : public Figure
{
	int height;
public:
	double GetArea() override
	{
		return height * height;
	}

	string ToString() override
	{
		string output = "Result "  ;
		return "Square " + to_string(height);
	}
	Square FromString(const string& str)
	{
		Square newRectangle(0, 0);
		int a = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (isdigit(str[i]) && a == 0)
				a = atoi(&str[i]);
			if (isdigit(str[i]) && b == 0 && a != 0)
				a = atoi(&str[i]);
		}
		newRectangle.height = a;
		newRectangle.width = b;
		return newRectangle;
	}
};

class Rectangle : public Figure
{
	int height;
	int width;
public:
	Rectangle(int h, int w) : height(h), width(w) {}
	double GetArea() override
	{
		return height * width;
	}

	string ToString() override
	{
		return "Rectangle " + to_string(height)+ ' ' + to_string(width);
	}

	Rectangle FromString(const string& str)
	{
		Rectangle newRectangle(0,0);
		int a = 0;
		int b = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (isdigit(str[i]) && a == 0)
				a = atoi(&str[i]);
			if (isdigit(str[i]) && b == 0 && a != 0)
				a = atoi(&str[i]);
		}
		newRectangle.height = a;
		newRectangle.width = b;
		return newRectangle;
	}
};
class Circle : public Figure
{
	int radius;
	const int PI = 3.14159;
public:
	double GetArea() override
	{
		return PI * (radius * radius);
	}

	string ToString() override
	{
		return "Circle " + to_string(radius);
	}
};

class Trapezoid : public Figure
{
	int upWidth;
	int downWidth;
	int height;
public:
	Trapezoid FromString(const string& str) {};
	double GetArea() override
	{
		return ((upWidth + downWidth) * height) / 2;
	}

	string ToString() override
	{
		return "Trapezoid " + to_string(upWidth) + ' ' + to_string(downWidth) + ' ' + to_string(height);
	}
};


class FigureCollection
{
	vector<Figure*> Figures;
public:
	void Add(Figure* figure)
	{
		Figures.push_back(figure);
	}
	
	void Save() const
	{
		ofstream file;
		for (int i = 0; i < Figures.size(); i++)
		{
			{
				if(dynamic_cast<Square*>(Figures[i])!= nullptr)
				{
					file.open("Square\\Square.txt", ios::out);
					if (file.is_open())
						file << Figures[i]->ToString() << endl;
				}
				if(dynamic_cast<Circle*>(Figures[i])!= nullptr)
				{
					file.open("Circle\\Circle.txt", ios::out);
					if (file.is_open())
						file << Figures[i]->ToString() << endl;
				}
				if(dynamic_cast<Rectangle*>(Figures[i])!= nullptr)
				{
					file.open("Rectangle\\Rectangle.txt", ios::out);
					if (file.is_open())
						file << Figures[i]->ToString() << endl;
				}
				if(dynamic_cast<Trapezoid*>(Figures[i])!= nullptr)
				{
					file.open("Trapezoid\\Trapezoid.txt", ios::out);
					if (file.is_open())
						file << Figures[i]->ToString() << endl;
				}
			}
		}
		file.close();
	}
	void Load();
};

void main()
{
	Rectangle r(0, 0);
	string s = "Rectangle 8 9";
	r.FromString(s);

	system("pause");
}