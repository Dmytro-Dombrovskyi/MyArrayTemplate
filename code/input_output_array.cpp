#include <iostream>
#include "MyArray.h"
#include "rational_number.h"
#include <ctime>

int main() {
   using std::cout;
   using std::endl;
   using std::cin;
   srand(time(NULL));
   const int counter = 5;
   MyArray<double> *write = new MyArray<double>[counter];
   MyArray<double> *Read = new MyArray<double>[counter];
   try {
      for(int i = 0; i < counter; ++i) {
         write[i] = MyArray<double>((rand() % 5),(rand() % 5));
      }
   }
   catch(std::exception &ex) { std::cerr << ex.what(); }
   // git info on console:
   for(int i = 0; i < counter; ++i) {
      cout << write[i] << endl;
   }
   // writing in file
   const char * filename = "input_output_array.txt";
   try {
          WriteInFileArray(write, counter, filename);
          GetFromFileArray(Read, counter, filename);
   }
   catch (std::exception &ex) { std::cerr << ex.what(); }
   cout << endl;
   for(int i = 0; i < counter; ++i) {
      cout << Read[i] << endl;
   }

   return 0;
}

