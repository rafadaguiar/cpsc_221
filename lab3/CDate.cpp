// ..................................................  
// CPSC221 Lab 2: CDate lab exercise
// Adapted from Hagit Schechter, Jan 2007
// ..................................................

#include <iostream>
#include <string>
#include "CDate.h"

using namespace std;

CDate::CDate( void )
{
	m_year = m_month = m_day = 0;
}

CDate::CDate( int year, int month, int day )
{
	setDate( year, month, day );        
}

CDate::CDate( int year, string month, int day )
{
	setDate( year, month, day );    
}

bool CDate::isValidDate( int year, int month, int day )
{
	return (year > 0) and (1 <= month <= 12) and isValidDay(year,month,day);
}

bool CDate::isValidDate( int year, string month, int day)
{
	int month_num = monthStr2Num(month); 
	return (year > 0) and (1 <= month_num <= 12) and isValidDay(year,month_num,day);
}

int CDate::monthStr2Num(string month)
{	
	int month_num;
	
	if(month == "January") month_num = 1;
	if(month == "February") month_num = 2;
	if(month == "March") month_num = 3;
	if(month == "April") month_num = 4;
	if(month == "May") month_num = 5;
	if(month == "June") month_num = 6;
	if(month == "July") month_num = 7;
	if(month == "August") month_num = 8;
	if(month == "September") month_num = 9;
	if(month == "October") month_num = 10;
	if(month == "November") month_num = 11;
	if(month == "December") month_num = 12;
	
	return month_num;
}

bool CDate::isValidDay(int year, int month, int day)
{
	if ((day<1) || (day>31)) return false;

	bool valid;

	switch (month) {
		case 1: valid = true;break;
		case 3: valid = true;break;
		case 5: valid = true;break;
		case 7: valid = true;break;
		case 8: valid = true;break;
		case 10: valid = true;break;
		case 12: valid = true;break;
		case 2:
			// Don't worry about this code too much.
			// It handles all the leap year rules for February.
			if ((year % 4) != 0) {
				valid = (day <=28);
			} else if ((year % 400) == 0) {
				valid = (day <= 29);
			} else if ((year % 100) == 0) {
				valid = (day <= 28);
			} else {
				valid = (day <= 29);
			}
			break;
		case 4: valid = (day < 31);break;
		case 6: valid = (day < 31);break;
		case 9: valid = (day < 31);break;
		case 11: valid = (day < 31);break;
	}
	return valid;
}

void CDate::setDate( int year, int month, int day )
{
	if( isValidDate( year, month, day ) )
	{    
		m_year = year;
		m_month = month;
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}
}


void CDate::setDate( int year, string month, int day )
{
	if( isValidDate( year, month, day ) )
	{    
		m_year = year;
		m_month = monthStr2Num(month);
		m_day = day;
	}
	else {
		m_year = m_month = m_day = 0;
	}

}

void CDate::print( void )
{
	cout << m_day << "/" << m_month << "/" << m_year << endl;
}

// main
int main(void)
{
	CDate myDate0(2000,5,25);
	CDate myDate1(-1,"May",25);
	CDate myDate2(2000,"April",31);
	CDate myDate3(2001,"February",29);
	CDate myDate4(2000,"February",29);
	CDate myDate5(2000,"December",32);
	CDate myDate6(2000,"December",31);
	CDate myDate7(2000,"November",31);
	CDate myDate8(2000,"November",30);

	myDate0.print();
	myDate1.print();
	myDate2.print();
	myDate3.print();
	myDate4.print();
	myDate5.print();
	myDate6.print();
	myDate7.print();
	myDate8.print();

#ifdef _WIN32
	system("PAUSE"); // needed for windows to prevent the program from terminating and the command window to close
#endif

	return 0;
}
