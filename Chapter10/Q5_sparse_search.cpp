#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find_closest(vector<string>& list, int mid, int strt, int end) {
	int left, right;

	left = mid-1;
	right = mid+1;
	while (left >= strt  && right <= end) {
		if (list[left].compare(""))
			return left;
		else if (list[right].compare(""))
			return right;
		left--;
		right++;
	}

	if (left < strt) {
		while (right <= end) {
			if (list[right].compare(""))
				return right;
			right++;
		}
	} else if (right > end) {
		while (left >= strt) {
			if (list[left].compare(""))
				return left;
			left--;
		}
	}
	return -1;
}

int sparse_search(vector<string>& list, string search) {
	int strt, last, mid;

	strt = 0;
	last = list.size() - 1;

	while (strt <= last) {
		mid = strt + (last - strt)/2;

		if (list[mid].compare("") == 0) {
			mid = find_closest(list, mid, strt, last);
		}
		if (mid == -1)
			return mid;
		if (search.compare(list[mid]) == 0)
			return mid;
		else if (search.compare(list[mid]) < 0){
			last = mid-1;
		} else {
			strt = mid+1;
		}
	}
	return -1;
}

int main() {
	vector<string> list;
	string val = "xyz";

	list.push_back("at");
	list.push_back("");
	list.push_back("");
	list.push_back("");
	list.push_back("ball");
	list.push_back("");
	list.push_back("");
	list.push_back("car");
	list.push_back("");
	list.push_back("");
	list.push_back("dad");
	list.push_back("");
	list.push_back("");

	cout<<"Index of "<<val<<" in list is : "<<sparse_search(list, val)<<"\n";

return 0;
}
