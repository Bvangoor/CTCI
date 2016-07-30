#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& array) {
	int len, temp;
	bool swapped;

	len = array.size();
	while (true) {
		swapped = false;
		for (int j = 0; j < len-1; j++) {
			if (array[j] > array[j+1]) {
				/* swap*/
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
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

	print_array(array);
	bubble_sort(array);
	print_array(array);

	return 0;
}
