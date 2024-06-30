#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

//Встреча 26
//Задание 1
//class Directory
//{
//	string companyName;
//	string owner;
//	int number;
//	string adress;
//	string typeOfActivity;
//public:
//	Directory() : Directory ("", "", 0, "", "") {}
//	Directory(string compName, string owner, int number,
//		string adress, string activity)
//	{
//		this->companyName = compName;
//		this->owner = owner;
//		this->number = number;
//		this->adress = adress;
//		this->typeOfActivity = activity;
//
//		ofstream file("Directory.txt", ios::app);
//		if (!file.is_open())
//			cout << "File not opened." << endl;
//		
//		file << "Company name: " << companyName << endl;
//		file << "Owner: " << owner << endl;
//		file << "Number: " << number << endl;
//		file << "Adress: " << adress << endl;
//		file << "Type of activity: " << typeOfActivity << endl << endl;
//
//		file.close();
//	}
//
//	string GetName() { return companyName; }
//	string GetOwner() { return owner; }
//	int GetNumber() { return number; }
//	string GetAdress() { return adress; }
//	string GetActivity() { return typeOfActivity; }
//	void Print()
//	{
//		cout << "Company name: " << companyName << endl;
//		cout << "Owner: " << owner << endl;
//		cout << "Number: " << number << endl;
//		cout << "Adress: " << adress << endl;
//		cout << "Type of activity: " << typeOfActivity << endl;
//	}
//};
//
//class SearchingInDirectory
//{
//	vector<Directory> entriesInTheDirectory;
//public:
//	void SearchByName(const string& name)
//	{
//		bool found = false;
//		for (Directory& entry : entriesInTheDirectory)
//		{
//			string lowerSourceName = entry.GetName();
//			for (char& ch : lowerSourceName)
//				ch = tolower(ch);
//			string lowerDestName = name;
//			for (char& ch : lowerDestName)
//				ch = tolower(ch);
//			if (lowerSourceName == lowerDestName)
//			{
//				found = true;
//				cout << "\nFind by name is successful!" << endl << endl;
//				entry.Print();
//			}
//		}
//		if (!found) 
//			cout << "No entry found by name: " << name << endl;
//	}
//	
//	void SearchByOwner(const string& owner)
//	{
//		bool found = false;
//		for (Directory& entry : entriesInTheDirectory)
//		{
//			string lowerSourceOwner = entry.GetOwner();
//			for (char& ch : lowerSourceOwner)
//				ch = tolower(ch);
//			string lowerDestOwner = owner;
//			for (char& ch : lowerDestOwner)
//				ch = tolower(ch);
//			if (lowerSourceOwner == lowerDestOwner)
//			{
//				cout << "\nFind by owner is successful!" << endl << endl;
//				entry.Print();
//			}
//		}
//		if (!found) 
//			cout << "No entry found by owner: " << owner << endl;
//	}
//	
//	void SearchByAdress(const string& adress)
//	{
//		bool found = false;
//		for (Directory& entry : entriesInTheDirectory)
//		{
//			string lowerSourceAdress = entry.GetAdress();
//			for (char& ch : lowerSourceAdress)
//				ch = tolower(ch);
//			string lowerDestAdress = adress;
//			for (char& ch : lowerDestAdress)
//				ch = tolower(ch);
//			if (lowerSourceAdress == lowerDestAdress)
//			{
//				cout << "\nFind by adress is successful!" << endl << endl;
//				entry.Print();
//			}
//		}
//		if (!found) cout << "No entry found by address: " << adress << endl;
//	}
//	
//	void SearchByActivity(const string& activity)
//	{
//		bool found = false;
//		for (Directory& entry : entriesInTheDirectory)
//		{
//			string lowerSourceActivity = entry.GetActivity();
//			for (char& ch : lowerSourceActivity)
//				ch = tolower(ch);
//			string lowerDestActivity = activity;
//			for (char& ch : lowerDestActivity)
//				ch = tolower(ch);
//			if (lowerSourceActivity == lowerDestActivity)
//			{
//				cout << "\nFind by activity is successful!" << endl << endl;
//				entry.Print();
//			}
//		}
//		if (!found) 
//			cout << "No entry found by activity: " << activity << endl;
//	}
//
//	void SearchByNumber(const int& number)
//	{
//		bool found = false;
//		for (Directory& entry : entriesInTheDirectory)
//			if (entry.GetNumber() == number)
//			{
//				cout << "\nFind by number is successful!" << endl << endl;
//				entry.Print();
//			}
//		if (!found) 
//			cout << "No entry found by number: " << number << endl;
//	}
//
//	void ShowAllEntries()
//	{
//		for (Directory& entry : entriesInTheDirectory)
//		{
//			entry.Print();
//		}
//	}
//
//	void Add(Directory newElement)
//	{
//		entriesInTheDirectory.push_back(newElement);
//	}
//};
//
//void main()
//{
//	SearchingInDirectory directory;
//	Directory first("Name", "Owner1", 123456, "Adress", "Activity1");
//	Directory second("Name2", "Owner2", 123456789, "Adress2", "Activity");
//	Directory third("Name", "Owner", 123456, "Adress", "Activity");
//	Directory fourth("Name", "Owner", 123456741, "Adress3", "Activity");
//
//	directory.Add(first);
//	directory.Add(second);
//	directory.Add(third);
//	directory.Add(fourth);
//	directory.SearchByName("name");
//	directory.SearchByName("qwerty");
//	cout << endl;
//	directory.SearchByOwner("owner");
//	directory.SearchByOwner("qwerty");
//	cout << endl;
//	directory.SearchByNumber(123456);
//	directory.SearchByNumber(212524412);
//	cout << endl;
//	directory.SearchByAdress("adress");
//	directory.SearchByAdress("qwerty");
//	cout << endl;
//	directory.SearchByActivity("activity");
//	directory.SearchByActivity("qwerty");
//	
//	system("pause");
//}

//Встреча 28
//Задание 1

string CleanWord(const string& word)
{
	string cleaned;
	for (char ch : word)
		if (isalpha(ch))
			cleaned += tolower(ch);
	return cleaned;
}

void main()
{
	ifstream inputFile("input.txt");
	if (!inputFile.is_open())
		cout << "File not open" << endl;

	map<string, int> wordCount;

	string line, word;
	while (inputFile >> word)
	{
		word = CleanWord(word);
		if (!word.empty())
			wordCount[word]++;
	}
	inputFile.close();

	cout << "Word Dictionary:" << endl;
	for (const auto& entry : wordCount)
		cout << entry.first << ": " << entry.second << endl;

	string mostFrequentWord;
	int maxFrequency = 0;
	for (const auto& entry : wordCount)
	{
		if (entry.second > maxFrequency)
		{
			mostFrequentWord = entry.first;
			maxFrequency = entry.second;
		}
	}

	cout << "\nThe most common word: " << mostFrequentWord << 
		" (" << maxFrequency << " times)" << endl;

	ofstream outputFile("output.txt");
	if (!outputFile.is_open())
	{
		cerr << "File not open" << endl;
	}

	outputFile << "Word  Dictionary:" << endl;
	for (const auto& entry : wordCount)
	{
		outputFile << entry.first << ": " << entry.second << endl;
	}

	outputFile << "\nThe most common word: " << mostFrequentWord << 
		" (" << maxFrequency << " times)" << endl;
	outputFile.close();

	system("pause");
}
