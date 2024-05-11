#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

class PhoneBook
{
	char* Name;
	char* Surname;
	char* Patronymic;
	int HomeNumber;
	int WorkNumber;
	long long MobileNumber;
	char Info;

public:

	PhoneBook()
	{
		Name = nullptr;
		Surname = nullptr;
		Patronymic = nullptr;
		HomeNumber = 0;
		WorkNumber = 0;
		MobileNumber = 0;
		Info = 0;
	}

	~PhoneBook()
	{
		cout << "call destr" << endl;
		delete[] Name;
		delete[] Surname;
		delete[] Patronymic;
	}

	char* GetName() { return Name; }
	void SetName(const char *n)
	{
		delete[] Name;

		const int size = strlen(n) + 1;
		Name = new char[size];

		strcpy_s(Name, size, n);
	}

	char* GetSurname() { return Surname; }
	void SetSurname(const char *s)
	{
		delete[] Surname;

		const int size = strlen(s) + 1;
		Surname = new char[size];

		strcpy_s(Surname, size, s);
	}

	char* GetPatronymic() { return Patronymic; }
	void SetPatronymic(const char* p)
	{
		delete[] Patronymic;

		const int size = strlen(p) + 1;
		Patronymic = new char[size];

		strcpy_s(Patronymic, size, p);
	}

	int GetHomeNumber() { return HomeNumber; }
	void SetHomeNumber(int number)
	{
		HomeNumber = number;
	}

	int GetWorkNumber()	{ return WorkNumber; }
	void SetWorkNumber(int number)
	{
		WorkNumber = number;
	}

	int GetMobileNumber() { return MobileNumber; }
	void SetMobileNumber(long long number)
	{
		MobileNumber = number;
	}

	const char GetInfo() { return Info; }
	void SetInfo(const char newInfo)
	{
		Info = newInfo;
	}
};

void AddAbonent(PhoneBook* nameClass, const char*  newName, const char*  newSurname, const char*  newPatronymic,
	int homeNumber, int workNumber, long long mobileNumber) 
{
    nameClass->SetName(newName);
    nameClass->SetSurname(newSurname);
    nameClass->SetPatronymic(newPatronymic);
    nameClass->SetHomeNumber(homeNumber);
    nameClass->SetMobileNumber(mobileNumber);
    nameClass->SetWorkNumber(workNumber);
}

void ShowAbonent(PhoneBook* nameClass)
{
	cout << "Имя: " << nameClass->GetName() << endl;
	cout << "Фамилия: " << nameClass->GetSurname() << endl;
	cout << "Отчество: " << nameClass->GetPatronymic() << endl;
	cout << "Домашний номер: " << nameClass->GetHomeNumber() << endl;
	cout << "Мобильный номер: " << nameClass->GetMobileNumber() << endl;
	cout << "Рабочий номер: " << nameClass->GetWorkNumber() << endl;
}

void DeleteAbonent(PhoneBook* Abonent)
{
	delete Abonent;
}

void SearchAbonent()
{

}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int action, homeNumber, workNumber;
	const int maxLenght = 25;
	long long mobileNumber;
	char newName[maxLenght], newSurname[maxLenght], newPatronymic[maxLenght];
	vector<PhoneBook*> DataBase;

	cout << "Приложение \"Телефонная книга\"" << endl;
	cout << "1. Добавить нового абонента" << endl;
	cout << "2. Вывести абонента на экран" << endl;
	cout << "3. Удалить абонента" << endl;
	cout << "4. Найти абонента" << endl;
	cout << "5. Вывести на экран всех абонентов" << endl;

	PhoneBook* Abonent = new PhoneBook;

	while(true)
	{
		cout << "Выберите пункт меню: ";
		cin >> action;

	
	
	
		switch (action)
		{
		case 1:
			cout << "Введите имя: ";
			cin >> newName;
			cout << "Введите фамилию: ";
			cin >> newSurname;
			cout << "Введите отчество: ";
			cin >> newPatronymic;
			cout << "Введите домашний номер: ";
			cin >> homeNumber;
			cout << "Введите рабочий номер: ";
			cin >> workNumber;
			cout << "Введите мобильный номер: ";
			cin >> mobileNumber;
			AddAbonent(Abonent, newName, newSurname, newPatronymic, homeNumber, workNumber, mobileNumber);
			DataBase.push_back(Abonent);
			break;
		case 2:
			ShowAbonent(Abonent);
			break;
		case 3:
			DeleteAbonent(Abonent);
			break;
		}
	}
		/*PhoneBook* Abonent = new PhoneBook;
		DataBase.push_back(Abonent);
		const char* newName = "Nikita";
		const char* newSurname = "Zagnetin";
		const char* newPatronymic = "Yaroslavovich";
		int homeNumber = 172638;
		int workNumber = 471929;
		long long mobileNumber = 79127462839;

		AddAbonent(Abonent ,newName, newSurname, newPatronymic, homeNumber, workNumber, mobileNumber);
		cout << Abonent->GetName() << endl;
		Abonent->SetName("Woody");
		cout << Abonent->GetName() << endl;;*/

	system("pause");

}



/*class Student
{
	char* name;

public:
	Student() : Student("")
	{
		cout << "Call Student()" << endl;
	}

	Student(const char* n)
	{
		cout << "Call Student(const char* n)" << endl;

		const int size = strlen(n) + 1;
		name = new char[size];

		strcpy_s(name, size, n);
	}

	~Student()
	{
		cout << "Call ~Student()" << endl;

		delete[] name;
	}

	char* GetName()
	{
		return name;
	}

	void SetName(const char* n)
	{
		delete[] name;

		const int size = strlen(n) + 1;
		name = new char[size];

		strcpy_s(name, size, n);
	}
};

void Method()
{
	Student s1("qwerty");
	cout << "s1 created" << endl;
}

void main()
{
	cout << "Start" << endl;
	Student* s1 = new Student("qwerty");
	cout << "s1 created" << endl;
	s1->SetName("asdf");
	delete s1;
	cout << "s1 deleted" << endl;

	if (true)
	{
		cout << "Start" << endl;
		Student s1("qwerty");
		cout << "s1 created" << endl;
	}

	//cout << "Start" << endl;
	//Method();
	//Method();

	//Student* s1 = new Student("qwerty");
	//delete s1->GetName();
	//s1->SetName("asdf");
	//delete s1;

	//Student* arr1 = new Student[2];

	//Student** arr2 = new Student* [2];
	//for (int i = 0; i < 2; i++)
	//	arr2[i] = new Student("qwerty");

	system("pause");
}*/