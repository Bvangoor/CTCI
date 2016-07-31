#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void print_list(vector<string>& list) {
	int len;

	len = list.size();
	for (int i=0; i < len; i++)
		cout<< list[i]<<" ";

	cout<<"\n";
}

bool check_anagram(string A, string B) {
	unordered_map<char, int> map;

	if (A.length() == B.length()) {
		for (int i=0; i < A.length(); i++) {
			if (map.count(A[i]))
				map[(A[i])] += 1;
			else	
				map[(A[i])] = 1;
		}
		/* Now check the string B */
		for (int i = 0; i < B.length(); i++) {
			if (map.count(B[i]) && map[(B[i])])
				map[(B[i])] -= 1;
			else
				return false;
		}
	} else
		return false;

	return true;
}

int partition(vector<string>& list, int strt, int end) {
	int wall;
	int pivot;
	string pivot_val;
	string temp;

	wall = strt - 1;
	pivot = end;
	pivot_val = list[pivot];
//	cout<<"pivot_val : "<<pivot_val<<"\n";
	for (int i=strt; i < end; i++) {
		if (check_anagram(list[i], pivot_val)) {
			wall++;
//			cout<<"Swapping "<<list[wall]<<" and "<<list[i]<<"\n";
			temp = list[wall];
			list[wall] = list[i];
			list[i] = temp;
		}
	}
	wall++;
//	cout<<"Finally swapping "<<list[wall]<<" with pivot : "<<list[pivot]<<"\n";
	temp = list[wall];
	list[wall] = pivot_val;
	list[pivot] = temp;
	return wall;	
}


void group_anagrams(vector<string>& list, int strt, int end) {
	if (strt < end) {
		int pivot;
			
		pivot = partition(list, strt, end);
		group_anagrams(list, pivot+1, end);
	}
}

int main() {
	vector<string> list;

	list.push_back("bac");
	list.push_back("efd");
	list.push_back("ghi");
	list.push_back("fde");
	list.push_back("abc");
	list.push_back("hgi");

	print_list(list);
	group_anagrams(list, 0, list.size() - 1);
	print_list(list);

return 0;
}

