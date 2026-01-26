#include "square.hpp"
#include <iostream>
#include <unordered_set>

Square::Square(size_t n):
    size(n), data(n*n, 0), magic_total(n*(n*n + 1) / 2)
{}

unsigned int& Square::set(size_t i, size_t j){
    return data[i * size + j];
}

const unsigned int& Square::get(size_t i, size_t j) const{
    return data[i * size + j];
}

void Square::print() const{
    for(size_t i = 0; i < size; ++i){
        for(size_t j = 0; j < size; ++j){
            if(data[i*size+j] == 0){
                std::cout << "* ";
            }
            else{
                std::cout << data[i*size+j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Square::is_magic() const{
    std::unordered_set<unsigned int> set;
    //check uniquity of each element and if the square is filled
    for(size_t i = 0; i < size*size; ++i){
        if(data[i] == 0) return false;  
        set.insert(data[i]);
    }

    if (set.size() != size*size) return false;

    //row sums
    for(size_t i = 0; i < size; ++i){
        unsigned int sum = 0;
        for(size_t j = 0; j < size; ++j){
            sum += data[i*size + j];
            if(sum > magic_total) return false;
        }
        if(sum != magic_total) return false;
    }

    // column sums
    for(size_t j = 0; j < size; ++j){
        unsigned int sum = 0;
        for(size_t i = 0; i < size; ++i){
            sum += data[i*size + j];
            if(sum > magic_total) return false;
        }
        if(sum != magic_total) return false;
    }

    // left to right diagnol
    unsigned int diag_sum = 0;
    for(size_t i = 0; i < size; ++i){
        diag_sum += data[i*size + i];
        if(diag_sum > magic_total){
            return false;
        }
    }
    
    if(diag_sum != magic_total) return false;

    // right to left diagnol
    diag_sum = 0;
    for(size_t i = 0; i < size; ++i){
        diag_sum += data[i*size + (size - 1 - i)];
        if(diag_sum > magic_total){
            return false;
        }
    }

    if(diag_sum != magic_total) return false;

    return true;
}

bool Square::row_has_magic_total(size_t row) const{
    unsigned int sum = 0;
    //check sum only for complete rows
    for(size_t j = 0; j < size; ++j){
        if(data[row * size + j] == 0){
            return true;
        }
    }

    for(size_t j = 0; j < size; ++j){
        sum += data[row * size + j];
    }
    return sum == magic_total;
}

void Square::see_magic_potential(){
    std::unordered_set<unsigned int> used_up;
    
    for(size_t i = 0; i < size*size; ++i){
        if(data[i] != 0){
            used_up.insert(data[i]);
        }
    }
    
    help_see_magic_potential(used_up, 0);
}

void Square::help_see_magic_potential(std::unordered_set<unsigned int>& used_up, size_t slots_considered) {
    //base case
    if (slots_considered == size * size) {
        if (is_magic()) print();
        return;
    }

    //skip slot if already filled
    if (data[slots_considered] != 0) {
        help_see_magic_potential(used_up, slots_considered + 1);
        return;
    }

    size_t row = slots_considered / size;
    size_t col = slots_considered % size;

    for (unsigned int num = 1; num <= size*size; ++num) {
        if (used_up.count(num)) continue;

        data[slots_considered] = num;
        used_up.insert(num);

        if (col == size - 1 && !row_has_magic_total(row)) {
            data[slots_considered] = 0;
            used_up.erase(num);
            continue;
        }

        help_see_magic_potential(used_up, slots_considered + 1);

        data[slots_considered] = 0;
        used_up.erase(num);
    }
}

/*
in case this is helpful, below are the comments I wrote when
coding the function help_see_magic_potential.
feel free to ignore them if you don't find them useful.
*/


// if a row has been filled in, check...

    // if this is the last row, check if the square is magic
    // if it is magic, print it, and return

    // if the row does not have the desired sum, return

// otherwise...
// if the slot is empty, fill it with the next unused number
// recursively try to construct more magic squares with this number filled in

// otherwise, move one slot forward by recursively calling the function