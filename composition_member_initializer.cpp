//HEADER DATE
#ifndef DATE_H
#define DATE_H
 
class Date
{
    public:
        Date( int = 1, int = 1, int = 1900 ); // default constructor
        void print() const;  // print date in month/day/year format
        ~Date();  // provided to confirm destruction order
 
    private:
        int month;  // 1-12 (January-December)
        int day;    // 1-31 based on month
        int year;   // any year
        // utility function to test proper day for month and year
        int checkDay( int ) const;
};
 
#endif

//DATE DEFINITION

#include <iostream>
 
using std::cout;
using std::endl;
 
// include Date class definition from date1.h
#include "date.h"
 
// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date( int mn, int dy, int yr )
{
    if ( mn > 0 && mn <= 12 )  // validate the month
        month = mn;
    else
    {                     // invalid month set to 1
        month = 1;
        cout << "Month " << mn << " invalid. Set to month 1.\n";
    }
    year = yr;                 // should validate yr
    day = checkDay( dy );      // validate the day
    // output Date object to show when its constructor is called
    cout << "Date object constructor for date ";
    print();
    cout << endl;
}
 
// print Date object in form month/day/year
void Date::print() const
{
    cout << month << '/' << day << '/' << year;
}
 
// output Date object to show when its destructor is called
Date::~Date()
{
    cout << "Date object destructor for date ";
    print();
    cout << endl;
}

// utility function to confirm proper day value based on
// month and year; handles leap years, too
int Date::checkDay( int testDay ) const
{
    static const int daysPerMonth[ 13 ] =
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
 
    // determine whether testDay is valid for specified month
    if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
        return testDay;
 
    // February 29 check for leap year
    if ( month == 2 && testDay == 29 && ( year % 400 == 0 ||
            ( year % 4 == 0 && year % 100 != 0 ) ) )
        return testDay;
 
    cout << "Day " << testDay << " invalid. Set to day 1.\n";
 
    return 1;  // leave object in consistent state if bad value
}

//HEADER EMPLOYEE
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
 
// include Date class definition from date1.h
#include "date.h"
 
class Employee
{
    public:
        Employee( const char *, const char *, const Date &, const Date & );
        void print() const;
        ~Employee();  // provided to confirm destruction order
 
    private:
        char firstName[ 25 ];
        char lastName[ 25 ];
        const Date birthDate;  // composition: member object
        const Date hireDate;   // composition: member object
};
 
#endif

//EMPLOYEE DEFINITION
#include <iostream>
#include <cstring>      // strcpy and strlen prototypes
 
using std::cout;
using std::endl;
 
#include "employee.h"  // Employee class definition
#include "date.h"      // Date class definition
 
// constructor uses member initializer list to pass initializer values to
// constructors of member objects birthDate and hireDate [This invokes the so-
// called "default copy constructor" which the C++ compiler provides implicitly.] 
Employee::Employee( const char *first, const char *last, const Date &dateOfBirth,
    const Date &dateOfHire )
        : birthDate( dateOfBirth ),  // initialize birthDate
          hireDate( dateOfHire )     // initialize hireDate
{
    // copy first into firstName and be sure that it fits
    int length = strlen( first );
    length = ( length < 25 ? length : 24 );
    strncpy( firstName, first, length );
    firstName[ length ] = '\0';
 
    // copy last into lastName and be sure that it fits
    length = strlen( last );
    length = ( length < 25 ? length : 24 );
    strncpy( lastName, last, length );
    lastName[ length ] = '\0';
    // output Employee object to show when constructor is called
    cout << "Employee object constructor: "
         << firstName << ' ' << lastName << endl;
}
 
// print Employee object
void Employee::print() const
{
    cout << lastName << ", " << firstName << "\nHired: ";
    hireDate.print();
    cout << "  Birth date: ";
    birthDate.print();
    cout << endl;
}
 
// output Employee object to show when its destructor is called
Employee::~Employee()
{
    cout << "Employee object destructor: "
         << lastName << ", " << firstName << endl;
}

//CPP
#include <iostream>
using std::cout;
using std::endl;
 
#include "employee.h"  // Employee class definition
 
int main()
{
    Date birth( 7, 24, 1949 );
    Date hire( 3, 12, 1988 );
    Employee manager( "Bob", "Jones", birth, hire );
 
    cout << '\n';
    manager.print();
 
    cout << "\nTest Date constructor with invalid values:\n";
    Date lastDayOff( 14, 35, 1994 );  // invalid month and day
    cout << endl;
 
    return 0;
}

/*****************************************

Date object constructor for date 7/24/1949
Date object constructor for date 3/12/1988
Employee object constructor: Bob Jones
  
Jones, Bob
Hired: 3/12/1988  Birth date: 7/24/1949
  
Test Date constructor with invalid values:
Month 14 invalid. Set to month 1.
Day 35 invalid. Set to day 1.
Date object constructor for date 1/1/1994
  
Date object destructor for date 1/1/1994
Employee object destructor: Jones, Bob
Date object destructor for date 3/12/1988
Date object destructor for date 7/24/1949
Date object destructor for date 3/12/1988
Date object destructor for date 7/24/1949

****************************************/