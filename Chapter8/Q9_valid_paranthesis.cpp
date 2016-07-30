#include <iostream>
#include <string>
#include <vector>
using namespace std;

void valid_paranthesis(vector<string>& result, string temp, int leftrem, int rightrem, int index) {
	if (leftrem == 0 && rightrem == 0) {
		result.push_back(temp);
	} else if ( (leftrem < 0) || (rightrem < leftrem) ) {
		return ;
	} else {
		temp[index] = '(';
		valid_paranthesis(result, temp + "(", leftrem-1, rightrem, index+1);
		temp[index] = ')';
		valid_paranthesis(result, temp + ")", leftrem, rightrem-1, index+1);
	}
}

void print_list(vector<string>& result) {
	for (int i=0; i < result.size(); i++)
		cout<<result[i]<<"\n";
}

int main() {
	int num = 4;
	string temp;
	vector<string> result;

	for (int i=0; i < (num+num); i++)
		temp[i] = 'A';

	valid_paranthesis(result, temp, num, num, 0);

	print_list(result);

	return 0;
}
