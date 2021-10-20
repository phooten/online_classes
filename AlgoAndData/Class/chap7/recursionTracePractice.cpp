/*
	Date: 		August 31, 2021
	Purpose:
		1. To show a simple recursion program that will be used to trace a recursion
    tree.
    2. Create a recurtion program to output 5 brackets: ((((()))))
*/

#include <iostream>
using namespace std;


/*
  f
    purpose:
      to fufill #1 of the listed requirements above
    arguments
      n -   the maximum number of the recursion tree
*/
void f(int n){
  cout << n;
  if(n > 1)
    f(n-1);
  if(n > 2)
    f(n-2);
  return;
}

/*
  b
    purpose:
      to fufill #2 of the listed requirements above
    arguments
      n -   the amount of times a pair of brackets will be printed
*/
void b(int n){
  if(n > 0){
    cout << "(";
    b(n - 1);
    cout << ")";
  }

}

int main(){
  int value = 5;

  b(value);

  return 0;
}
