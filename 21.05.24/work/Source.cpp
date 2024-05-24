#include <iostream>
#include <algorithm>
#include <string>
#include <span>

using namespace std;

class TimeSpan
{
	long long totalMilliseconds;
	
public:
	int GetDays() const { return totalMilliseconds / 24 / 60 / 60/ 1000 / 60; };

	int GetHours() const { return totalMilliseconds / 1000 / 60 / 60 % 60; };
	int GetTotalHours() const { return totalMilliseconds / 1000 / 60 / 60; };

	int GetMinutes() const { return totalMilliseconds / 1000 / 60 % 60; };
	int GetTotalMinutes() const { return totalMilliseconds / 1000 / 60; };
	
	int GetSeconds() const { return totalMilliseconds / 1000 % 60; };
	int GetTotalSeconds() const { return totalMilliseconds / 1000; };

	int GetTotalMilliseconds() const { return totalMilliseconds; } ;

	TimeSpan() : TimeSpan(0,0,0,0)
	{
		
	}

	TimeSpan(int days, int hours, int mins, int sec)
	{
		totalMilliseconds = 0;
		AddDays(days);
		AddHours(hours);
		AddMinutes(mins);
		AddSeconds(sec);
	}

	TimeSpan operator-(const TimeSpan& right) const
	{
		TimeSpan temp(*this);
		temp.totalMilliseconds = temp.totalMilliseconds - right.totalMilliseconds;

		return temp;
	}

	TimeSpan operator+(const TimeSpan& right) const
	{
		TimeSpan temp(*this);
		temp.totalMilliseconds = totalMilliseconds + right.totalMilliseconds;

		return temp;
	}

	TimeSpan AddDays(int days)
	{
		totalMilliseconds += days * 24 * 60 * 60 * 1000;

		return *this;
	}
	TimeSpan AddHours(int hours)
	{
		totalMilliseconds += hours * 60 * 60 * 1000;

		return *this;
	}
	TimeSpan AddMinutes(int minutes)
	{
		totalMilliseconds += minutes * 60 * 1000;

		return *this;
	}
	TimeSpan AddSeconds(int seconds)
	{
		totalMilliseconds += seconds * 1000;

		return *this;
	}
	TimeSpan AddMilliseconds(int milliseconds)
	{
		totalMilliseconds += milliseconds;

		return *this;
	}


	string ToString()
	{
		string str;
		str = to_string(GetDays()) + to_string(totalMilliseconds / 1000 / 60 / 60 % 24) + to_string(totalMilliseconds / 1000 / 60 % 60)
			+ to_string(totalMilliseconds / 1000 % 60) + to_string(totalMilliseconds % 1000);

		return str;
	}
	string ToString(
		string daysSeparator,
		string timeSeparator,
		string millisecondsSeparator)
	{
		string str;
		str = to_string(GetDays())+ daysSeparator + to_string(totalMilliseconds / 1000 / 60 / 60 % 24) +
			to_string(totalMilliseconds / 1000 / 60 % 60) + to_string(totalMilliseconds / 1000 % 60) + timeSeparator +
			millisecondsSeparator + to_string(totalMilliseconds % 1000);

		return str;
	}
	string ToString(
		string daysHoursSeparator,
		string hoursMinutesSeparator,
		string minutesSecondsSeparator,
		string secondsMillisecondsSeparator)
	{
		string str;
		str = to_string(GetDays()) +  daysHoursSeparator + to_string(totalMilliseconds / 1000 / 60 / 60 % 24) +
			hoursMinutesSeparator+ to_string(totalMilliseconds / 1000 / 60 % 60) + minutesSecondsSeparator + to_string(totalMilliseconds / 1000 % 60) +
			secondsMillisecondsSeparator+ to_string(totalMilliseconds % 1000);

		return str;
	}

};

class DateTime
{
	unsigned short year;
	unsigned char month;
	unsigned char day;
	unsigned char hours;
	unsigned char minutes;
	unsigned char seconds;
	unsigned short milliseconds;

public:
	DateTime() : DateTime(0, 0, 0, 0, 0, 0, 0) {}

	DateTime(int year, int month, int day) : DateTime(year, month, day, 0, 0, 0, 0) {}

	DateTime(int year, int month, int day, int hours, int minutes, int seconds) : DateTime(year, month, day, hours, minutes, seconds, 0) {}

	DateTime(int year, int month, int day, int hours, int minutes, int seconds, int milliseconds) 
	{
		this->year = year;
		this->month = month;
		this->day = day;
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
		this->milliseconds = milliseconds;
	}

	int GetYear() const { return year; };
	int SetYear(int year) {	this->year = year; };

	int GetMonth() const { return month; };
	int SetMonth(int month) { this->month = month; };

	int GetDay() const { return day; };
	int SetDay(int day) { this->day = day; };

	int GetHours() const { return hours; };
	int SetHours(int hours) { this->hours = hours; };

	int GetMinutes() const { return minutes; };
	int SetMinutes(int minutes) { this->minutes = minutes; };

	int GetSeconds() const { return seconds; };
	int SetSeconds(int seconds) { this->seconds = seconds; };

	int GetMilliseconds() const { return milliseconds; };
	int SetMilliseconds(int milliseconds) { this->milliseconds = milliseconds; };


	DateTime operator+(const TimeSpan& right) const
	{
		DateTime temp(*this);
		temp.day += right.GetDays();
		if (temp.day >= 30)
		{
			temp.month += temp.day / 30;
			temp.day = temp.day % 30;
		}

		temp.hours += right.GetHours();
		if (temp.hours >= 24)
		{
			temp.day += temp.hours / 24;
			temp.hours = temp.hours % 24;
		}

		temp.minutes += right.GetMinutes();
		if (temp.minutes >= 60)
		{
			temp.hours += temp.minutes / 60;
			temp.minutes = temp.minutes % 60;
		}

		temp.seconds += right.GetSeconds();
		if (temp.seconds >= 60)
		{
			temp.minutes += temp.seconds / 60;
			temp.seconds = temp.seconds % 60;
		}

		temp.milliseconds += right.GetTotalMilliseconds();
		if (temp.seconds >= 1000)
		{
			temp.seconds += temp.milliseconds / 1000;
			temp.milliseconds = temp.milliseconds % 1000;
		}

		if (temp.day > 30)
		{
			temp.month += temp.day / 30;
			temp.day = temp.day % 30;
		}

		if (temp.month > 12)
		{
			temp.year += temp.month / 12;
			temp.month = temp.month % 12;
		}
		
		return temp;
	}

	friend DateTime operator+(const TimeSpan& left, const DateTime& right)
	{
		DateTime temp(right);
		temp.day += left.GetDays();
		if (temp.day >= 30)
		{
			temp.month += temp.day / 30;
			temp.day = temp.day % 30;
		}

		temp.hours += left.GetHours();
		if (temp.hours >= 24)
		{
			temp.day += temp.hours / 24;
			temp.hours = temp.hours % 24;
		}

		temp.minutes += left.GetMinutes();
		if (temp.minutes >= 60)
		{
			temp.hours += temp.minutes / 60;
			temp.minutes = temp.minutes % 60;
		}

		temp.seconds += left.GetSeconds();
		if (temp.seconds >= 60)
		{
			temp.minutes += temp.seconds / 60;
			temp.seconds = temp.seconds % 60;
		}

		temp.milliseconds += left.GetTotalMilliseconds();
		if (temp.seconds >= 1000)
		{
			temp.seconds += temp.milliseconds / 1000;
			temp.milliseconds = temp.milliseconds % 1000;
		}

		if (temp.day > 30)
		{
			temp.month += temp.day / 30;
			temp.day = temp.day % 30;
		}

		if (temp.month > 12)
		{
			temp.year += temp.month / 12;
			temp.month = temp.month % 12;
		}

		return temp;
	}

	TimeSpan operator-(const DateTime& right) const
	{
		TimeSpan temp;
		long long x = 0;
		x += (this->year - right.year) * 12 * 30 * 24 * 60 * 60 * 1000;
		x += (this->month - right.month) * 30 * 24 * 60 * 60 * 1000;
		x += (this->day - right.day) * 24 * 60 * 60 * 1000;
		x += (this->hours - right.hours) * 60 * 60 * 1000;
		x += (this->minutes - right.minutes) * 60 * 1000;
		x += (this->seconds - right.seconds) * 1000;
		x += (this->milliseconds - right.milliseconds);
		temp.AddMilliseconds(x);

		return temp;
	}
	
	DateTime operator-(const TimeSpan& right) const
	{
		DateTime temp(*this);
		temp.day -= right.GetDays();
		if (temp.day < 0)
		{
			temp.month -= temp.day / 30;
			temp.day = temp.day % 30;
		}

		temp.hours -= right.GetHours();
		if (temp.hours < 0)
		{
			temp.day -= temp.hours / 24;
			temp.hours = temp.hours % 24;
		}

		temp.minutes -= right.GetMinutes();
		if (temp.minutes < 0)
		{
			temp.hours -= temp.minutes / 60;
			temp.minutes = temp.minutes % 60;
		}

		temp.seconds -= right.GetSeconds();
		if (temp.seconds < 0)
		{
			temp.minutes -= temp.seconds / 60;
			temp.seconds = temp.seconds % 60;
		}

		temp.milliseconds -= right.GetTotalMilliseconds();
		if (temp.seconds < 0)
		{
			temp.seconds -= temp.milliseconds / 1000;
			temp.milliseconds = temp.milliseconds % 1000;
		}

		if (temp.day < 0)
		{
			temp.month -= temp.day / 30;
			temp.day = temp.day % 30;
		}

		if (temp.month < 0)
		{
			temp.year -= temp.month / 12;
			temp.month = temp.month % 12;
		}

		return temp;
	}

	friend DateTime operator-(const TimeSpan& left, const DateTime& right)
	{
		DateTime temp(right);
		temp.day -= left.GetDays();
		if (temp.day < 0)
		{
			temp.month -= temp.day / 30;
			temp.day = temp.day % 30;
		}

		temp.hours -= left.GetHours();
		if (temp.hours < 0)
		{
			temp.day -= temp.hours / 24;
			temp.hours = temp.hours % 24;
		}

		temp.minutes -= left.GetMinutes();
		if (temp.minutes < 0)
		{
			temp.hours -= temp.minutes / 60;
			temp.minutes = temp.minutes % 60;
		}

		temp.seconds -= left.GetSeconds();
		if (temp.seconds < 0)
		{
			temp.minutes -= temp.seconds / 60;
			temp.seconds = temp.seconds % 60;
		}

		temp.milliseconds -= left.GetTotalMilliseconds();
		if (temp.seconds < 0)
		{
			temp.seconds -= temp.milliseconds / 1000;
			temp.milliseconds = temp.milliseconds % 1000;
		}

		if (temp.day < 0)
		{
			temp.month -= temp.day / 30;
			temp.day = temp.day % 30;
		}

		if (temp.month < 0)
		{
			temp.year -= temp.month / 12;
			temp.month = temp.month % 12;
		}

		return temp;
	}

	string ToString() const
	{
		string str;
		str = to_string(year) + "." + to_string(month) + ":" + to_string(day) + "T"
			+ to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds)
			+ "." + to_string(milliseconds);

		return str;
	}
};

void main()
{
	DateTime dt1(2024, 05, 25);
	DateTime dt2(2024, 05, 24);
	DateTime dt3(2024, 05, 24, 23, 59, 59);
	DateTime dt4(2024, 05, 24, 23, 59, 59, 999);
	DateTime dt5(2024, 05, 25, 0, 0, 1);
	DateTime dt6(2024, 05, 25, 0, 0, 0, 1);
	DateTime dt7(2024, 05, 24, 1, 1, 1, 1);
	DateTime dt8(2024, 05, 25, 1, 1, 1, 1);

	TimeSpan ts1(0, 0, 0, 1);
	TimeSpan ts2(0, 0, 0, -1);
	TimeSpan ts3(0, 0, 1, 0);
	TimeSpan ts4(0, 0, -1, 0);
	TimeSpan ts5(0, 1, 0, 0);
	TimeSpan ts6(0, -1, 0, 0);
	TimeSpan ts7(1, 0, 0, 0);
	TimeSpan ts8(-1, 0, 0, 0);
	TimeSpan ts9(100, 0, 0, 0);
	TimeSpan ts0(-100, 0, 0, 0);

	cout << endl << "DateTime - DateTime" << endl;
	cout << dt1.ToString() << " - " << dt1.ToString() << " = " << (dt1 - dt1).ToString(".", ":", ":", ".") << endl;
	cout << dt1.ToString() << " - " << dt2.ToString() << " = " << (dt1 - dt2).ToString(".", ":", ":", ".") << endl;
	cout << dt1.ToString() << " - " << dt3.ToString() << " = " << (dt1 - dt3).ToString(".", ":", ":", ".") << endl;
	cout << dt1.ToString() << " - " << dt4.ToString() << " = " << (dt1 - dt4).ToString(".", ":", ":", ".") << endl;
	cout << dt1.ToString() << " - " << dt5.ToString() << " = " << (dt1 - dt5).ToString(".", ":", ":", ".") << endl;
	cout << dt1.ToString() << " - " << dt6.ToString() << " = " << (dt1 - dt6).ToString(".", ":", ":", ".") << endl;
	cout << dt1.ToString() << " - " << dt7.ToString() << " = " << (dt1 - dt7).ToString(".", ":", ":", ".") << endl;
	cout << dt1.ToString() << " - " << dt8.ToString() << " = " << (dt1 - dt8).ToString(".", ":", ":", ".") << endl;

	cout << endl << "DateTime + TimeSpan" << endl;
	cout << dt1.ToString() << " + " << ts1.ToString(".", ":", ":", ".") << " = " << (dt1 + ts1).ToString() << endl;
	cout << dt1.ToString() << " + " << ts2.ToString(".", ":", ":", ".") << " = " << (dt1 + ts2).ToString() << endl;
	cout << dt1.ToString() << " + " << ts3.ToString(".", ":", ":", ".") << " = " << (dt1 + ts3).ToString() << endl;
	cout << dt1.ToString() << " + " << ts4.ToString(".", ":", ":", ".") << " = " << (dt1 + ts4).ToString() << endl;
	cout << dt1.ToString() << " + " << ts5.ToString(".", ":", ":", ".") << " = " << (dt1 + ts5).ToString() << endl;
	cout << dt1.ToString() << " + " << ts6.ToString(".", ":", ":", ".") << " = " << (dt1 + ts6).ToString() << endl;
	cout << dt1.ToString() << " + " << ts7.ToString(".", ":", ":", ".") << " = " << (dt1 + ts7).ToString() << endl;
	cout << dt1.ToString() << " + " << ts8.ToString(".", ":", ":", ".") << " = " << (dt1 + ts8).ToString() << endl;
	cout << dt1.ToString() << " + " << ts9.ToString(".", ":", ":", ".") << " = " << (dt1 + ts9).ToString() << endl;
	cout << dt1.ToString() << " + " << ts0.ToString(".", ":", ":", ".") << " = " << (dt1 + ts0).ToString() << endl;

	cout << endl << "DateTime - TimeSpan" << endl;
	cout << dt1.ToString() << " - " << ts1.ToString(".", ":", ":", ".") << " = " << (dt1 - ts1).ToString() << endl;
	cout << dt1.ToString() << " - " << ts2.ToString(".", ":", ":", ".") << " = " << (dt1 - ts2).ToString() << endl;
	cout << dt1.ToString() << " - " << ts3.ToString(".", ":", ":", ".") << " = " << (dt1 - ts3).ToString() << endl;
	cout << dt1.ToString() << " - " << ts4.ToString(".", ":", ":", ".") << " = " << (dt1 - ts4).ToString() << endl;
	cout << dt1.ToString() << " - " << ts5.ToString(".", ":", ":", ".") << " = " << (dt1 - ts5).ToString() << endl;
	cout << dt1.ToString() << " - " << ts6.ToString(".", ":", ":", ".") << " = " << (dt1 - ts6).ToString() << endl;
	cout << dt1.ToString() << " - " << ts7.ToString(".", ":", ":", ".") << " = " << (dt1 - ts7).ToString() << endl;
	cout << dt1.ToString() << " - " << ts8.ToString(".", ":", ":", ".") << " = " << (dt1 - ts8).ToString() << endl;
	cout << dt1.ToString() << " - " << ts9.ToString(".", ":", ":", ".") << " = " << (dt1 - ts9).ToString() << endl;
	cout << dt1.ToString() << " - " << ts0.ToString(".", ":", ":", ".") << " = " << (dt1 - ts0).ToString() << endl;


	cout << endl << "DateTime - TimeSpan + TimeSpan" << endl;
	cout << dt1.ToString() << " - " << ts1.ToString(".", ":", ":", ".") << " + " << ts1.ToString(".", ":", ":", ".") << " = " << (dt1 - ts1 + ts1).ToString() << endl;
	cout << dt1.ToString() << " - " << ts2.ToString(".", ":", ":", ".") << " + " << ts2.ToString(".", ":", ":", ".") << " = " << (dt1 - ts2 + ts2).ToString() << endl;
	cout << dt1.ToString() << " - " << ts3.ToString(".", ":", ":", ".") << " + " << ts3.ToString(".", ":", ":", ".") << " = " << (dt1 - ts3 + ts3).ToString() << endl;
	cout << dt1.ToString() << " - " << ts4.ToString(".", ":", ":", ".") << " + " << ts4.ToString(".", ":", ":", ".") << " = " << (dt1 - ts4 + ts4).ToString() << endl;
	cout << dt1.ToString() << " - " << ts5.ToString(".", ":", ":", ".") << " + " << ts5.ToString(".", ":", ":", ".") << " = " << (dt1 - ts5 + ts5).ToString() << endl;
	cout << dt1.ToString() << " - " << ts6.ToString(".", ":", ":", ".") << " + " << ts6.ToString(".", ":", ":", ".") << " = " << (dt1 - ts6 + ts6).ToString() << endl;
	cout << dt1.ToString() << " - " << ts7.ToString(".", ":", ":", ".") << " + " << ts7.ToString(".", ":", ":", ".") << " = " << (dt1 - ts7 + ts7).ToString() << endl;
	cout << dt1.ToString() << " - " << ts8.ToString(".", ":", ":", ".") << " + " << ts8.ToString(".", ":", ":", ".") << " = " << (dt1 - ts8 + ts8).ToString() << endl;
	cout << dt1.ToString() << " - " << ts9.ToString(".", ":", ":", ".") << " + " << ts9.ToString(".", ":", ":", ".") << " = " << (dt1 - ts9 + ts9).ToString() << endl;
	cout << dt1.ToString() << " - " << ts0.ToString(".", ":", ":", ".") << " + " << ts0.ToString(".", ":", ":", ".") << " = " << (dt1 - ts0 + ts0).ToString() << endl;

	system("pause");
}