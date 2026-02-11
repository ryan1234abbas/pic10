#include "vector.hpp"









size_t my::vector::size()     const { return siz; }
size_t my::vector::capacity() const { return cap; }

bool my::vector::empty() const { return siz == 0; }























void my::vector::pop_back() { siz -= 1; }



void my::vector::new_capacity(size_t n) {
    cap = n;
    int* new_ptr = new int[cap];

    for (size_t i = 0; i < siz; ++i) {
        new_ptr[i] = ptr[i];
    }
    delete[] ptr;

    ptr = new_ptr;
}




































































const int* my::vector::data() const { return ptr; }
      int* my::vector::data()       { return ptr; }


void my::swap(vector& v1, vector& v2) {
    v1.swap(v2);
}
