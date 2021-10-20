#ifndef NUMBERCOUNT_H
#define NUMBERCOUNT_H

class NumberCount{
    private:
        int maxNum;
        int minNum;
        int aLen;   // array length
        int *aIr;   // array in (correct) range


    public:
        NumberCount();      // Default Constructor
        NumberCount(int num1, int num2);
        void addElement(int number);
        bool removeElement(int number);
        void display();     // Displays contents of aIr[]
};


#endif