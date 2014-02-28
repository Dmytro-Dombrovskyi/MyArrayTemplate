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
   try {
      for(int i = 0; i < counter; ++i) {
         write[i] = MyArray<double>((rand() % 5),(rand() % 5));
      }
   }
   catch(std::exception &ex) { std::cerr << ex.what(); }

   for(int i = 0; i < counter; ++i) {
      cout << write[i] << endl;
   }

   return 0;
}
