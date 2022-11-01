#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <string>
#include "Clock.h"
using namespace std;

int main()
{
	// Setting Rand Seed
	srand(177);
	
	// Declaring Clock Pointer with 200 Clock Objects using Default Parameters
	Clock* clock = new Clock[200];
	

	// Iteration through 200 Clock Objects and Setting Time Values using modified random numbers
	for (int i = 0; i < 200; i++)
	{
		int randomHour = ((rand() % 24) * 100) + 1;	// Random Hour (1 to 24) and multiplying it by 100
		int randomMin = rand() % 59;				// Random Amount of Minutes (0 to 59)
		clock[i].setTime(randomHour + randomMin);	// Combining Hour and Minute variables to Create a Valid Time Parameter
		
		// Outputting of Clock Index, Time and Largest Angle
		cout << i << ": "; clock[i].printTime(); cout << "\tLargest Angle : " << clock[i].calcAngle() << endl;
	}

}