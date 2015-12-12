//HEADER
#ifndef TIME_H
#define TIME_H
 
class Time
{
    public:
        Time( int = 0, int = 0, int = 0 );  // default constructor
        // set functions
        void setTime( int, int, int );  // set hour, minute, second
        void setHour( int );   // set hour
        void setMinute( int ); // set minute
        void setSecond( int ); // set second
        // get functions
        int getHour();         // return hour
        int getMinute();       // return minute
        int getSecond();       // return second
        void printUniversal(); // output universal-time format
        void printStandard();  // output standard-time format
 
    private:
        int hour;              // 0 - 23 (24-hour clock format)
        int minute;            // 0 – 59
        int second;            // 0 – 59
};
#endif

//CLASS DEFINIYION
#include <iostream>
#include <iomanip>
using std::cout;
using std::setfill;
using std::setw;

#include "time.h"
 
// constructor function to initialize private data.
// calls member function setTime to set variables.
// default values are 0 (see class definition)
Time::Time( int hr, int min, int sec )
{
    setTime( hr, min, sec );
} // end Time constructor
 
// set hour, minute and second values
void Time::setTime( int h, int m, int s )
{
    setHour( h );
    setMinute( m );
    setSecond( s );
}

// set hour value
void Time::setHour( int h )
{
    hour = ( h >= 0 && h < 24 ) ? h : 0;
}
 
// set minute value
void Time::setMinute( int m )
{
    minute = ( m >= 0 && m < 60 ) ? m : 0;
}
 
// set second value
void Time::setSecond( int s )
{
    second = ( s >= 0 && s < 60 ) ? s : 0;
}
 
// return hour value
int Time::getHour()
{
    return hour;
}
 
// return minute value
int Time::getMinute()
{
    return minute;
}

// return second value
int Time::getSecond()
{
    return second;
}
 
// print Time in universal format
void Time::printUniversal()
{
    cout << setfill( '0' ) << setw( 2 ) << hour << ":“ << setw( 2 )
         << minute << ":“ << setw( 2 ) << second;
}
 
// print Time in standard format
void Time::printStandard()
{
    cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 )
         << ":" << setfill( '0' ) << setw( 2 ) << minute
         << ":" << setw( 2 ) << second 
         << ( hour < 12 ? " AM" : " PM" );
}

//CPP

#include <iostream>
 
using std::cout;
using std::endl;
 
// include definition of class Time from time.h
#include "time.h"
 
void incrementMinutes( Time &, const int );  // prototype
 
int main()
{
    Time t;              // create Time object
 
    // set time using individual set functions
    t.setHour( 17 );     // set hour to valid value
    t.setMinute( 34 );   // set minute to valid value
    t.setSecond( 25 );   // set second to valid value
 
    // use get functions to obtain hour, minute and second
    cout << "Result of setting all valid values:\n" << "  Hour: " << t.getHour()
         << "  Minute: " << t.getMinute() << "  Second: " << t.getSecond();
    // set time using individual set functions
    t.setHour( 234 );    // invalid hour set to 0    
    t.setMinute( 43 );   // set minute to valid value
    t.setSecond( 6373 ); // invalid second set to 0  
 
    // display hour, minute and second after setting invalid hour and second values
    cout << "\n\nResult of attempting to set invalid hour and"
         << " second:\n  Hour: " << t.getHour() << "  Minute: " << t.getMinute()
         << "  Second: " << t.getSecond() << "\n\n";
 
    t.setTime( 11, 58, 0 );    // set time
    incrementMinutes( t, 3 );  // increment t's minute by 3
 
    return 0;
}

// add specified number of minutes to a Time object
void incrementMinutes( Time &tt, const int count )
{
    cout << "Incrementing minute " << count << " times:\nStart time: ";
    tt.printStandard();
 
    for ( int i = 0; i < count; i++ )
    {
        tt.setMinute( ( tt.getMinute() + 1 ) % 60 );
 
        if ( tt.getMinute() == 0 )
            tt.setHour( ( tt.getHour() + 1 ) % 24);
 
        cout << "\nminute + 1: ";
        tt.printStandard();
    }
 
    cout << endl;
}

/****************************************************

Result of setting all valid values:
  Hour: 17  Minute: 34  Second: 25
 
Result of attempting to set invalid hour and second:
  Hour: 0  Minute: 43  Second: 0
 
Incrementing minute 3 times:
Start time: 11:58:00 AM
minute + 1: 11:59:00 AM
minute + 1: 12:00:00 PM
minute + 1: 12:01:00 PM

*****************************************************/