#include "rational_number.h"
using std::cout;
using std::endl;
using std::cin;

#if 0
int main() {
   // Testing class rational number
	rational_number A;
	A = rational_number(1, 4);
	rational_number B (4, 5);
	cout << "A = " << A << endl;
	cout << "B = " << B << endl;
	// Testing operators:
	// 1. Operations with two classes objects:
	cout << "1. Using operator to do operations with two classes objects: " << endl;
	cout << " '+=', '*=', '/=', '-=' " << endl;
	cout << "1.a)  " << "A += B: " << A << " += " << B << " = ";
	cout << (A += B) << endl;
	cout << "1.b)  " << "A -= B: " << A << " -= " << B << " = ";
	cout << (A -= B) << endl;
	cout << "1.c)  " << "A *= B: " << A << " *= " << B << " = ";
	cout << (A *= B) << endl;
	cout << "1.d)  " << "A /= B: " << A << " /= " << B << " = ";
	cout << (A /= B) << endl;
	cout << endl;
	// 1. Operations with two classes using operators '+', '-', '/', '*'.
	cout << " '+', '-', '/', '*' " << endl;
	cout << "1.a)  " << "A + B: " << A << " + " << B << " = ";
	cout << (A + B) << endl;
	cout << "1.b)  " << "A - B: " << A << " - " << B << " = ";
	cout << (A - B) << endl;
	cout << "1.c)  " << "A * B: " << A << " * " << B << " = ";
	cout << (A * B) << endl;
	cout << "1.d)  " << "A / B: " << A << " / " << B << " = ";
	cout << (A / B) << endl;
	cout << endl;

	// 2. Operations with class object and integer value
	cout << "2. Using operator to do operations with "
		 << "class object and integer value: " << endl;
	cout << " '+=', '*=', '/=', '-=' " << endl;
	cout << "2.a)  " << "A += 5: " << A << " += " << 5 << " = ";
	cout << (A += 5) << endl;
	cout << "2.a)  " << "A -= 5: " << A << " -= " << 5 << " = ";
	cout << (A -= 5) << endl;
	cout << "2.a)  " << "A *= 5: " << A << " *= " << 5 << " = ";
	cout << (A *= 5) << endl;
	cout << "2.a)  " << "A /= 5: " << A << " /= " << 5 << " = ";
	cout << (A /= 5) << endl;
	cout << endl;
	// 2. Operations with class object and integer value which are using operators
	//		'+', '-', '/', '*'
	cout << " '+', '-', '/', '*' " << endl;
	cout << "2.a)  " << "A + 5: " << A << " + " << 5 << " = ";
	cout << (A + 5) << endl;
	cout << "2.a)  " << "A - 5: " << A << " - " << 5 << " = ";
	cout << (A - 5) << endl;
	cout << "2.a)  " << "A * 5: " << A << " * " << 5 << " = ";
	cout << (A * 5) << endl;
	cout << "2.a)  " << "A / 5: " << A << " / " << 5 << " = ";
	cout << (A / 5) << endl;
	cout << endl;

	// 3. Operations with integer value and object data
	cout << "3. Using operator to do operations with integer " << endl;
	cout << "   value and class object, where integer value is first: " << endl;
	rational_number C;
	cout << "C = " << C << endl;
	cout << " '+', '-', '/', '*' " << endl;
	cout << "3.a)  C = " << "-8 + A: " << -8 << " + " << A << " = ";
	cout << (-8 + A) << endl;
	cout << "3.b)  C = " << "-8 - A: " << -8 << " - " << A << " = ";
	cout << (-8 - A) << endl;
	cout << "3.b)  C = " << "-8 * A: " << -8 << " * " << A << " = ";
	cout << (-8 * A) << endl;
	cout << "3.b)  C = " << "-8 / A: " << -8 << " / " << A << " = ";
	cout << (-8 / A) << endl;

	// 4. Operations with object class:
	cout << "4. Manipulation with object class data: " << endl;
	cout << "4a. A = " << A << endl;
	cout << "A numenator: " << A.get_num() << endl;
	cout << "A denumenator: " << A.get_denum() << endl;
	cout << "4b. Change sign of value: " << endl;
	cout << "-A  " << A << ": ";
	cout << -A << endl;

	// 5. Operation with file read/write:
	cout << "Creating file, than read data to file '.txt': " << endl;
	const char *filename = "rational_number.txt";
	readToFile (filename, A);

	// 6. Operation with file read to object class:
	cout << "Read data from file and read to object class: " << endl;
	readFromFile (filename, B);


	cin.get (); cin.get ();
    return 0;
}
#endif
