/*Determine If String has all unique Characters, *What if no extra Data Structures*/

#include <iostream>
#include <string>
#include <unordered_map> /*No extra space should be used*/

using namespace std;

/*Approach 1 (Not useful)*/
/*
int main() {
	string given = "";
	unordered_map<char, int> map;
	int i, len;
	
	len = given.length();
	for ( i = 0; i < len; i++ ) {
		if (map.count(given[i])) {
			cout<<"string is not unique\n";
			return 0;
		}
		map[given[i]] = 1;
	}
	cout<<"String is unique\n";
return 0;
}
*/
/*Approach 2, why not use ASCII values range (0-127) : Use a 128 sized array to keep track the count*/
int main() {
	int val, map[128], i, len;
	string given = "1234:;abcdfeghjlmnop";

	memset(map, 0, sizeof(map));
	len = given.length();
	for (i = 0; i < len; i++) {
		val = given[i] - '\0';
		if (map[val] > 0) {
			cout<<"string is not unique at index : "<<i<<"\n";
                        return 0;
		}
		map[val] += 1;
	}
	cout<<"String is unique\n";
return 0;
}
