#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int magic_index(vector<int>& given) {
	int low, high, middle;

	low = 0;
	high = given.size() - 1;

	while (low <= high) {
		middle = low + (high - low)/2;
		if (middle == given[middle])
			return middle;
		else if (middle < given[middle]) {
			high = middle-1;
		} else {
			low = middle+1;
		}
	}
	return -1;
} 

int helper_func(int low, int high, vector<int>& given) {
	int middle, midVal, left, right, val1, val2;
	

	if (low <= high) {
		middle = low + (high - low)/2;
		midVal = given[middle];
		if (middle == midVal)
			return middle;
		else {
			left = min(middle-1, midVal);
			val1 = helper_func(low, left, given);
			if (val1 >= 0)
				return val1;

			right = max(middle+1, midVal);
			val2 = helper_func(right, high, given);
			if (val2 >= 0)
				return val2;
		}
	}
	return -1;
}

int magic_index_duplicate(vector<int>& given) {
	int low, high;

	low = 0;
	high = given.size() - 1;
	return helper_func(low, high, given);
}


int main() {
	vector<int> given;

	given.push_back(-10);
	given.push_back(-5);
	given.push_back(2); /*Ans*/
	given.push_back(2);
	given.push_back(2);
	given.push_back(3);
	given.push_back(4);
	given.push_back(7);
	given.push_back(9);
	given.push_back(12);
	given.push_back(13);
	
	cout<<"Magic index of the given array is : "<<magic_index_duplicate(given)<<"\n";
return 0;
}
