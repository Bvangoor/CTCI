#include <iostream>
#include <vector>

using namespace std;

int B_S_T(vector<int>& list, int strt, int end, int val) {
	while (strt <= end) {
		int mid;

		mid = strt + (end - strt)/2;
		if (val == list[mid])
			return mid;
		else if (val < list[mid]) {
			end = mid-1;
		} else
			strt = mid+1;	
	}
	return -1;
}

int search_no_size(vector<int>& list, int val) {
	int strt, end;
	int incr = 1; /* start with 1*/

	strt = 0;
	end = strt + incr;

	while (strt <= end) {
		if (list[end] != -1) {
			if ((val >= list[strt]) && (val <= list[end])) {
				return B_S_T(list, strt, end, val);
			} else if (val < list[strt])
				return -1;
			else {
				strt = end;
				incr = 2*incr;
				end = strt + incr;
			}
		} else {
			if (incr == 1) {
				if (list[strt] == val)
					return strt;
				else
					return -1;
			}
			incr = 1;
			end = strt + incr;
		}
	}
	return -1;
}

int main() {
	vector<int> list (100, -1);
	int val = 4;

	list[0] = 1;
	list[1] = 2;
	list[2] = 3;
	list[3] = 4;
	list[4] = 5;
	list[5] = 6;
	list[6] = 7;
	
	cout<<"Index of val : "<<val<<" is : "<<search_no_size(list, val)<<"\n";

return 0;
}
