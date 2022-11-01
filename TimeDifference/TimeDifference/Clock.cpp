#include "Clock.h"
#include <iostream>
#include <string>
using namespace std;

// Clock Default Constructor
Clock::Clock()
{
	isConverted = false;
	hour = 0;
	minutes = 0;
};

// Clock Constructor with Time Initialisation
Clock::Clock(int time)
{
	isConverted = false;
	hour = 0;
	minutes = 0;
	setTime(time);
}


// Setting Clock Time
bool Clock::setTime(int time) 
{
	int h = 0;
	int min = 0;
	if (validateTime(time))
	{
		h = time / 100;
		ConvertTime(h);
		min = time % 100;
		hour = h;
		minutes = min;
	}
	else
	{
		exit(3); // Exit Due to Invlalid Initialisation Parameters
	}
	return true;
}

// Calculation of Largest Angle
int Clock::calcAngle()
{
	int hourAngle = hour * HOUR;
	int minuteAngle = minutes * MINUTE;
	int Angle1 = hourAngle - minuteAngle;
	int Angle2 = minuteAngle - hourAngle;
	int positiveAngle = (Angle1 > Angle2) ? Angle1 : Angle2;
	int oppositeAngle = 360 - positiveAngle;



	return (positiveAngle > oppositeAngle) ? positiveAngle : oppositeAngle;

};

// Time Validation Function
bool Clock::validateTime(int time)
{
	if (time < 0 || time > 2359)
	{
		cout << "Time is Invalid\tResult: " << time;
		return false;
	}
	int h = time / 100;
	int m = time % 100;

	if (h < 0 || h > 23)
	{
		cout << "Hour is Invalid\tResult: " << h;
		return false;
	}
	if (m < 0 || m > 59)
	{
		cout << "Minute is Invalid\tResult: " << m;
		return false;
	}

	return true;
}

// Conversion from AM to PM for the Hour Hand
void Clock::ConvertTime(int& hourRef)
{
	if (hourRef > 12)
	{
		hourRef = hourRef - 12;
		isConverted = true;
		return;
	}
	isConverted = false;
	
}

// Printing Time in a Formatted String
void Clock::printTime()
{
	string outTxt = "";

	if (hour < 10)
	{
		outTxt += "0";
		outTxt += to_string(hour);
	}
	else
	{
		outTxt += to_string(hour);
	}

	outTxt += ":";

	if (minutes < 10)
	{
		outTxt += "0";
		outTxt += to_string(minutes);
	}
	else
	{
	outTxt += to_string(minutes);
	}
	if (isConverted) outTxt += "PM";
	else outTxt += "AM";
	
	cout << outTxt;
}

