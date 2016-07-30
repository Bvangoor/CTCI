#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& array, vector<int>& helper, int low, int mid, int high) {
	int helper_left; /* start of left array */
	int helper_right; /* start of right array */
	int curr; /* pointer in original array */
	int rem; /* If left array is not copied to orig array*/

	for (int i = low; i <= high; i++)
		helper[i] = array[i];

	helper_left = low;
	helper_right = mid+1;
	curr = low;

	while (helper_left <= mid && helper_right <= high) {
		if (helper[helper_left] < helper[helper_right]) {
			array[curr] = helper[helper_left];
			helper_left++;
		} else {
			array[curr] = helper[helper_right];
			helper_right++;
		}
		curr++;
	}

	rem = mid - helper_left;
	for (int i = 0; i <= rem; i++)
		array[curr + i] = helper[helper_left + i];
}

void merge_sort(vector<int>& array, vector<int>& helper, int low, int high) {
	if (low < high) {
		int mid;

		mid = low + (high - low)/2;
		merge_sort(array, helper, low, mid);
		merge_sort(array, helper, mid+1, high);
		merge(array, helper, low, mid, high);
	}
}

void print_array(vector<int>& array) {
        int len;

        len = array.size();
        for (int i=0; i < len; i++)
                cout<<array[i]<<" " ;
        cout<<"\n";
}

int main() {
	vector<int> array;
	
        array.push_back(4);
        array.push_back(3);
        array.push_back(2);
        array.push_back(1);

	vector<int> helper(array.size(), -1);

        print_array(array);
        merge_sort(array, helper, 0, array.size()-1);
        print_array(array);

return 0;
}
