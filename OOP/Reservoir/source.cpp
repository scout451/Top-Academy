#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

class Reservoir
{
	string Name;
	string Type;
	int Width;
	int Length;
	int Depth;

public:

	static bool TypeCompare(Reservoir& first, Reservoir& second)
	{
		return first.GetType() == second.GetType();
	}

	static bool AreaCompare(Reservoir& first, Reservoir& second)
	{
		return first.Area() == second.Area();
	}

	Reservoir() : Reservoir("","", 0, 0, 0) {}
	
	explicit Reservoir(string name)
	{
		this->Name = name;
	}

	Reservoir(string name, string type) 
	{
		this->Name = name;
		this->Type = type;
	}

	Reservoir(string name, string type, int width, int length, int depth)
	{
		this->Name = name;
		this->Type = type;
		this->Width = width;
		this->Length = length;
		this->Depth = depth;
	}

	Reservoir(const Reservoir& other)
	{
		this->Name = other.Name;
		this->Type = other.Type;
		this->Width = other.Width;
		this->Length = other.Length;
		this->Depth = other.Depth;
	}

	string GetName() const { return Name; }
	void SetName(string Name) { this->Name = Name; }

	string GetType() const { return Type; } 
	void SetType(string Type) { this->Type = Type; }

	int GetWidth() const { return Width; } 
	void SetWidth(int value) { Width = value; }

	int GetLength() const { return Length; } 
	void SetLength(int value) { Length = value; }

	int GetDepth() const { return Depth; } 
	void SetDepth(int value) { Depth = value; }

	int Volume()
	{
		return Width * Length * Depth;
	}

	int Area()
	{
		return (Width != Length) ? Width * Length : Width * Width;
	}
	
};

class Pools
{
	vector<Reservoir> Reservoirs;

public:

	Pools(Reservoir object)
	{
		Reservoirs.push_back(object);
	}

	void Add(Reservoir object)
	{
		Reservoirs.push_back(object);
	}

	void Remove()
	{
		Reservoirs.pop_back();
	}

	void Remove(int index)
	{
		Reservoirs.erase(Reservoirs.begin() + (index - 1));
	}
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Reservoir A("Черное море", "Море", 1160, 65, 1276);
	Reservoir B("Тихий океан", "Океан", 15800, 19500, 10994);
	Reservoir C("Балтийское море", "Море", 1600, 193, 55);
	Reservoir D("Ижевский пруд", "Пруд", 13, 3, 4);

	Pools WorldReservoirs(A);
	WorldReservoirs.Add(B);
	WorldReservoirs.Add(C);
	WorldReservoirs.Add(D);

	cout << A.GetName() << " : " << endl;
	cout << "Тип - " << A.GetType() << endl;
	cout << "Площадь - " << A.Area() << " кв.км." << endl;
	cout << "Глубина - " << A.GetDepth() << " кв.км." << endl;
	cout << "Объем - " << A.Volume() << " куб.м." << endl  << endl;

	cout << B.GetName() << " : " << endl;
	cout << "Тип - " << B.GetType() << endl;
	cout << "Площадь - " << B.Area() << " кв.км." << endl;
	cout << "Глубина - " << B.GetDepth() << " кв.км." << endl;
	cout << "Объем - " << B.Volume() << " куб.м." << endl << endl;

	cout << C.GetName() << " : " << endl;
	cout << "Тип - " << C.GetType() << endl;
	cout << "Площадь - " << C.Area() << " кв.км." << endl;
	cout << "Глубина - " << C.GetDepth() << " кв.км." << endl;
	cout << "Объем - " << C.Volume() << " куб.м." << endl << endl;

	cout << D.GetName() << " : " << endl;
	cout << "Тип - " << D.GetType() << endl;
	cout << "Площадь - " << D.Area() << " кв.км." << endl;
	cout << "Глубина - " << D.GetDepth() << " кв.км." << endl;
	cout << "Объем - " << D.Volume() << " куб.м." << endl << endl;

	if (!Reservoir::AreaCompare(A, B))
		cout << "Площадь " << A.GetName() << " и " << B.GetName() << " не совпадает." << endl;
	if (Reservoir::TypeCompare(A, C))
		cout << "Тип " << A.GetName() << " и " << C.GetName() << " совпадает." << endl;

	system("pause");
}