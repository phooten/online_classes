/*
    Contributer:    Parker Hooten
    Date Started:   August 23, 2021
    Status:         Complete
    Purpose:        Write a binary search function that will perform more efficiently
                    than "binarySearch_inefficient.cpp" which was my first blind attempt.
                    This was after studying other implementations and critiquing my code.
*/

#include <iostream>

/*
    Purpose:
		Assuming the arrary is ***sorted from lowest value[0] to high valux[x]***, this will
		find the number being looked for and return the position in the array, or return a -1
		for not found.
*/
int binSearch(int *pArray, int goal, int length){
	int current;			   // current point inside given array
	int mid;				     // mid point of current range
	int min = 0;         // min of current range
	int max = length;    // max of current range
	bool found = false;	 // once true, we found the number

	// intial bound check
	if(goal <= pArray[length - 1] && goal >= pArray[0]){
		//while(found == false){
		while(min < max){
      mid = min + ((max - min)/2); // will never acceed length, so it will stay in arr bounds

			if(goal == pArray[mid]){
				found = true;
				return mid;
			} else if(goal < pArray[mid]){
				max = mid - 1;
			} else {
				min = mid;
			}

			if(pArray[mid] == pArray[0] || pArray[mid] == pArray[length - 1]){
				return -1;
			}
		}

	}

	std::cout << goal << " is out of array bounds.";
	return -1;
}

int main(){
	int len = 16;
	int target = 15;
	int tArray[len] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int pos = binSearch(tArray, target, len);

	if(pos != -1)
		std::cout << "\nFound: " << tArray[pos] << " pos: " << pos << "\n";
	else
		std::cout << "\nNot Found: " << target << "\n";

	return 0;
}
