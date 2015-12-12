//HEADER
#ifndef TIME_H
#define TIME_H
 
class Time
{
    public:
        Time( int = 0, int = 0, int = 0 );  // default constructor
 
        Time &setTime( int, int, int ); // set hour, minute, second
        Time &setHour( int );    // set hour
        Time &setMinute( int );  // set minute
        Time &setSecond( int );  // set second
 
        int getHour() const;     // return hour
        int getMinute() const;   // return minute
        int getSecond() const;   // return second
 
        void printUniversal() const;  // print universal time
        void printStandard() const;   // print standard time
 
    private:
        int hour;    // 0 - 23 (24-hour clock format)
        int minute;  // 0 – 59
        int second;  // 0 – 59
};
#endif

//DEFINITION
#include <iostream>
#include <iomanip>
 
using std::cout;
using std::setfill;
using std::setw;
 
#include "time.h"
 
// constructor function to initialize private data;
// calls member function setTime to set variables;
// default values are 0 (see class definition)
Time::Time( int hr, int min, int sec )
{
    setTime( hr, min, sec );
}
 
Time &Time::setTime( int h, int m, int s )
{
    setHour( h );
    setMinute( m );
    setSecond( s );
 
    return *this;   // enables cascading
}

Time &Time::setHour( int h )
{
    hour = ( h >= 0 && h < 24 ) ? h : 0;
 
    return *this;   // enables cascading
}
 
Time &Time::setMinute( int m )
{
    minute = ( m >= 0 && m < 60 ) ? m : 0;
 
    return *this;   // enables cascading
} // end function setMinute
 
Time &Time::setSecond( int s )
{
    second = ( s >= 0 && s < 60 ) ? s : 0;
 
    return *this;   // enables cascading
}
 
int Time::getHour() const 
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}
 
int Time::getSecond() const
{
    return second;
}
 
void Time::printUniversal() const
{
    cout << setfill( '0' ) << setw( 2 ) << hour << ":“ << setw( 2 ) 
         << minute << ":“ << setw( 2 ) << second;
}
 
void Time::printStandard() const
{
    cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 ) 
         << ":" << setfill( '0' ) << setw( 2 ) << minute << ":" 
         << setw( 2 ) << second << ( hour < 12 ? " AM" : " PM" );
}

//CPP
#include <iostream>
 
using namespace std;
 
#include "time.h"  // Time class definition
 
int main()
{
    Time t;
 
    // cascaded function calls
    t.setHour( 18 ).setMinute( 30 ).setSecond( 22 );
 
    cout << "Universal time: ";
    t.printUniversal();
    cout << "\nStandard time: ";
    t.printStandard();
    cout << "\n\nNew standard time: ";
    t.setTime( 20, 20, 20 ).printStandard();
    cout << endl;
 
    return 0;
}

/*****************************

Universal time: 18:30:22
Standard time: 6:30:22 PM
 
New standard time: 8:20:20 PM

*****************************/