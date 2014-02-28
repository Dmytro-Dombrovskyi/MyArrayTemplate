#include "rational_number.h"
#include "my_exception.h"
// assignment constructor
rational_number & rational_number::operator=(const rational_number &a) {
	if(this != &a) {
		num = a.num;
		denum = a.denum;
	}
	return *this;
}
// copy constructor
rational_number::rational_number (const rational_number &a) {
	if(this != &a) {
		num = a.num;
		denum = a.denum;
	}
}
// make normalize: sign orders, numerator and denumenator orders
void rational_number::normalize() const {
  int BigD = BiggestDenum (num, denum); // function is finding the biggest denumenator
	num /= BigD;
	denum /= BigD;

	if(denum < 0) {
		num = -num;
		denum = -denum;
	}
}
// Euclids algoritm for the greatest common divisor
int BiggestDenum (int a, int b) {
	if(a != b) {
		if(a < b)
			std::swap (a, b);

		while(a != 0 && b != 0) {
			a %= b;
			std::swap (a, b);
		}
	}
	return ((a == 0) ? b : a); // returned value with greatest common divisor
}
// printing correct data with entire
std::ostream& operator<<(std::ostream &os, const rational_number &a) {
		a.normalize (); // finding the biggest denumenator
    os << a.num << "/" << a.denum ; // print data
    return os; // return object
}
std::istream& operator>>(std::istream &os, rational_number &a) {
	os >> a.num;
	char symbol;
	os >> symbol;
	os >> a.denum;
	a.normalize ();
	return os;
}
/////////////////////////////////////////////////////////////////////////
// multiplicate object to another and then do assignment
rational_number & rational_number::operator*=(const rational_number &a) {
	num *= a.num;
	denum *= a.denum;
	return *this;
}
// addition objects and then do assignment to object called
rational_number & rational_number::operator+=(const rational_number &a) {
	num = ((a.num * denum) + (a.denum * num));
	denum *= a.denum;
	return *this;
}
// divide objects and then do assignment to object called
rational_number & rational_number::operator/=(const rational_number &a) {
	num *= a.denum;
	denum *= a.num;
	return *this;
}
// substruct objects and then do assignment to object called
rational_number & rational_number::operator-=(const rational_number &a) {
	rational_number b;
	num = ((a.denum * num) - (a.num * denum));
	denum *= a.denum;
	return *this;
}
////////////////////////////////////////////////////////
// operation with integer value
rational_number & rational_number::operator*=(int val) {
	num *= val;
	return *this;
}
rational_number & rational_number::operator/=(int val) {
	denum *= val;
	return *this;
}
rational_number & rational_number::operator+=(int val) {
	num += (val * denum);
	return *this;
}
rational_number & rational_number::operator-=(int val) {
	num -= (val * denum);
	return *this;
}
////////////////////////////////////////////////////////////
// operation with integer value and object data
rational_number operator*(int val, const rational_number &a) {
	rational_number temp (val);
	return (temp *= a);
}
rational_number operator/(int val, const rational_number &a) {
	rational_number temp (val);
	return (temp /= a);
}
rational_number operator+(int val, const rational_number &a) {
	rational_number temp (val);
	return (temp += a);
}
rational_number operator-(int val, const rational_number &a) {
	rational_number temp (val);
	return (temp -= a);
}
////////////////////////////////////////////////////////////////////////////////////////////

rational_number operator*(rational_number a, const rational_number &b) { return (a *= b); }
rational_number operator+(rational_number a, const rational_number &b) { return (a += b); }
rational_number operator/(rational_number a, const rational_number &b) { return (a /= b); }
rational_number operator-(rational_number a, const rational_number &b) { return (a -= b); }

// operation without assignment
rational_number operator*(rational_number a, int val) { return (a *= val); }
rational_number operator/(rational_number a, int val) { return (a /= val); }
rational_number operator+(rational_number a, int val) { return (a += val); }
rational_number operator-(rational_number a, int val) { return (a -= val); }

// bool operators >, <, -, +, == //
bool operator>(const rational_number &a, const rational_number &b) {
	return ((b.get_num() * a.get_denum()) >
					(a.get_num() * b.get_denum())) ?
					true : false;
}
bool operator<(const rational_number &a, const rational_number &b) {
	return ((b.get_num () * a.get_denum ()) <
					(a.get_num () * b.get_denum ())) ?
					true : false;
}
bool operator>=(const rational_number &a, const rational_number &b) {
	return ((b.get_num () * a.get_denum ()) >=
					(a.get_num () * b.get_denum ())) ?
					true : false;
}
bool operator<=(const rational_number &a, const rational_number &b) {
	return ((b.get_num () * a.get_denum ()) <=
					(a.get_num () * b.get_denum ())) ?
					true : false;
}
bool operator==(const rational_number &a, const rational_number &b) {
	return ((b.get_num () * a.get_denum ()) ==
					(a.get_num () * b.get_denum ())) ?
					true : false;
}
bool operator!=(const rational_number &a, const rational_number &b) {
	return ((b.get_num () * a.get_denum ()) !=
					(a.get_num () * b.get_denum ())) ?
					true : false;
}

///////////////////////////////////////////////////////////////////////////////

void readToFile (const char * f_name, rational_number & Object_read) {
	std::fstream outFile;
	outFile.open (f_name, std::ios::out);
	outFile << Object_read;
	outFile.close ();
	std::cout << "File has been created! " << std::endl;
}

void readFromFile (const char *f_name, rational_number & Object_read) {
	std::cout << "Object data is: " << Object_read << std::endl;
	std::fstream inFile;
	try {
		inFile.open (f_name, std::ios::in);
		while(inFile.good ()) {
			inFile >> Object_read;
		}
	}
	catch(std::exception &ex) {
		std::cerr << ex.what();
	}
	inFile.close ();
}
