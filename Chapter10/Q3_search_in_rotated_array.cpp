#include <iostream>
#include <vector>

using namespace std;

void print_list(vector<int>& array) {
        int len;

        len = array.size();
        for (int i=0; i < len; i++)
                cout<<array[i]<<" " ;
        cout<<"\n";
}

bool check(vector<int>& list, int val, int strt, int end) {
	if (list[strt] <= list[end]) { /* strict increasing case */
		if ((val >= list[strt]) && (val <= list[end]) )
			return true;
		else
			return false;
	} else {
		if ((val >= list[strt]) || (val <= list[end]) )
                        return true;
                else
                        return false;
	}
}

int search_in_rotated_array(vector<int>& list, int val, int strt, int end) {
	while (strt <= end) {
		int mid;

		mid = strt + (end - strt)/2;
		if (list[mid] == val)
			return mid;
		else if (check(list, val, strt, mid-1)) { /* Check left */
			end = mid - 1;
		} else {  /* Go to right */
			strt = mid + 1;
		}
	}
	return -1;
}

int main() {
	vector<int> list;
	int val = 5;

	list.push_back(7);
	list.push_back(10);
	list.push_back(14);
	list.push_back(15);
	list.push_back(16);
	list.push_back(19);
	list.push_back(20);
	list.push_back(25);
	list.push_back(1);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	print_list(list);

	cout<<"Index of val : "<<val<<" is : "<<search_in_rotated_array(list, val, 0, list.size() - 1)<<"\n";

return 0;
}
