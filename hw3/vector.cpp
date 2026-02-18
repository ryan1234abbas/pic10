#include "vector.hpp"









size_t my::vector::size()     const { return siz; }
size_t my::vector::capacity() const { return cap; }

bool my::vector::empty() const { return siz == 0; }

my::vector::vector(){
    siz = 0;
    cap = 0;
    ptr = nullptr;   
}
my::vector::~vector(){
    delete [] ptr;
}


const int& my::vector::operator[](size_t i) const {
    return ptr[i];
}

int& my::vector::operator[](size_t i){
    return ptr[i];
}


my::vector::vector(size_t size){
    siz = size, cap = size; 
    ptr = new int[size]();
}
my::vector::vector(size_t size, int val){
    siz = size, cap = size;
    ptr = new int[size];
    for(int j = 0; j < size; ++j){
        ptr[j] = val;
    }
    
}

my::vector::vector(std::initializer_list<int> l1){
    siz = l1.size(), cap = l1.size();
    ptr = new int[l1.size()];
    size_t i = 0;
    for(int val: l1){
        ptr[i] = val;
        ++i;
    }
    
}

void my::vector::clear(){
    siz = 0;
}

void my::vector::reserve(size_t c){
    if(c > cap){cap += c;}
}

void my::vector::push_back(int val){
    if(cap == 0){
        cap+=1;
        ptr = new int[cap];
    }
    else if(siz == cap){
        cap*=2;
        int* new_ptr = new int[cap];
        for(int i = 0; i < siz; ++i){
            new_ptr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = new_ptr;
    }
    
    ptr[siz] = val; 
    siz += 1;
}

void my::vector::resize(size_t n, int i){
    if(n > cap){
        size_t new_cap = cap*2;
        //is cap*2 is still too small just set cap = n as a fallback
        if(new_cap < n){
            new_cap = n;
        }
        cap = new_cap;

    }
    else{
        cap = n;
    }

    if(n > siz){
        int* new_ptr = new int[cap];
        for(size_t m = 0; m < siz; ++m){
            new_ptr[m] = ptr[m];
        }
        for(size_t j = siz; j < n; ++j){
            new_ptr[j] = i;
            
        }
        delete[] ptr;
        ptr = new_ptr;
        
    }

    siz = n;
}

void my::vector::swap(vector& v){
    std::swap(v.ptr, ptr);
    std::swap(v.siz, siz);
    std::swap(v.cap, cap);
}

//move constructor
my::vector::vector(vector&& v){
    cap = v.cap;
    siz = v.siz;
    ptr = v.ptr;

    v.cap = 0, v.siz= 0;
    v.ptr = nullptr;
}
//copy constructor
my::vector::vector(const vector& v1){
    siz = v1.siz;
    cap = v1.cap;
    ptr = new int[cap];

    for(int i = 0; i < siz; ++i){
        ptr[i] = v1[i];
    }

}

//move operator
my::vector& my::vector::operator=(vector&& v){
    delete[] ptr;
    ptr = v.ptr;
    cap = v.cap;
    siz = v.siz;

    v.cap = 0, v.siz = 0, v.ptr= nullptr;
    return *this;
}   

//copy operator
my::vector& my::vector::operator=(const vector& v){
    delete[] ptr;
    siz = v.siz;
    cap = v.cap;
    ptr = new int[cap];

    for(int i = 0; i < siz; ++i){
        ptr[i] = v[i];
    }
    return *this;
}  











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
