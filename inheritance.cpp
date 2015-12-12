//HEADER POINT
#ifndef POINT_H
#define POINT_H
 
class Point
{
    public:
        Point( int = 0, int = 0 ); // default constructor
 
        void setX( int );          // set x in coordinate pair
        int getX() const;          // return x from coordinate pair
        void setY( int );          // set y in coordinate pair
        int getY() const;          // return y from coordinate pair
 
        void print() const;        // output Point object
 	/*
 	Better engineering practice: private over protected when possible
 	*/
    private:
        int x;  // x part of coordinate pair
        int y;  // y part of coordinate pair
};
 
#endif

//POINT DEFINITION
#include <iostream>
 
using std::cout;
 
#include "point.h"
 
// default constructor
Point::Point( int xValue, int yValue )
	/*
	Member initializers specify values of x and y
	*/
    : x( xValue ), y( yValue )
{
    // empty body
}
 
// set x in coordinate pair
void Point::setX( int xValue )
{
    x = xValue; // no need for validation
}
 
// return x from coordinate pair
int Point::getX() const
{
    return x;
}

// set y in coordinate pair
void Point::setY( int yValue )
{
    y = yValue; // no need for validation
}
 
// return y from coordinate pair
int Point::getY() const
{
    return y;
}
 
// output Point object
void Point::print() const
{
    cout << '[' << x << ", " << y << ']';
}

//HEADER CIRCLE
#ifndef CIRCLE_H
#define CIRCLE_H
 
#include "point.h"

/*
Class Circle inherits from class Point
*/
class Circle : public Point
{
    public:
        Circle( int = 0, int = 0, double = 0.0 );
 
        void setRadius( double );   // set radius
        double getRadius() const;   // return radius
        double getDiameter() const;       // return diameter
        double getCircumference() const;  // return circumference
        double getArea() const;           // return area
 
        void print() const;         // output Circle2 object
 
    private:
    	/*
    	Maintain private data member radius
    	*/
        double radius; // Circle's radius
};

#endif

//CIRCLE DEFINITION
#include <iostream>
 
using std::cout;
 
#include "circle.h"   // Circle class definition
 
Circle::Circle( int xValue, int yValue, double radiusValue )
	/*
	Base-class initializer syntax passes arguments to base class Point
	*/
    : Point( xValue, yValue )	// call base class constructor
{
    setRadius( radiusValue );
} // end Circle constructor
 
void Circle::setRadius( double radiusValue )
{
    radius = ( radiusValue < 0.0 ? 0.0 : radiusValue );
} // end function setRadius

/*
Invoke function getRadius rather than directly accessing data member radius
*/
double Circle::getRadius() const
{
    return radius;
}

double Circle::getDiameter() const
{
    return 2 * getRadius();
}
 
double Circle::getCircumference() const
{
    return 3.14159 * getDiameter();
}
 
double Circle::getArea() const
{
    return 3.14159 * getRadius() * getRadius();
}

/*
Redefine class Point’s member function print.
*/
void Circle::print() const
{
    cout << "Center = ";
    Point::print();
    cout << "; Radius = " << getRadius();
}

//CPP
#include <iostream>
#include <iomanip>
 
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
 
#include "circle.h"  // Circle class definition
 
int main()
{
    Circle circle( 37, 43, 2.5 ); // instantiate Circle object
 
    // display point coordinates
    cout << "X coordinate is " << circle.getX()
    << "\nY coordinate is " << circle.getY()
    << "\nRadius is " << circle.getRadius();
 	/*
 	Use inherited functions
 	*/
    circle.setX( 2 );          // set new x-coordinate
    circle.setY( 2 );          // set new y-coordinate
    circle.setRadius( 4.25 );  // set new radius
    // display new point value
    cout << "\n\nThe new location and radius of circle are\n";
    circle.print();
 
    // display floating-point values with 2 digits of precision
    cout << fixed << setprecision( 2 );
 
    // display Circle's diameter
    cout << "\nDiameter is " << circle.getDiameter();
 
    // display Circle's circumference
    cout << "\nCircumference is " << circle.getCircumference();
 
    // display Circle's area
    cout << "\nArea is " << circle.getArea();
 
    cout << endl;
 
    return 0;  // indicates successful termination
}

/*****************************************

X coordinate is 37
Y coordinate is 43
Radius is 2.5
 
The new location and radius of circle are
Center = [2, 2]; Radius = 4.25
Diameter is 8.50
Circumference is 26.70
Area is 56.74

*****************************************/