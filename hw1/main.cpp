#include "square.hpp"


// I recommend you write your own test cases too...

int main() {
    // Square s(3);
    // s.set(2, 0) = 8;



   Square s(4);
   s.set(0, 0) = 1;
   s.set(1, 1) = 13;
   s.set(2, 2) = 11;
   s.set(3, 3) = 9;
//    s.set(0,3) = 16;

    s.print();
    s.see_magic_potential();
    s.print();

    return 0;
}

//clang++ -std=gnu++14 hw1/main.cpp hw1/square.cpp -o main && ./main