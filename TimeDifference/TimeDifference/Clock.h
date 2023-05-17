class Clock
{
private:

	// Declaring Clock Degree Range Variables
	const int RANGE = 360;	// Clock has 360 degrees
	const int HOUR = 30;	// 30 Degrees per hour   360/12 = 30
	const int MINUTE = 6;	// 6 Degrees per minute  360/60 = 6


	int hour;				// Declaration of hour variable
	int minutes;			// Declaration of minute variable
	bool isConverted;		// Variable for Conversion Verification

	// Private Function Declarations
	void ConvertTime(int& hour);
	bool validateTime(int time);

public:
	Clock();				// Default Constructor
	Clock(int time);		// Constructor with time parameter
	bool setTime(int time);	// Time Setting Function
	int calcAngle();		// Angle Calculation Function
	void printTime();		// toString Function
};
