#pragma once
#ifndef MYARRAY_H
#define MYARRAY_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include "my_exception.h"

using std::exception;

template <typename T>
class MyArray;
// declaration of friends operators
template <typename T>
std::ostream & operator<<(std::ostream &os, const MyArray<T> &a);
template <typename T>
std::istream & operator>>(std::istream &os, MyArray<T> &a);
template <typename T>
std::istream & operator>>(std::istream &os, MyArray<T> *ptrArr);

////////////////////////////////////////////////////////////

template <typename T>
class MyArray {
private:
	size_t size;
	T *arr;
public:
	MyArray () : size(0), arr(nullptr) {}
	explicit MyArray(T, size_t = 0); // constructor
	~MyArray () { delete[] arr; } // destructor
	MyArray (const MyArray &a);		// copy constructor
	MyArray & operator=(const MyArray &a); // assignment constructor

	inline T & operator[](size_t i) { return arr[i]; }
	inline const T & operator[](size_t i) const { return arr[i]; }

	inline size_t length () const { return size; } // get size of array
	MyArray & Resize (size_t new_size); // function reset
	// operator input / output stream
	friend std::ostream & operator<< <T>(std::ostream &os, const MyArray<T> &a);
	friend std::istream & operator>> <T>(std::istream &os, MyArray<T> &a);

	// functions +=, -=, /=, *=, witch work with arrays elements
	MyArray & operator+=(const MyArray &a);
	MyArray & operator-=(const MyArray &a);
	MyArray & operator*=(const MyArray &a);
	MyArray & operator/=(const MyArray &a);
};
//////////////////////////////////////////////////////////
// constructor
template<typename T>
MyArray<T>::MyArray (T num, size_t i_size) : size (i_size) {
	if(size) {
		arr = new T[size];
		for(size_t i = 0; i < size; i++)
			arr[i] = num;
	}
	else
		arr = nullptr;
}
///////////////////////////////////////////////////////////
// copy constructor
template<typename T>
MyArray<T>::MyArray (const MyArray<T> &a) : size (a.size) {
	if(size) {
		arr = new T[size];
		for(size_t i = 0; i < size; i++)
			arr[i] = a.arr[i];
	}
	else
		arr = nullptr;
}
//////////////////////////////////////////////////////////
// assignment constructor
template <typename T>
MyArray<T> & MyArray<T>::operator=(const MyArray<T> &a) {
	if(this != &a) { // checking the object
		T *temp = new T[a.size];
		for(size_t i = 0; i < a.size; i++) { // copy data in array with new memory
			temp[i] = a.arr[i];
		}
		delete[] arr; // delete the memory
		arr = temp;
		size = a.size;
	}
	return *this;
}
////////////////////////////////////////////////////////
// function reset
template <typename T>
MyArray<T> & MyArray<T>::Resize (size_t new_size) {
	if(new_size != size) {
		T *temp = new T[new_size];
		// write the value from the this object
		if(size > new_size) {	// if new size is less than old size
			for(size_t i = 0; i < new_size; i++) {
				temp[i] = arr[i];
			}
		}
		else if(size < new_size) { // if new size is bigger than old size
			for(size_t i = 0; i < size; i++) {
				temp[i] = arr[i];
			}
			for(size_t i = size; i < new_size; i++) {
				temp[i] = T ();
			}
		}
		delete[]arr;
		arr = temp; // assignment pointer new block of memory
		size = new_size; // assignment new size
	}
	return *this;
}
////////////////////////////////////////////////////////////////
// print data
template <typename T>
std::ostream & operator<<(std::ostream &os, const MyArray<T> &a) {
	os << a.size << "[ ";
	if(a.size) {
		os << a.arr[0];
		for(size_t i = 1; i < a.size; i++) { // print data array
			os << ", " << a.arr[i];
		}
	}
	os << " ] ";
	return os;
}
///////////////////////////////////////////////////////////////
// read data to object
template <typename T>
std::istream & operator>>(std::istream &os, MyArray<T> &a) {
	size_t tempSize;
	os >> tempSize;
	if(tempSize) {
		T *temp = new T[tempSize]; // temporary pointer with new memory
		char symbol;
		size_t i = 0;
		while(i < tempSize) {
			os >> symbol; // if you write from console you have to write comma after value
			if(symbol == ',' || symbol == ']' || symbol == '[')
				os >> temp[i];
			++i;
		}
		delete[]a.arr;
		a.arr = temp; // point pointer to new memory
		a.size = tempSize;
	}
	return os;
}
///////////////////////////////////////////////////////////////
// read data from object into array
template <typename T>
std::istream & operator>>(std::istream &os, MyArray<T> *ptrArr) {
	size_t tempArrSize;
   os >> tempArrSize;
   ptrArr = new MyArray<T>[tempArrSize];
		for(size_t i = 0; i < tempArrSize; ++i) {
			//size_t tempSize;
			os >> ptrArr[i]->size;
			if(ptrArr[i]->size) {
				ptrArr[i]->arr = new T[ptrArr[i]->size]; // temporary pointer with new memory
				char symbol;
				size_t j = 0;
				while(j < tempSize) {
					os >> symbol; // if you write from console you have to write comma after value
					if(symbol == ',' || symbol == ']' || symbol == '[')
						os >> temp[j];
					++j;
				}
			}
		//}
	return os;
}
//////////////////////////////////////////////////////////////
// read data into new file and than read from that file:
template <typename V>
void WriteInFile (const MyArray<V> &a, const char * filename) {
	std::ofstream outFile; // creating the class object
	outFile.open (filename, std::ios::out);
	outFile << a;
	outFile.close ();
}
/////////////////////////////////////////////////////////////
template <typename V>
void WriteInFileArray(const MyArray<V> *ptrArr, const size_t i_size, const char *filename) {
	std::ofstream outFile;
	outFile.open(filename, std::ios::out);
	outFile << i_size << "\n";
	for(size_t i = 0; i < i_size; ++i) {
		outFile << ptrArr[i] << "\n";
	}
	outFile.close();
}
/////////////////////////////////////////////////////////////
// read data into class object from file
template <typename V>
void GetFromFile (MyArray<V> &a, const char * filename) {
	std::ifstream inFile; // create an object
	inFile.open (filename, std::ios::in);
	while(inFile.good ()) {	inFile >> a; }
	inFile.close ();
}
//////////////////////////////////////////////////////////////////
// read data into class array from file
template <typename V>
void GetFromFileArray(const MyArray<V> *ptrArr,	const char *filename) {
	std::ifstream inFile;
   inFile.open(filename, std::ios::in);
   while(inFile.good()) { inFile >> ptrArr; }
   inFile.close();
}
/////////////////////////////////////////////////////////////
// operators +=, -=, *=, /=.
template <typename T>
MyArray<T> & MyArray<T>::operator+=(const MyArray<T> &a) {
	if(size == a.size) {
		for(size_t i = 0; i < size; i++)
			arr[i] += a.arr[i];
	}
	else {
		throw fail_size_array (size, a.size);
	}
	return *this;
}
/////////////////////////////////////////////////////////////
template <typename T>
MyArray<T> & MyArray<T>::operator-=(const MyArray &a) {
	if(size == a.size) {
		for(size_t i = 0; i < size; i++) {
			arr[i] -= a.arr[i];
		}
	}
	else {
		throw fail_size_array (size, a.size);
	}
	return *this;
}
//////////////////////////////////////////////////////////////
template <typename T>
MyArray<T> & MyArray<T>::operator*=(const MyArray &a) {
	if(size == a.size) {
		for(size_t i = 0; i < size; i++)
			arr[i] *= a.arr[i];
	}
	else
		throw fail_size_array (size, a.size);

	return *this;
}
/////////////////////////////////////////////////////////////
template <typename T>
MyArray<T> & MyArray<T>::operator/=(const MyArray &a) {
	if(size == a.size) {
		for(size_t i = 0; i < size; i++)
			arr[i] /= a.arr[i];
	}
	else
		throw fail_size_array (size, a.size);

	return *this;
}
//////////////////////////////////////////////////////////////////////////
// functions +, -, /, *, witch work with arrays elements
template <typename T>
MyArray<T> operator+(MyArray<T> b, const MyArray<T> &a) { return (b += a); }

template <typename T>
MyArray<T> operator-(MyArray<T> b, const MyArray<T> &a) { return (b -= a); }

template <typename T>
MyArray<T> operator/(MyArray<T> b, const MyArray<T> &a) { return (b /= a); }

template <typename T>
MyArray<T> operator*(MyArray<T> b, const MyArray<T> &a) { return (b *= a); }
///////////////////////////////////////////////////////////////////////////

#endif // MYARRAY_H
