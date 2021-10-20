#include <iostream>
#include "NumberCount.h"

// default constructor
NumberCount::NumberCount(){
    std::cout << "no range selected";
}


/*
    Purpose:
        Initialize and set up the array that a range of numbers are stored in
*/
NumberCount::NumberCount(int num1, int num2){
    
    // decides which argument is bigger
    if(num1>=num2){
        maxNum = num1;
        minNum = num2;
    }else{
        maxNum = num2;
        minNum = num1;
    }

    // allocates array memory
    aLen = maxNum - minNum + 1;
    aIr = new int [aLen];       

    // initiates array values to 0
    for(int i = 0; i < aLen; i++)
        aIr[i] = 0;
}   


/*
    Purpose:
        Adds a count to the associated number in the array. Each number has a running
        tally
*/
void NumberCount::addElement(int number){
    // adds tally if valid
    if(number >= minNum && number <= maxNum){
        aIr[aLen - 1 - (maxNum - number)]++; 
    } else {
        std::cout << number << " Out of range;\n"; 
    }

    return;
};


/*
    Purpose:
        Removes a count to the associated number in the array. Each number has a running
        tally
*/
bool NumberCount::removeElement(int number){
    // removes tally if there is any, and if valid
    if(number >= minNum && number <= maxNum){
        if(aIr[aLen - 1 - (maxNum - number)] == 0)
            std::cout << number << " not present;\n";    
        else 
            aIr[aLen - 1 - (maxNum - number)]--;
    } else {
        std::cout << number << " Out of range;\n"; 

    }

    return true;
};


/*
    Purpose:
        Prints out each value in the array and it's tally with '*'
*/
void NumberCount::display(){
    std::cout << "\n";
    
    // Cycles through array and prints each number's tally
    for(int i = 0; i < aLen; i++){
        std::cout << i + minNum << ": ";
        for(int j = 0; j < aIr[i]; j++){
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return;
};

