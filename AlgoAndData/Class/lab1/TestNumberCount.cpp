/*
    Name:   Parker Hooten
    Date:   August 20, 2021    
    Problem Statement:
        1. Consider a situation, such as a lottery, where over time certain numbers appear.
        Wayne wants to know how often each number appears. In C++, create a class
        NumberCount to count the occurrences of numbers.
        The class should use an array for storage. The methods that the class should have
        are:
            • Unique constructor takes two arguments: the minimum and maximum number that can occur.
            • void addElement(int number): increment the count of number
            • bool removeElement(int number): decrement the count of number
            • void display(): draw the results as a histogram
        
        2. Also create a main function in TestNumberCount.cpp that properly exercises your
        class

    Compile with:
        g++ -Wall -std=c++11 NumberCount.cpp TestNumberCount.cpp

*/

#include "NumberCount.h"

int main(){
    NumberCount N(11, 16);
    N.addElement(12); 
    N.addElement(12); 
    N.addElement(12); 
    N.addElement(14);
    N.addElement(17); 
    N.addElement(13); 
    N.removeElement(11); 
    N.removeElement(13);

    N.display();
    
    return 0;
}