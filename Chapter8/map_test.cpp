#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

int main() {
	unordered_map<pair<int, int>, vector<char> > custom_map;
	pair<int, int> temp_pair;
	vector<char> temp_list;

	temp_pair.first = 0;
	temp_pair.second = 0;
	temp_list.push_back('1');
	temp_list.push_back('0');
	temp_list.push_back('1');
	custom_map[temp_pair] = temp_list;

	temp_list.clear();

	temp_pair.first = 2;
	temp_pair.second = 2;
	temp_list.push_back('0');
	temp_list.push_back('0');
	temp_list.push_back('0');
	custom_map[temp_pair] = temp_list;
	
	temp_list.clear();

	if (custom_map.count(temp_pair))
		cout<<"FOUND\n";
	else
		cout<<"NOT FOUND\n";
return 0;
}
