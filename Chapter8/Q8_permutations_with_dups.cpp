#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

vector<deque<char> > permutations_with_dups(string& given) {
	vector<deque<char> > result;
	deque<char> temp;
	unordered_map<char, int> Map;
	int len;

	len = given.length();
//	cout<<"string : "<<given<<" len : "<<len<<"\n";
	if (len == 1) {
		temp.push_front(given[0]);
		result.push_back(temp);
		return result;
	}

	for (int pos = 0; pos < len; pos++) {
		if (Map.count(given[pos])) {
			Map[given[pos]] += 1;
			//Do Nothing
		} else {
			string remaining = "";
			remaining += (pos == 0) ? "" : given.substr(0, pos);
			remaining += (pos == (len-1)) ? "" : given.substr(pos+1, (len-1) - pos);
			vector<deque<char> > recur_res;
			recur_res = permutations_with_dups(remaining);
			for (int k = 0; k < recur_res.size(); k++) {
				deque<char> rec_temp;
				rec_temp = recur_res[k];
				rec_temp.push_front(given[pos]);
				result.push_back(rec_temp);
			}
			Map[given[pos]] = 1;
		}
	}
	return result;
}

void print_permutations(vector<deque<char> >& result) {
	int len;
	deque<char> temp;

	len = result.size();
	for (int i=0 ;i < len; i++) {
		temp = result[i];
		for (int j=0; j < temp.size(); j++){
			cout<<temp[j]<<" ";
		}
		cout<<"\n";
	}
}

int main() {
	string given = "AABB";
	vector<deque<char> > result;

	result = permutations_with_dups(given);
	print_permutations(result);
return 0;
}
