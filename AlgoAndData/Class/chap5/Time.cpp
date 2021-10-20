#include<iostream>
using namespace std;

class Foo {
  public:
    Foo( ) { cout << 1; }
    Foo( Foo & other ) { cout << 7; }
};

class Bar {
  Foo one;
  public:
    Bar( ) { cout << 2; }
    Bar( Bar & other ) : one(other.one) { cout << 3; }
    ~Bar( ) { cout << 4; }

    void fred(Foo wilma) {
      cout << 5;
    }
    void thelma( Foo & louise ) {
      cout << 6;
    }
};

                // my guess
int main( ) {       
  Bar A;          // 1 (Bar->Foo()) 2
  cout << " ";
  Bar B(A);       // 173
  cout << " ";
  Foo C;          // 1
  cout << " ";    
  A.fred(C);      // 5
  cout << " ";
  B.thelma(C);    // 6
  cout << " ";
}

//12 173 1 5 6 44
//12 73 1 75 6 44