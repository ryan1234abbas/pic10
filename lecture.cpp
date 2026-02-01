#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;


const string& first(const string& p0, const string& p1){
    if (p0 > p1){
        return p1;
    }
    return p0;
}

unsigned int factorial(unsigned int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

void merge_sort(vector<int> &v){
    const int size = v.size();
    if(size == 0 || size ==1){
        return;
    }

    int first_size = size / 2;
    int second_size = size - first_size;

    vector<int> v1(v.begin(), v.begin() + first_size);
    vector<int> v2(v.begin() + first_size, v.end());

    merge_sort(v1);
    merge_sort(v2);
    
    int id1 = 0, id2 = 0, i = 0;

    while(id1 < v1.size() && id2 < v2.size()){
        if(v1[id1] <= v2[id2]){
            v[i] = v1[id1];
            ++i;
            ++id1;
        }
        else if(v1[id1] >= v2[id2]){
            v[i] = v2[id2];
            ++i;
            ++id2;
        }
    }
    while(id1 < v1.size()){
        v[i] = v1[id1];
        ++i;
        ++id1;
    }
    while(id2 < v2.size()){
        v[i] = v2[id2];
        ++i;
        ++id2;
    }

}

void permutation(unsigned int n,vector<int>& current, unordered_set<int>& used){
    if(current.size() == n){
        for(int el: current){
            cout << el << " ";
        }
        cout << endl;
    }
    
    for(int i = 1; i <= n; ++i){
        if(used.count(i)){
            continue;
        }
        current.push_back(i);
        used.insert(i);

        permutation(n, current, used);

        current.pop_back();
        used.erase(i);    
    }
}

void bubble_sort(std::vector<int> &v){
    for(size_t i = 0; i < v.size(); ++i){
        for(size_t j = 0; j+1 <= v.size()-1; ++j){
            if(v[j] > v[j+1]){
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
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

//operator overloading

class Sets{
    private:
        set<int> s;
    public:
        Sets(): s() {};
        Sets(std::set<int>&s1): s(s1){};

        void print() const {
            for (int el: s){
                cout << el << " ";
            }
        }

        Sets& operator+=(const Sets& other){
            for(int el: other.s){
                s.insert(el);
            }
            return *this;
        }

        Sets& operator-=(const Sets& other){
            for(int el: other.s){
                if((*this).s.count(el) && other.s.count(el)){
                    s.erase(el);
                }
            }
            return *this;
        }

};

class Vector{

    private:
        vector<int> v1;

    public:

        Vector(): v1() {};
        Vector(const vector<int> &v): v1(v){};

        std::vector<int> operator+(const Vector &v2) const{
            size_t N;
            vector<int> v3;

            if(v1.size() <= v2.v1.size()) N = v1.size();
            else N = v2.v1.size();

            for(size_t i = 0; i < N; ++i){  
                v3.push_back(v1[i] + v2.v1[i]);
            }
            return v3;
        }

        void operator+=(const Vector &v2){
            size_t N;

            if(v1.size() <= v2.v1.size()) N = v1.size();
            else N = v2.v1.size();

            for(size_t i = 0; i < N; ++i){  
                v1[i] += v2.v1[i];
            }
        }

        bool operator>(const Vector& other) const{
            int sum1 = 0, sum2 = 0;;
            for(int el: v1){
                sum1 += el;
            }
            for(int el: other.v1){
                sum2 += el;
            }

            return sum1 > sum2;

        }

        void print(){
            for(int el: v1){
                cout << el << " ";
            }
        }

};

class Point2D{
    private:
        int x;
        int y;
        friend ostream& operator<<(ostream& out, const Point2D& other);
        friend bool operator==(Point2D& other1, Point2D& other2);

    public:
        Point2D(){};
        Point2D(int _x, int _y): x(_x), y(_y){};
        
        //declarations
        const int& operator[](size_t index) const;
        int& operator[](size_t index);

        Point2D& operator+=(const Point2D& other){
            x += other.x;
            y += other.y;
            return *this;
        }

        void print(){
            cout << x << " ";
            cout << y;
        }
};

ostream& operator<<(ostream& out, const Point2D& other){
    out << other.x << " ";
    out << other.y << endl;
    return out;
}

bool operator==(Point2D& other1, Point2D& other2){
    return (other1.x == other2.x) && (other1.y == other2.y);
}

//why cant we use const on vars or outside ?
bool operator!=(Point2D& other1, Point2D& other2){
    return !(other1 == other2);
}

const int& Point2D::operator[](size_t index) const{
    if(index == 0) return x;
    else return y;
}

int& Point2D::operator[](size_t index){
    if(index == 0) return x;
    else return y;
}

class OneVal{
    private:
        int i;
        friend ostream& operator<<(ostream& cout, const OneVal v1);

    public:
        OneVal(int _i): i(_i){};
        OneVal(){};

        OneVal& operator++(){
            ++i;
            return *this;
        }

        //prefix
        OneVal& operator--(){
            --i;
            return *this;
        }

        //postfix
        OneVal operator--(int){
            OneVal o = *this;
            --i;
            return o;
        }

        OneVal operator-(){
            i*=-1;
            return *this;
        }


};

ostream& operator<<(ostream& cout, const OneVal v1){
    cout << v1.i;
    return cout;
}

class TwoVals{
    private:
        int i;
        int j;
        friend ostream& operator<<(ostream& cout, const TwoVals& v);
    public:
        TwoVals(){};
        TwoVals(int _i, int _j): i(_i), j(_j){};

        bool operator==(TwoVals& other) const{
            return (i == other.i) && (j == other.j);
        }

        TwoVals& operator+=(TwoVals& other){
            i+= other.i;
            j += other.j;
            return *this;
        }

        TwoVals& operator--(){
            i -= 1;
            j -= 1;
            return *this;
        }

        TwoVals& operator++(){
            i += 1;
            j += 1;
            return *this;
        }
};

ostream& operator<<(ostream& cout, const TwoVals& v){
    cout << v.i;
    return cout;
}

int main(){



    return 0;
}

//how can we use operator !+/== without specifying Point2D:: ?

//clang++ -std=c++14 lecture.cpp -o lecture && ./lecture
