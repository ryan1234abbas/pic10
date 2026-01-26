#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <set>


//compile then execute
//clang++ -std=c++14 discussion.cpp -o discussion && ./discussion

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

int main(){

    std::unordered_set<int> used_up;
    std::vector<int> curr;
    unsigned int n = 3;
    
    permutations(used_up, curr, n);


    return 0;
}
