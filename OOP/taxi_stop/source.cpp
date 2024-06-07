#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int SeatsOnBus()
{
	return rand() % 100 % 10 * 10;
}

int RandomTimeArrivalPass(int value)
{
	int a = value - 1;
	int b = value + 1;
	return a + rand() % (int)(b - a + 1);
}

int RandomTimeArrivalBus(int value)
{
	int a = value - 3;
	int b = value + 3;
	return a + rand() % (int)(b - a + 1);
}

void main()
{
	setlocale(LC_ALL, "ru");
	srand(time(nullptr));

	int timePass[4] = { 1, 2, 3, 4 };
	int timeBus[4] = { 5, 6, 7, 8 };
	string typeStopBus = "intermediate"; // либо "final"

	int totalPass = 0;
	int currentPass = 0;
	int totalBus = 0;
	int totalWaitTime = 0;
	int totalTime = 1440; // минуты
	int currentTime = 0;
	int timeOfDay = 0; // 0 - утро, 1 - день, 2 - вечер, 3 - ночь

	priority_queue<int, vector<int>, greater<int>> ArriveTimePass;
	priority_queue<int, vector<int>, greater<int>> ArriveTimeBus;

	ArriveTimePass.push(RandomTimeArrivalPass(timePass[timeOfDay]));
	ArriveTimeBus.push(RandomTimeArrivalBus(timeBus[timeOfDay]));

	while(currentTime < totalTime)
	{
		if(!ArriveTimePass.empty() && (ArriveTimePass.top() < ArriveTimeBus.top() || ArriveTimeBus.empty())) // если пассажир пришел раньше
		{
			currentTime = ArriveTimePass.top();
			ArriveTimePass.pop();

			totalPass++;
			currentPass++;

			ArriveTimePass.push(currentTime + RandomTimeArrivalPass(timePass[timeOfDay]));
		}

		else // если автобус пришел раньше
		{
			currentTime = ArriveTimeBus.top();
			ArriveTimeBus.pop();

			totalBus++;
			int seats = SeatsOnBus();
			
			if (currentPass < seats)
			{
				totalWaitTime += currentPass * currentTime;
				currentPass = 0;
			}
			else
			{
				totalWaitTime += seats * currentTime;
				currentPass -= seats;
			}

			ArriveTimeBus.push(currentTime + RandomTimeArrivalBus(timeBus[timeOfDay]));
		}

		if (currentTime > 360 || currentTime > 720 || currentTime > 1080)
			timeOfDay++;
	}

	double averageWaitTime = totalWaitTime / totalPass;
	double averageBusInterval = totalTime / totalBus;

	cout << "Среднее время ожидания человека на остановке: " << averageWaitTime << endl;
	std::cout << "Средний интервал времени между маршрутками: " << averageBusInterval << endl;
	std::cout << "Общее количество пассажиров: " << totalPass << endl;
	std::cout << "Общее количество маршруток: " << totalBus<< endl;
	system("pause");
}