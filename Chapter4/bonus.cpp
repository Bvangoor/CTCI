#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

vector<pair<int, int> > contigous_sum_array(vector<int> given, int sum) {
	vector<pair<int, int> > result;
	unordered_map<int, vector<int>> Map;
	vector<int> temp;
	int target_sum, running_sum = 0;
	
	target_sum = sum;
	temp.push_back(running_sum);
	Map[running_sum] = temp;
	temp.clear();
	for (int i = 1; i < given.size(); i++) {
		running_sum += given[i];
		if (Map.count(running_sum - target_sum)) {
			vector<int> temp;
			pair<int, int> temp_pair;
			temp = Map[(running_sum - target_sum)];
			for (int j=0; j < temp.size(); j++) {
				temp_pair.first = temp[j] + 1;
				temp_pair.second = i;
				result.push_back(temp_pair);
			}
		}
		if (Map.count(running_sum))
			Map[running_sum].push_back(i);
		else {
			vector<int> temp;
			temp.push_back(i);
			Map[running_sum] = temp;
		}
	}
	return result;
}

int main() {
	vector<int> given;
	vector<pair<int, int> > result;

	given.push_back(0); /*place holder*/

	given.push_back(1);
	given.push_back(2);
	given.push_back(3);
	given.push_back(-6);
	given.push_back(4);
	given.push_back(-4);

	result = contigous_sum_array(given, 0);
	for (int i=0; i < result.size(); i++)
		cout<<"strt : "<<result[i].first<<" end : "<<result[i].second<<"\n";
return 0;
}
