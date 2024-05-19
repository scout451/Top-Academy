#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include <span>

using namespace std;

class Human
{
	char* Name;
	char* Surname;
	char* Patronymic;

public:
	
	Human() : Human("\0","\0","\0") {}

	Human(const char* Name, const char* Surname, const char* Patronymic)
	{
		int lenName = strlen(Name) + 1;
		this->Name = new char[lenName];
		strcpy_s(this->Name, lenName, Name);

		int lenSurname = strlen(Surname) + 1;
		this->Surname = new char[lenSurname];
		strcpy_s(this->Surname, lenSurname, Surname);

		int lenPatronymic = strlen(Patronymic) + 1;
		this->Patronymic = new char[lenPatronymic];
		strcpy_s(this->Patronymic, lenPatronymic, Patronymic);
	}

	Human(const Human& other)
	{
		int lenName = strlen(other.Name) + 1;
		Name = new char[lenName];
		strcpy_s(Name, lenName, other.Name);

		int lenSurname = strlen(other.Surname) + 1;
		this->Surname = new char[lenSurname];
		strcpy_s(this->Surname, lenSurname, other.Surname);

		int lenPatronymic = strlen(other.Patronymic) + 1;
		this->Patronymic = new char[lenPatronymic];
		strcpy_s(this->Patronymic, lenPatronymic, other.Patronymic);
	}

	~Human()
	{
		if (Name != nullptr)
		{
			delete[] Name;
		}
		if (Surname != nullptr)
		{
			delete[] Surname;
		}
		if (Patronymic != nullptr)
		{
			delete[] Patronymic;
		}
	}

	char* GetName() { return Name; }
	void SetName(const char* Name)
	{
		int lenName = strlen(Name) + 1;
		this->Name = new char[lenName];
		strcpy_s(this->Name, lenName, Name);
	}

	char* GetSurSurname() { return Surname; }
	void SetSurname(const char* Surname)
	{
		int lenSurname = strlen(Surname) + 1;
		this->Surname = new char[lenSurname];
		strcpy_s(this->Surname, lenSurname, Surname);
	}

	char* GetPatronymic() { return Patronymic; }
	void SetPatronymic(const char* Patronymic)
	{
		int lenPatronymic = strlen(Patronymic) + 1;
		this->Patronymic = new char[lenPatronymic];
		strcpy_s(this->Patronymic, lenPatronymic, Patronymic);
	}
};

class Apartment 
{
	vector<Human> Humans;

public:

	Apartment(Human Resident)
	{
		Humans.push_back(Resident);
	}

	void Add(Human Resident)
	{
		Humans.push_back(Resident);
	}

	void Remove()
	{
		Humans.pop_back();
	}

	void Remove(int index)
	{
		Humans.erase(Humans.begin() + (index - 1));
	}
};

class House
{
	vector<Apartment> Apartments;

public:

	House(Apartment Apartment)
	{
		Apartments.push_back(Apartment);
	}

	void Add(Apartment Apartment)
	{
		Apartments.push_back(Apartment);
	}

	void Remove()
	{
		Apartments.pop_back();
	}

	void Remove(int index)
	{
		Apartments.erase(Apartments.begin() + (index - 1));
	}
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Human Me("Никита", "Загнетин", "Ярославович");
	Human Mother("Светлана", "Загнетина", "Энгельсовна");
	Human Father("Ярослав", "Загнетин", "Геннадиевич");

	Apartment MyApartment(Me);
	MyApartment.Add(Mother);
	MyApartment.Add(Father);

	House MyHouse(MyApartment);

	system("pause");
}