#pragma once
#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H
#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstdlib>

class fail_open_file : public std::ios_base::failure {
public:
	const char* what () { return "Error open file."; }
};

class fail_read_file : public std::exception {
private:
	std::string file_;
	std::string str_problem;
public:
	explicit fail_read_file (const char * i_filename,
													 const char * i_problem = "Error! Data wasn't read: ") :
		file_ (i_filename), str_problem (i_problem) {	}
	const std::string & what () { return str_problem.append (file_); }
};
//class fail_size_array :
class fail_size_array : public std::logic_error {
private:
	size_t size1_;
	size_t size2_;
	std::string str_problem;
public:
	explicit fail_size_array (const size_t i_size1, const size_t i_size2,
									 const std::string & i_str = "Error! Size of arrays are not	equal:") :
	std::logic_error(i_str), size1_(i_size1), size2_(i_size2), str_problem(i_str) {}
	const std::string what () { return str_problem; }
};
#endif // MY_EXCEPTION_H



