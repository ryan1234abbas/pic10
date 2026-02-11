#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

unsigned int factorial(unsigned int n){
    if(n == 1 || n == 0){return 1;}
    else{
        return n * factorial(n-1);
    }
}

void permutation(int n, std::vector<int>& curr, std::set<int>& used){
    if(curr.size() == n){
        for(int el : curr){
            cout << el << " ";
        }
        cout << endl;
    }

    for(size_t i = 1; i <= n; ++i){
        if(!used.count(i)){
            curr.push_back(i);
            used.insert(i);

            permutation(n, curr, used);

            curr.pop_back();
            used.erase(i);
        }
    }

}

bool palindrome(std::string s, size_t hi, size_t low){
    if(hi <= low) return true;
    if(s[hi] != s[low]) return false;
    return palindrome(s, hi-1, low+1);
}

void merge_sort(std::vector<int>& v){
    
    if(v.size() == 0 || v.size() == 1){return;}

    size_t N1 = v.size() / 2;
    size_t N2 = v.size() - N1;

    std::vector<int> v1(v.begin(), v.begin() + N1);
    std::vector<int> v2(v.begin() + N1, v.end());

    merge_sort(v1);
    merge_sort(v2);

    size_t i = 0, id1 = 0, id2 = 0;

    while(id1 < v1.size() && id2 < v2.size()){
        if(v1[id1] <= v2[id2]){
            v[i] = v1[id1];
            ++id1;
        }
        else if(v1[id1] > v2[id2]){
            v[i] = v2[id2];
            ++id2;
        }
        ++i;
    }

    while(id1 < v1.size()){
        v[i] = v1[id1];
        ++id1;
        ++i;
    }
    while(id2 < v2.size()){
        v[i] = v2[id2];
        ++id2;
        ++i;
    }

}

void iterative_bubble_sort(std::vector<int>&v){
    for(size_t i= 0; i < v.size() -1; ++i){
        for(size_t j = 0; j < v.size() - 1; ++j){
            if(v[j] > v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp; 
            }
        }
    }
}

void recursive_bubble_sort(std::vector<int>&v, int n){
    if(n == 0 || n ==1) return;
    for(size_t i = 0; i < v.size() -1; ++i){
        if(v[i] > v[i+1]){
            std::swap(v[i], v[i+1]);
        }
    }
    recursive_bubble_sort(v, n-1);

}

void iterative_selection_sort(std::vector<int> &v){
    for(size_t i = 0; i < v.size()-1; ++i){
        size_t min_idx = i;
        for(size_t j = i+1; j < v.size(); ++j){
            if(v[j] < v[min_idx]){
                min_idx = j;
            }
        }

        if(min_idx != i){
            std::swap(v[i],v[min_idx]);
        }
    }
}

void recursive_selection_sort(std::vector<int> &v, size_t beg){
    if(beg > v.size()-1){
        return;
    }
    size_t min_idx = beg;
    for(size_t i = beg; i < v.size(); ++i){
        if(v[i] < v[min_idx]){
            min_idx = i;
        }
    }
    std::swap(v[beg], v[min_idx]);
    recursive_selection_sort(v, beg+1);
}

int iterative_binary_search(const std::vector<int> &v, int target){
    int hi = v.size()-1, low = 0;

    while(hi >= low){
        int mid = (hi+low)/2;
        if(v[mid] > target){
            hi = mid-1;
        }
        else if(v[mid] < target){
            low = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;

}

int recursive_binary_search(const std::vector<int>& v, int target, size_t low, size_t hi){

    size_t mid = (low+hi)/2;
    if(target > v[mid]){
        return recursive_binary_search(v, target, mid+1, hi);
    }
    else if(target < v[mid]){
        return recursive_binary_search(v, target, low, mid-1);
    }
    else{
        return mid;
    }
    
    return -1;
}

int iterative_sequential_search(std::vector<int>&v, int n){
    for(size_t i = 0; i < v.size(); ++i){
        if(v[i] == n){
            return i;
        }
    }
    return -1;
}

int recursive_sequential_search(std::vector<int>&v, int n, size_t idx){
    if(idx >= v.size()) return -1;
    if(v[idx] == n) return idx;
    return recursive_sequential_search(v, n, idx+1);
}

//operator overloading
class C{
    private: 
        int i;
        friend ostream& operator<<(ostream& cout, const C& other);
        friend istream& operator>>(istream& in, C& other);
        friend bool operator==(const C& left, const C& right);
        friend bool operator<(const C& left, const C& right);
    public:
        C(int _i): i(_i){};

        C& operator+=(const C& other){
            i += other.i;
            return *this;
        }
        C& operator-=(const C& other){
            i -= other.i;
            return *this;
        }
        C& operator*=(const C& other){
            i *= other.i;
            return *this;
        }
        C& operator/=(const C& other){
            i /= other.i;
            return *this;
        }

        //postfix
        C operator++(int){
            C other = *this;
            i += 1;
            return other;
        }
        C operator--(int){
            C other = *this;
            i -= 1;
            return other;
        }

        //prefix
        C& operator++(){
            ++i;
            return *this;
        }
        C& operator--(){
            --i;
            return *this;
        }

        C operator+() const{
            return *this;
        }

        C operator-() const{
            return C(-i);
        }

        operator double() const{
            return static_cast<double>(i);
        }

        explicit operator char() const{
            return static_cast<char>(i);
        }

        int& operator[](size_t j){
            if(j != 0){ 
                cout << "Not 0" << endl;
                return i;
            }
            else{
                return i;
            }
        }
        const int& operator[](size_t j) const{
            if(j != 0){ 
                cout << "Not 0" << endl;
                return i;
            }
            else{
                return i;
            }
        }

        int operator()() const{
            return i * 2;
        }
};

ostream& operator<<(ostream& cout, const C& other){
    cout << other.i;
    return cout;
}
istream& operator>>(istream& in, C& other){
    in >> other.i;
    return in;
}

C operator+(const C& left, const C& right){
    C val = left;
    val += right;
    return val;
}
C operator-(const C& left, const C& right){
    C val = left;
    val -= right;
    return val;
}
C operator*(const C& left, const C& right){
    C val = left;
    val *= right;
    return val;
}
C operator/(const C& left, const C& right){
    C val = left;
    val /= right;
    return val;
}

bool operator==(const C& left, const C& right){
    return left.i == right.i;
}
bool operator!=(const C& left, const C& right){
    return !(left == right);
}
bool operator<(const C& left, const C& right){
    return left.i < right.i;
}
bool operator>(const C& left, const C& right){
    return right < left;
}
bool operator>=(const C& left, const C& right){
    return !(left < right);
}
bool operator<=(const C& left, const C& right){
    return !(right > left);
}

struct A {
    double d;
    explicit A(double _d) : d(_d) {}
    operator int() const { return d; }
};

bool operator==(const A& a1, const A& a2){
    return (a1.d == a2.d);
}

//memory management with RAII
struct RAII{
    int* p;
    RAII(); 
    ~RAII();//destructor
};

RAII::RAII(): p(new int(8)){
    cout << "default constructor called" << endl;
};

RAII::~RAII(){
    cout << "destructor called" << endl;
    delete p;
}

int main() {
    cout << "Before RAII object in main" << endl;

    RAII r;  // RAII object lives for the entire main function

    cout << "Using heap value: " << *(r.p) << endl;

    cout << "End of main, RAII destructor will run automatically" << endl;
}



/*undefined behavior:
del a pointer to a stack variable
deleting a pointer 2x
dereferencing a del pointer or nullptr
*/

// clang++ -std=c++14 lecture.cpp -o lecture && ./lecture