/*
    Contributer:    Parker Hooten
    Date Started:   August 19, 2021
    Status:         Incomplete 
    Purpose:        Print out all numbers less then 100 that are prime numbers
    
*/

/*
    Initial thoughts:
        - create 0->100 array and see if its prime
        - for-loop to 100, see if its prime
        - Use a math library to find factors and count them

    Tips:
        Prime number: Only divisible by 1 and itself
        0 and 1 are not prime numbers

    Personal Critiques:
        - seems very slow. Instead of calculating every number between 1 and x, it could be done from
          1 to x/2 at LEAST.  It got intricate on certain cases like perfect roots and odd numbers.  
        - Looking back, if you find a number other than 1 that divides into the number evenly
          you can just stop. i.e: 80, you'd only have to check if 2 is, and thats it. its not prime based 
          on the 1 number. 

*/
#include<iostream>
using namespace std;

int main(){
    int currNum;            // Current number
    int factor = 0;
    int factCount = 0;         // Factor Count
    int totalPrimes = 0;
    const int upBound = 100;    // Upper bound
    const int loBound = 2;     // Lower bound 

    cout << "Prime Numbers: " << "\n";
    for(currNum = loBound; factor <= upBound; currNum++){   //checks fro prime 

        factCount = 0;                                  // resets ongoing factor pairs
        for(factor = 1; factor <= currNum; factor++){   
            if(currNum % factor == 0){                  // any number dividing evenly is a factor
                factCount++;
            }
        }
        
        // Prime if factors are 1, num and num, 1
        if(factCount == 2){
            cout << currNum << "\n";
            totalPrimes++;
        }
    }

    cout << "Total Prime Numbers: " << totalPrimes << "\n";

    return 0;
}

