#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int factorial(int m) {
	int result = 1;
	for (int i=1; i <= m; i++)
		result *= i;
	return result;
}

int selection(int n, int m) {
	if (n < m)
		return 0;
	if (m == 0)
		return 1;
	return (factorial(n)/((factorial(n-m))*(factorial(m))));
}

vector<deque<char> > power_set(vector<char>& given) {
	int len, length, prev_len, cnt, size;
	vector<deque<char> > result;
	deque<char> temp;

	len = given.size();
	result.push_back(temp); /* empty set */

	for (int i = 1; i <= len; i++) {
		length = i;
		prev_len = length - 1;
		size = result.size();
		for (int pos = 0; pos < len; pos++) {
			cnt = selection((len-1)-pos, prev_len); /* Nc\m*/
//			cout<<"Processing "<<given[pos]<<" for length : "<<length<<" and choose :  "<<(len-1)-pos<<", "<<prev_len<<" is : " <<cnt<<"\n";
			for (int strt = (size-cnt); strt < size; strt++) {
				deque<char> temporary;
				temporary = result[strt];
			//	cout<<"Adding "<<given[pos]<<" to result matrix at index : "<<strt<<"\n";
				temporary.push_front(given[pos]);
				result.push_back(temporary);
			}
		}
	}
	return result;
}

vector<deque<char> > power_set_iterative(vector<char> &given) {
	vector<deque<char> > result;
	deque<char> temp;
	int len;

	len = given.size();
	result.push_back(temp);

	for (int i = 0; i < len; i++) {
		int res_len;
		res_len = result.size();
		for (int j = 0; j < res_len; j++) {
			deque<char> temporary;
			temporary = result[j];
			temporary.push_back(given[i]);
			result.push_back(temporary);
		}
		
	}
	return result;
}


int main() {
	vector<char> given;
	vector<deque<char> > result;

	given.push_back('A');
	given.push_back('B');
	given.push_back('C');
	given.push_back('D');
	given.push_back('E');

//	result = power_set(given);
	result = power_set_iterative(given);

	for (int i = 0; i < result.size(); i++) {
		deque<char> temporary;
		temporary = result[i];
		for (int j = 0; j < temporary.size(); j++)
			cout<<temporary[j]<<" ";
		cout<<"\n";
	}
	return 0;
}
