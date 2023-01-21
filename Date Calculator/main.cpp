#include <iostream>
using namespace std;

int Vyear(int Year)
{
	int days = 0;
	if (Year % 4 == 0 || Year % 400 == 0)
		days = 366;
	else
		days = 365;
	return days;
}
void DateDifference(int dayB, int monthB, int YearB, int dayE, int monthE, int YearE)
{
	const int N = 12;
	int YearToDays = 0;
	int MonthToDaysB = 0;
	int MonthToDaysE = 0;
	int difference = 0;
	int arr[N]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int countY = YearB + 1; countY < YearE; countY++)
		YearToDays += Vyear(countY);
	if (YearB != YearE)
	{
		for (int countM = monthB - 1; countM < N; countM++)
			MonthToDaysB += arr[countM];
	}
	MonthToDaysB -= dayB;
	for (int countM = 0; countM < monthE - 1; countM++)
		MonthToDaysE += arr[countM];
	MonthToDaysE += dayE;
	difference = YearToDays + MonthToDaysB + MonthToDaysE;
	cout << endl << "Difference is: " << difference << " days";
}
int main()
{
	int dayB = 0, monthB = 0, YearB = 0, dayE = 0, monthE = 0, YearE = 0;
	char choose{ 0 };
	do
	{
		cout << "Enter Date begin: " << endl
			<< "Day Begin: ";
		cin >> dayB;
		cout << "Month Begin: ";
		cin >> monthB;
		cout << "Year Begin: ";
		cin >> YearB;
		cout << "Enter Date End: " << endl
			<< "Day End: ";
		cin >> dayE;
		cout << "Month End: ";
		cin >> monthE;
		cout << "Year End: ";
		cin >> YearE;
		DateDifference(dayB, monthB, YearB, dayE, monthE, YearE);
		cout << endl << "Continue? Y/N: ";
		cin >> choose;
		system("CLS");
	} while (choose == 'Y' || choose == 'y');
	return 0;
}