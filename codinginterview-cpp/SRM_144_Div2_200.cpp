#include <iostream>
#include <sstream>

using namespace std;

class Time
{
public:
	string whatTime(int seconds)
	{
		int hours = seconds / 3600;
		seconds -= hours * 3600;
		int minutes = seconds / 60;
		seconds -= minutes * 60;
		ostringstream os;
		os << hours << ":" << minutes << ":" << seconds;

		return os.str();
	}
};

int SRM_144_Div2_200()
{
	Time time;
	cout << time.whatTime(0) << endl;
	cout << time.whatTime(3661) << endl;
	cout << time.whatTime(5436) << endl;
	cout << time.whatTime(86399) << endl;

	int test;
	cin >> test;

	return 0;
}