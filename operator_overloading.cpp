
#include <iostream>
#include <iomanip>
 
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;
using std::setw;
 
// PhoneNumber class definition
class PhoneNumber
{
	/*
	Notice function prototypes for overloaded operators >> and <<.
	They must be non-member friend functions, since the object of class Phonenumber appears on the right of the operator.
	cin << object
	cout >> object
	*/
    friend ostream &operator<<( ostream&, const PhoneNumber & );
    friend istream &operator>>( istream&, PhoneNumber & );
 
    private:
        char areaCode[ 4 ];  // 3-digit area code and null
        char exchange[ 4 ];  // 3-digit exchange and null
        char line[ 5 ];      // 4-digit line and null
};

// overloaded stream-insertion operator; cannot be a member function
// if we would like to invoke it with cout << somePhoneNumber;
/*
The expression:
cout << phone;
is interpreted as the function call:
operator<<(cout, phone);
output is an alias for cout.
*/
ostream &operator<<( ostream &output, const PhoneNumber &num )
{
    output << "(" << num.areaCode << ") "
           << num.exchange << "-" << num.line;
 
    /*
    This allows objects to be cascaded
	cout << phone1 << phone2;
	first calls:
	operator<<(cout, phone1), and returns cout.
	Next, cout << phone2 executes
	*/
    return output;     // enables cout << a << b << c;
}
 
// overloaded stream-extraction operator; cannot be a member function
// if we would like to invoke it with cin >> somePhoneNumber;
istream &operator>>( istream &input, PhoneNumber &num )
{
    /*
    ignore() skips specified number of characters from input (1 by default)
    */
    input.ignore();                     // skip (
    input >> setw( 4 ) >> num.areaCode; // input area code
    input.ignore( 2 );                  // skip ) and space
    /*
    Stream manipulator setw restricts number of characters read.
    setw(4) allows 3 characters to be read, leaving room for the null character.
    */
    input >> setw( 4 ) >> num.exchange; // input exchange
    input.ignore();                     // skip dash (-)
    input >> setw( 5 ) >> num.line;     // input line
 
    return input;      // enables cin >> a >> b >> c;
}

int main()
{
    PhoneNumber phone; // create object phone
 
    cout << "Enter phone number in the form (123) 456-7890:\n";
 
    // cin >> phone invokes operator>> by implicitly issuing
    // the non-member function call operator>>( cin, phone )
    cin >> phone;
 
    cout << "The phone number entered was: " ;
 
    // cout << phone invokes operator<< by implicitly issuing
    // the non-member function call operator<<( cout, phone )
    cout << phone << endl;
 
    return 0;
}

/*********************************************

Enter phone number in the form (123) 456-7890:
(800) 555-1212
The phone number entered was: (800) 555-1212

*********************************************/