#include <iostream>
#include <vector>

using namespace std;

void print_array(vector<int>& array) {
        int len;

        len = array.size();
        for (int i=0; i < len; i++)
                cout<<array[i]<<" " ;
        cout<<"\n";
}

int partition(vector<int>& array, int low, int high) {
	int wall;  /* plae holder for swaping */
	int temp;  /* for swapping */
	int pivot;

	pivot = array[high];

	wall = low - 1;
	for (int i = low; i <= high; i++) {
		if (array[i] < pivot) {
			wall++;
			temp = array[wall];
			array[wall] = array[i];
			array[i] = temp;
		}
	}
	temp = array[wall+1];
	array[wall+1] = array[high];
	array[high] = temp;
	return (wall+1);
}

void quick_sort(vector<int>& array, int low, int high) {
	int pivot;

	if (low < high) {
		pivot = partition(array, low, high);
		quick_sort(array, low, pivot-1);
		quick_sort(array, pivot+1, high);
	}
}

int main() {
	vector<int> array;

        array.push_back(4);
        array.push_back(3);
        array.push_back(2);
        array.push_back(1);
	
	print_array(array);
	quick_sort(array, 0, array.size()-1);
	print_array(array);
		
return 0;
}
