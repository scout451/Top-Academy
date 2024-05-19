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

	Reservoir A("������ ����", "����", 1160, 65, 1276);
	Reservoir B("����� �����", "�����", 15800, 19500, 10994);
	Reservoir C("���������� ����", "����", 1600, 193, 55);
	Reservoir D("�������� ����", "����", 13, 3, 4);

	Pools WorldReservoirs(A);
	WorldReservoirs.Add(B);
	WorldReservoirs.Add(C);
	WorldReservoirs.Add(D);

	cout << A.GetName() << " : " << endl;
	cout << "��� - " << A.GetType() << endl;
	cout << "������� - " << A.Area() << " ��.��." << endl;
	cout << "������� - " << A.GetDepth() << " ��.��." << endl;
	cout << "����� - " << A.Volume() << " ���.�." << endl  << endl;

	cout << B.GetName() << " : " << endl;
	cout << "��� - " << B.GetType() << endl;
	cout << "������� - " << B.Area() << " ��.��." << endl;
	cout << "������� - " << B.GetDepth() << " ��.��." << endl;
	cout << "����� - " << B.Volume() << " ���.�." << endl << endl;

	cout << C.GetName() << " : " << endl;
	cout << "��� - " << C.GetType() << endl;
	cout << "������� - " << C.Area() << " ��.��." << endl;
	cout << "������� - " << C.GetDepth() << " ��.��." << endl;
	cout << "����� - " << C.Volume() << " ���.�." << endl << endl;

	cout << D.GetName() << " : " << endl;
	cout << "��� - " << D.GetType() << endl;
	cout << "������� - " << D.Area() << " ��.��." << endl;
	cout << "������� - " << D.GetDepth() << " ��.��." << endl;
	cout << "����� - " << D.Volume() << " ���.�." << endl << endl;

	if (!Reservoir::AreaCompare(A, B))
		cout << "������� " << A.GetName() << " � " << B.GetName() << " �� ���������." << endl;
	if (Reservoir::TypeCompare(A, C))
		cout << "��� " << A.GetName() << " � " << C.GetName() << " ���������." << endl;

	system("pause");
}