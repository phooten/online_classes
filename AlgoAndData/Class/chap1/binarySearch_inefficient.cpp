/*
    Contributer:    Parker Hooten
    Date Started:   August 21, 2021
    Status:         Complete
    Purpose:        Write a binary search function. This is a first draft, but I will look at other
					programs to find a more efficient technique and hopefully post that.

*/

/*
    Initial thoughts:
		- I would have to cycle through the whole array if I wasn't given the length so I could find
		the end.
		- need to sort if not in the correct order

    Personal Critiques:
		- around line 50, when goal < arr[mid]: -> max = mid should be max = mid + 1. It would save an
    extra check every loop. I already checked arr[mid] don't need to include it in a bound to find the mid again.
    - Lines 60-62: if(mid == length - 2) could be avoided if the full length is used, not length-1. It
    is okay to do this, because ((length - 1) + length)/2 will always round down to below lenght, thus
    never getting to arr[length]
*/


#include <iostream>

/*
    Purpose:
		Assuming the arrary is ***sorted from lowest value[0] to high valux[x]***, this will
		find the number being looked for and return the position in the array, or return a -1
		for not found.
*/
int binSearch(int *pArray, int goal, int length){
	int current;			// current point inside given array
	int mid;				// mid point of current range
	int min = 0;
	int max = length - 1;
	bool found = false;		// once true, we found the number

	// intial bound check
	if(goal <= pArray[length - 1] && goal >= pArray[0]){
		while(found == false){
			mid = min + ((max - min)/2);		// I see an issue with this in odd numbers, but since '/' rounds down, i think it will be okay.

			// Found what was looked for
			if(goal == pArray[mid]){
				found = true;
				return mid;

			// if we didn't find what we were looking for
			} else if(goal < pArray[mid]){
				max = mid;
			} else {
				min = mid;
			}

			// getting in here exceeds bounds
			//	NEEDS TO BE AFTER THE IF ABOVE.


			// Case: Length = odd, mid never reached len(array) bc x/y = 0.5 = 0
			if(mid == length - 2){
				max = length;
			}
			if(pArray[mid] == pArray[0] || pArray[mid] == pArray[length - 1]){
				return -1;
			}
		}

	} else {
		std::cout << goal << " is out of array bounds.";
		return -1;
	}

	// should never get here... bad code?
	return 0;
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
