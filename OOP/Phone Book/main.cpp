#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

class Abonent
{
	string FIO;
	string HomeAbonent;
	string WorkAbonent;
	string MobileAbonent;
	string Info;

public:

	Abonent()
	{
	}

	~Abonent()
	{
	}

	string GetFIO() { return FIO; }
	void SetFIO(string newFIO)
	{
		FIO = newFIO;
	}

	string GetHomeAbonent() { return HomeAbonent; }
	void SetHomeAbonent(string Abonent)
	{
		HomeAbonent = Abonent;
	}

	string GetWorkAbonent() { return WorkAbonent; }
	void SetWorkAbonent(string Abonent)
	{
		WorkAbonent = Abonent;
	}

	string GetMobileAbonent() { return MobileAbonent; }
	void SetMobileAbonent(string Abonent)
	{
		MobileAbonent = Abonent;
	}

	string GetInfo() { return Info; }
	void SetInfo(string newInfo)
	{
		Info = newInfo;
	}
};

class Database
{
	vector <Abonent> Abonents;

public:
	void Add()
	{
		Abonent x;
		cout << "[Добавление новой записи]" << endl;
		cout << "Введите ФИО: ";
		string newFIO;
		cin.ignore();
		getline(cin, newFIO);
		x.SetFIO(newFIO);
		cin.clear();
		cout << "Введите домашний номер: ";
		string newHN;
		cin >> newHN;
		x.SetHomeAbonent(newHN);
		cout << "Введите мобильный номер: ";
		string newMN;
		cin >> newMN;
		x.SetMobileAbonent(newMN);
		cout << "Введите рабочий номер: ";
		string newWN;
		cin >> newWN;
		x.SetWorkAbonent(newWN);
		cout << "Введите описание: ";
		string newInfo;
		cin.ignore();
		getline(cin, newInfo);
		x.SetInfo(newInfo);
		Abonents.push_back(x);
		cout << "Новая запись с порядковым номером " << Abonents.size() << " добавлена!" << endl;
	}

	void Output(int i)
	{
		cout << i + 1 << ". " << Abonents[i].GetFIO() << endl
			<< "Домашний: " << Abonents[i].GetHomeAbonent() << endl
			<< "Мобильный: " << Abonents[i].GetMobileAbonent() << endl
			<< "Рабочий: " << Abonents[i].GetWorkAbonent() << endl;
		int sz = 60 - Abonents[i].GetFIO().size() - Abonents[i].GetMobileAbonent().size();
		if
			(Abonents[i].GetInfo().size() > sz)
			cout << "Инфо: " << Abonents[i].GetInfo().substr(0, sz) << "...";
		else
			cout << "Инфо: " << Abonents[i].GetInfo();
		cout << endl;
	}

	int Find()
	{
		int Id = 0;
		cout << "Введите порядковый номер абонента: ";
		cin >> Id;
		cout << endl;
		Output(Id - 1);

		return (Id < 1 || Id > Abonents.size()) ? -1 : Id - 1;
	}

	void Delete()
	{
		int i = 0;
		cout << "Введите номер записи: ";
		cin >> i;
		Output(i);
		if (i < 0)
		{
			cout << "Удаление не удалось!" << endl;
			return;
		}

		cout << "Удалить эту запись? (y/n)" << endl;
		char answer;
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			Abonents.erase(Abonents.begin() + i);
			cout << "Абонент с порядковым номером " << i + 1 << " удален" << endl;
		}
	}

	void All()
	{
		cout << "Всего " << Abonents.size() << " записей:" << endl;

		for (int i = 0; i < Abonents.size(); i++)
			Output(i);
	}

	int size()
	{
		return Abonents.size();
	}
	
};

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
		int sel;

		Database database;
		while (true)
		{
		cout << "\n\n\t\t[ Главное меню ]\n\n";
		cout << "1. Посмотреть список записей (" << database.size() << ")" << endl
			<< "2. Добавить нового абонента" << endl
			<< "3. Удалить абонента" << endl
			<< "4. Найти абонента" << endl
			<< "5. Выход" "\n\n> ";
		
		cin >> sel;
		cout << endl;

		switch (sel)
		{
		case 1: database.All(); break;
		case 2: database.Add(); break;
		case 3: database.Delete(); break;
		case 4: database.Find(); break;
		case 5: return;
		default:  break;
		}
		}
	
	system("pause");
}