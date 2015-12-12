//HEADER
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
 
class Employee
{
    public:
        Employee( const char *, const char * );  // constructor
        ~Employee();                       // destructor
        const char *getFirstName() const;  // return first name
        const char *getLastName() const;   // return last name
 
        // static member function
        static int getCount();  // return # objects instantiated
 
    private:
        char *firstName;
        char *lastName;
 
        // static data member
        static int count;  // number of objects instantiated
};
 
#end if

//DEFINITION
#include <iostream>
#include <new>          // C++ standard new operator
#include <cstring>      // strcpy and strlen prototypes
 
using std::cout;
using std::endl;
 
#include "employee.h"  // Employee class definition
 
// define and initialize static data member
int Employee::count = 0;
 
// define static member function that returns number of
// Employee objects instantiated
int Employee::getCount()
{
    return count;
}
 
// constructor dynamically allocates space for first and last name and 
// uses strcpy to copy first and last names into the object                 
Employee::Employee( const char *first, const char *last )
{
    firstName = new char[ strlen( first ) + 1 ];
    strcpy( firstName, first );
    lastName = new char[ strlen( last ) + 1 ];
    strcpy( lastName, last );
 
    ++count;  // increment static count of employees
 
    cout << "Employee constructor for " << firstName
         << ' ' << lastName << " called." << endl;
}
 
// destructor deallocates dynamically allocated memory
Employee::~Employee()
{
    cout << "~Employee() called for " << firstName << ' ' << lastName << endl;
 
    delete [] firstName;  // recapture memory
    delete [] lastName;   // recapture memory
    --count;  // decrement static count of employees
}
 
// return first name of employee
const char *Employee::getFirstName() const
{
    return firstName;
}

// return last name of employee
const char *Employee::getLastName() const
{
    return lastName;
}

//CPP
#include <iostream>
#include <new>          // C++ standard new operator
 
using std::cout;
using std::endl;
 
#include "employee.h"  // Employee class definition
 
int main()
{
    cout << "Number of employees before instantiation is "
         << Employee::getCount() << endl;   // use class name
 
    Employee *e1Ptr = new Employee( "Susan", "Baker" );
    Employee *e2Ptr = new Employee( "Robert", "Jones" );
 
    cout << "Number of employees after instantiation is " << e1Ptr->getCount(); // static member function can be invoked on any object of class
 
    cout << "\n\nEmployee 1: " << e1Ptr->getFirstName() << " " 
         << e1Ptr->getLastName()
         << "\nEmployee 2: " << e2Ptr->getFirstName() << " "
         << e2Ptr->getLastName() << "\n\n";

    delete e1Ptr;  // recapture memory
    e1Ptr = 0;     // disconnect pointer from free-store space
    delete e2Ptr;  // recapture memory
    e2Ptr = 0;     // disconnect pointer from free-store space
 
    cout << "Number of employees after deletion is "
         << Employee::getCount() << endl; // static member function invoked using binary scope resolution operator (no existing class objects)
 
    return 0;
}

/********************************************

Number of employees before instantiation is 0
Employee constructor for Susan Baker called.
Employee constructor for Robert Jones called.
Number of employees after instantiation is 2
 
Employee 1: Susan Baker
Employee 2: Robert Jones
 
~Employee() called for Susan Baker
~Employee() called for Robert Jones
Number of employees after deletion is 0

********************************************/