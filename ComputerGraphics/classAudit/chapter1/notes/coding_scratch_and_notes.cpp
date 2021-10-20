// Purpose:
//    used as a throw away program for debugging concepts discussed in the chapters

/*
  notes:
      - 1 byte:
          - char
          - unsigned char
      - 8 bytes:
          - pointers (pointer to a pointer, char pointer, int pointer, etc)
            * on a 64 bit machine, 8 bytes. on a 32 bit machine, 4 bytes
      - sizeof() returns number of bytes
      - new -> allocates memory for an object or array of abjects of type-name
               from the free store and returns a suitably typed, nonzero pointer
               to the object
*/

#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
  const int ROWS = 8;
  const int COLS = 8;
  unsigned char ** pixmap;
  unsigned char *data;

  cout << "sizeof(pixmap): " << sizeof(pixmap) << "\n"; // this prints 8

  cout << "pixmap: " << pixmap << "\n";   // prints 0

  pixmap = new unsigned char *[ROWS];     // sets pixmap equal to an allocated space for an array of unsigned char pointer of ROWS size
  data = new unsigned char [ROWS * COLS];  // sets data equal to an allocated space for an unsigned char array of ROWS * COLS size

  cout << "pixmap: " << pixmap << "\n";   // prints address

  pixmap[0] = data;                       // sets the first pointer equal to the data allocations
  for(int y = 1; y < ROWS; y++){          // sets each array element of pixmap equal to a spot in data based on pixmap[0]
    pixmap[y] = pixmap[y - 1] + COLS;
  }

  // Testing my understanding
  data[10] = 'A';
  cout << "data[10]: " << data[10] << "\n";
  pixmap[1][2] = 'C';
  cout << "data[10]: " << data[10] << "\n";
  // cout << "pixmap[1][3]: " << pixmap[1][3] << "\n";



  return 0;
}
