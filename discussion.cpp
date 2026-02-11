#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <set>


void merge_sort(std::vector<int> &v){
    
    if(v.size() == 1 || v.size() == 0){
        return;
    }
    
    int n1 = v.size() / 2;
    int n2 = v.size() - n1;

    std::vector<int> v1(v.begin(), v.begin() + n1);
    std::vector<int> v2(v.begin() + n1, v.end());

    merge_sort(v1);
    merge_sort(v2);

    size_t id1 = 0, id2 = 0, i = 0;

    while(id1 < n1 && id2 < n2){
        if(v1[id1] <= v2[id2]){
            v[i] = v1[id1];
            ++id1;
            ++i;
        }
        else{
            v[i] = v2[id2];
            ++id2;
            ++i;
        }
    }

    while(id1 < n1){
        v[i] = v1[id1];
        ++id1;
        ++i;
        
    }

    while(id2 < n2){
        v[i] = v2[id2];
        ++id2;
        ++i;
        
    }

}

void print_perm(std::vector<int> curr){
    for(int el : curr){
        cout << el << " ";
    }
    cout << endl;
}

void permutations(std::unordered_set<int> used_up,std::vector<int> curr, unsigned int n){
    
    //base case
    if(curr.size() == n){
        print_perm(curr);
        return;
    }

    for(size_t i = 1; i <= n; ++i){
        if(!used_up.count(i)){
            used_up.insert(i);
            curr.push_back(i);
            permutations(used_up, curr, n);

            //backtrack
            used_up.erase(i);
            curr.pop_back();
        }
    }
}

class C{
    private:
        int i;
        friend C& operator+(const C& left, const C&right);
        friend ostream& operator<<(ostream& cout, const C& other);
        friend bool operator==(const C& left,const C& right);
    public:
        C(){};
        C(int _i): i(_i){};

        C& operator+=(const C& other){
            i += other.i;
            return *this; 
        }
        //or
        C& operator+=(const int& val){
            i+= val;
            return *this;
        }

        //pre-increment
        C& operator++(){
            i++;
            return *this;
        }
        //post-increment
        C operator++(int){
            C temp(i);
            i++;
            return temp;
        }
        //make it explicit
        C operator-(){
            return i *= -1;
        }

        //perform other operations in midterm pratcice


};

C& operator+(const C& left, const C&right){
    C res(0);
    res += left.i + right.i;
    return res;
}

ostream& operator<<(ostream& cout, const C& other){
    cout << other.i;
    return cout;
}

bool operator==(const C& left,const C& right){
    return (left.i == right.i);
}

struct Point2D {
    double x, y;
    Point2D(double _x, double _y) : x(_x), y(_y) {}
    void print() const {
    std::cout << '(' << x << "," << y << ')' << std::endl;
    }
    Point2D operator+=(const Point2D& other) {
    x += other.x; y += other.y;
    return *this;
    }
    Point2D operator*=(double d) {
    x *= d; y *= d;
    return *this;
    }
};
Point2D operator+(Point2D& p1, const Point2D& p2 ) { return p1 += p2; }

int main() {
    Point2D q1(1, 0), q2(0, 1);
    Point2D q3 = q1 + q2;
    const Point2D& r2 = q2;
    q2 = Point2D(0, 2);
    const Point2D& r3 = (q3 *= 2);
    q3 = Point2D(7, 7);
    q1.print(); q2.print(); q3.print(); r2.print(); r3.print();
    return 0;
}
//clang++ -std=c++14 discussion.cpp -o discussion && ./discussion
