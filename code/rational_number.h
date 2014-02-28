#pragma once
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H
#include <iostream>
#include <fstream>

class rational_number
{
  private:
    mutable int num;	// data numerator
    mutable int denum;	// data denumerator
    void normalize() const; // normalize
  public:
    explicit rational_number(int i_num = 0, int i_denum = 1): // constructor by default
        num(i_num), denum(i_denum) { normalize(); }
		rational_number (const rational_number &a); // copy constructor
		rational_number & operator=(const rational_number &a); // assignment constructor
    ~rational_number() {}		// destructor by default

	// operation with two class objects
	rational_number & operator*=(const rational_number &a); // multiplicate
	rational_number & operator+=(const rational_number &a); // addition
	rational_number & operator/=(const rational_number &a); // divide
	rational_number & operator-=(const rational_number &a); // substract

	// operation with class object and integer value
	rational_number & operator*=(int val);
	rational_number & operator/=(int val);
	rational_number & operator+=(int val);
	rational_number & operator-=(int val);

	// print write data with optimization
	friend std::ostream& operator<<(std::ostream &os, const rational_number &a);
	friend std::istream& operator>>(std::istream &os, rational_number &a);

	int get_num() const { return num; } // print private data num
	int get_denum() const { return denum; } // print private data denum
	double get_double ()const { return static_cast<double>(num) / denum; }

	// change the sign of data
	rational_number & operator-() { num = -num; return (*this); } // get another sign to data
};

std::ostream& operator<<(std::ostream &os, const rational_number &a);
std::istream& operator>>(std::istream &os, rational_number &a);
// Euclids algoritm for the greatest common divisor
int BiggestDenum (int a, int b);

//// operation with classes
rational_number operator*(rational_number a, const rational_number &b);
rational_number operator+(rational_number a, const rational_number &b);
rational_number operator/(rational_number a, const rational_number &b);
rational_number operator-(rational_number a, const rational_number &b);

// operation with integer value and object data
rational_number operator*(int val, const rational_number &a);
rational_number operator/(int val, const rational_number &a);
rational_number operator+(int val, const rational_number &a);
rational_number operator-(int val, const rational_number &a);

rational_number operator*(rational_number a, int val);
rational_number operator/(rational_number a, int val);
rational_number operator+(rational_number a, int val);
rational_number operator-(rational_number a, int val);

void readToFile (const char * f_name, rational_number & Object_read);
void readFromFile (const char *f_name, rational_number & Object_read);

// bool operators >, <, -, +, == //
bool operator> (const rational_number &, const rational_number &);
bool operator< (const rational_number &, const rational_number &);
bool operator>=(const rational_number &, const rational_number &);
bool operator<=(const rational_number &, const rational_number &);
bool operator==(const rational_number &, const rational_number &);
bool operator!=(const rational_number &, const rational_number &);

/////////////////////////////////////////
// bool operators >, <, -, +, == // templates
template <typename Type>
bool operator>(const rational_number &a, const Type &b) {
	return (a.get_double () > b) ? true : false;
}
template <typename Type>
inline bool operator>(const Type &a, const rational_number &b) {
	return (a > b.get_double ()) ? true : false;
}
//////////////////////////////////////
template <typename Type>
inline bool operator<(const rational_number &a, const Type &b) {
	return (a.get_double() < b) ? true : false;
}
template <typename Type>
inline bool operator<(const Type &a, const rational_number &b) {
	return (a < b.get_double()) ? true : false;
}
//////////////////////////////////////
template <typename Type>
inline bool operator>=(const rational_number &a, const Type &b) {
	return (a.get_double () >= b) ? true : false;
}
template <typename Type>
inline bool operator>=(const Type &a, const rational_number &b) {
	return (a >= b.get_double ()) ? true : false;
}
////////////////////////////////////////
template <typename Type>
inline bool operator<=(const rational_number &a, const Type &b) {
	return (a.get_double() <= b) ? true : false;
}
template <typename Type>
inline bool operator<=(const Type &a, const rational_number &b) {
	return (a <= b.get_double()) ? true : false;
}
//////////////////////////////////////////
template <typename Type>
inline bool operator==(const rational_number &a, const Type &b) {
	return (a.get_double () == b) ? true : false;
}
template <typename Type>
inline bool operator==(const Type &a, const rational_number &b) {
	return (a == b.get_double ()) ? true : false;
}
//////////////////////////////////////////////////////
template <typename Type>
inline bool operator!=(const rational_number &a, const Type &b) {
	return (a.get_double() != b) ? true : false;
}
template <typename Type>
inline bool operator!=(const Type &a, const rational_number &b) {
	return (a != b.get_double()) ? true : false;
}
//////////////////////////////////////////////////////////

#endif // RATIONAL_NUMBER_H
