#include <iostream>
#include "MyArray.h"
#include "rational_number.h"
using std::cout;
using std::endl;
using std::cin;

int main () {
	//// 1. Test methods of class += , -=, /=, *=.
	//MyArray<double> a1 (5, 5);
	//MyArray<double> b1 (3, 5);
	//cout << "array a1: " << a1 << endl;
	//cout << "array b1: " << b1 << endl;
	//cout << "a1 += b1: " << (a1 += b1) << endl;
	//cout << "a1[0] += b1[0]: " << (a1[0] += b1[0]) << endl;
	//cout << "a1 -= b1: " << (a1 -= b1) << endl;
	//cout << "a1 *= b1: " << (a1 *= b1) << endl;
	//cout << "a1 /= b1: " << (a1 /= b1) << endl;
	//// 1. a) Get new array with parametrs:
	//cout << "Create the new object an print data: " << endl;
	MyArray<double> b2 (3.32, 5);
	cout << "Print array b: " << endl;
	cout << b2 << endl;
	try {
		WriteInFile (b2, "array.txt");
	}
	catch(std::exception &ex) {
		std::cerr << ex.what ();
	}
	//// 4. use function assignment new value to object of class
	//cout << "creating an object and write the value into its: " << endl;
	MyArray<double> c;
	//cout << c << endl;
	//cout << "Write the size of array then value: \n";
	//cout << "You have to write this way: \n";
	//cout << "size of array, Enter, comma, Enter, value1 , Enter, comma2, ...value n: ";
	//cin >> c;
	//cout << "Print data object: " << endl;
	try {
		GetFromFile (c, "array.txt");
	}
	catch(std::exception &ex) {
		std::cerr << ex.what ();
	}
	cout << endl << "Data in \'c\': " << endl;
	cout << c << endl;	
	////////////////////////////////////////////////////
	// part 2!!!
	// rational number in array:
	/*cout << "Part2. Creating fractions array:" << endl;
	MyArray<rational_number> RN(rational_number(2, 3), 3);
	MyArray<rational_number> LN (rational_number (1, 3), 3);
	cout << RN << endl;
	cout << LN << endl;
	cout << "RN + LN = " << RN + LN << endl;
	cout << "RN - LN = " << RN - LN << endl;
	cout << "RN / LN = " << RN / LN << endl;
	cout << "RN * LN = " << RN * LN << endl;*/
	//RN.Resize (2);
	//cout << RN[0] << endl;
	//RN[0] = rational_number (1, 3);
	//cout << "Cnanged RN[0]: " << RN[0] << endl;
	//cout << "num: " << (RN[0].get_num ()) << endl;
	//cout << "denum: " << (RN[0].get_denum ()) << endl;
	//cout << RN << endl;
	////////////////////////////////////////////////////////////
	//cout << "Check for operator >, < , >=, <= , != : " << endl;
	//if(RN[0] > RN[1])
	//	cout << "RN[0] > RN[1]" << endl;
	//else {
	//	if(RN[0] < RN[1])
	//		cout << "RN[0] < RN[1]" << endl;
	//	else
	//		cout << "RN[0] == RN[1]" << endl;
	//}
	//cout << endl;
	///////////////////////////////////////////////////////////
	//// part 4!!!	
	//rational_number a (1, 3);
	//rational_number b (3, 5);
	//// using operators for comparing numbers of objects: >, <, == ...
	//cout << "Compare rational numbers: " << a << " and " << b << endl;
	//cout << a << " > " << b << " ? " << (a > b) << endl;
	//cout << a << " < " << b << " ? " << (a < b) << endl;
	//cout << a << " >= " << b << " ? " << (a >= b) << endl;
	//cout << a << " <= " << b << " ? " << (a <= b) << endl;
	//cout << a << " == " << b << " ? " << (a == b) << endl;
	//cout << a << " != " << b << " ? " << (a != b) << endl;
	//cout << "Compare rational number with random value: " 
	//		 << a << endl;
	//cout << a << " > " << 3 << " ? " << (a > 3) << endl;
	//cout << a << " < " << 3 << " ? " << (a < 3) << endl;
	//cout << a << " >= " << 3 << " ? " << (a >= 3) << endl;
	//cout << a << " <= " << 3 << " ? " << (a <= 3) << endl;
	//cout << a << " == " << 3 << " ? " << (a == 3) << endl;
	//cout << a << " != " << 3 << " ? " << (a != 3) << endl;
	//cout << "Compare rational number with random value: "
	//	<< b << endl;
	//cout << 3 << " > " << b << " ? " << (3 > b) << endl;
	//cout << 3 << " < " << b << " ? " << (3 < b) << endl;
	//cout << 3 << " >= " << b << " ? " << (3 >= b) << endl;
	//cout << 3 << " <= " << b << " ? " << (3 <= b) << endl;
	//cout << 3 << " == " << b << " ? " << (3 == b) << endl;
	//cout << 3 << " != " << b << " ? " << (3 != b) << endl;
	//////////////////////////////////////////////////////////////
	// part 5
	// using operator +, - , *, / which are work with elements:
	//cout << a * b << endl;
	cout << "Done!" << endl;
	cin.get(); cin.get();
	return 0;
}
