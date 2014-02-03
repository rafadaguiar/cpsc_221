// ...........................................................
// Lab 2:        Date class definition
// Author:       Kimberly Voll, January 2008
// ...........................................................

#ifndef _DATE_
#define _DATE_

#include <string>
using namespace std;


class CDate
{
public:
	CDate( void );
	CDate( int year, int month, int day );
	CDate( int year, string month, int day );
	void setDate( int year, int month, int day );
	void setDate( int year, string month, int day );
	bool isValidDate( int year, int month, int day );
	bool isValidDate( int year, string month, int day );
	void print( void );

private:
	int m_year;
	int m_month;
	int m_day;

	int monthStr2Num(string month);
	bool isValidDay(int year, int month, int day);

};

#endif
