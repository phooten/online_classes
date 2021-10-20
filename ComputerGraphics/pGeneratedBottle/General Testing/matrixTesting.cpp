#include <iostream>
using namespace std;

int main(){
    float colorList[4][4] = {
		{ 0.91f, 0.90f, 0.92f, 1.00f },		// 1 - white
		{ 0.94f, 0.94f, 0.71f, 1.00f },		// 2 - tan
		{ 0.85f, 0.76f, 0.82f, 1.00f },		// 3 - pink
		{ 0.46f, 0.85f, 0.80f, 1.00f }		// 4 - black
	};

    // float bottleColor[4] = colorList[2];

    cout << colorList[1][] << endl;

    return 0;
}